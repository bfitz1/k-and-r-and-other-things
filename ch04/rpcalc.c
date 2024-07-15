#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define PEEK '1'
#define DUP '2'
#define SWAP '3'
#define CLEAR '4'
#define SHOW '5'
#define SIN '6'
#define EXP '7'
#define POW '8'
#define VARS '9'

int getop(char []);
int getvarindex();
void push(double);
double pop(void);
double peek(void);
void duplicate(void);
void swap(void);
void clear(void);
void show(void);

// Alright, getting kinda tired of this. Might come back to it in a
// structured way, though.
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    // Because I'm supporting a delete operation, I'd rather have
    // a way of identifying set variables
    int vi = 0;
    int vars_set[26] = {0};
    double vars[26] = {0};

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case PEEK:
            printf("\ttop: %.8g\n", peek());
            break;
        case DUP:
            duplicate();
            break;
        case SWAP:
            swap();
            break;
        case CLEAR:
            clear();
            break;
        case SHOW:
            show();
            break;
        case VARS:
            for (int i = 0; i < 26; i += 1) {
                if (vars_set[i] == 1) {
                    printf("\t%c: %.8g\n", i + 'a', vars[i]);
                }
            }
            printf("\n");
            break;
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2)); 
            break;
        // I can't think of a better way (that wouldn't also be a ton
        // of work) of handling variables than introducing sigils. It
        // feels hacky, but I want to get on with things.
        case '@': // Access a variable
            vi = getvarindex();
            if (vars_set[vi]) {
                push(vars[vi]);
            } else {
                printf("error: variable %c is unset\n", 'a' + vi);
            }
            break;
        case '=': // Assign a variable
            vi = getvarindex();
            vars[vi] = pop();
            vars_set[vi] = 1;
            break;
        case '!': // Unassign a variable
            vi = getvarindex();
            vars_set[vi] = 0;
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            push((int) pop() % (int) op2);
            break;
        case '\n':
            // Do nothing because this is annoying now
            // printf("\teol: %.8g\n", peek());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp] = f;
        sp += 1;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        double ret = val[sp-1];
        sp -= 1;
        return ret;
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double peek(void) {
    if (sp > 0) {
        return val[sp-1];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicate(void) {
    if (sp <= 0) {
        printf("error: stack empty\n");
    } else if (sp > MAXVAL) {
        printf("error: stack full\n");
    } else {
        val[sp] = val[sp-1];
        sp += 1;
    }
}

void swap(void) {
   if (sp < 2) {
       printf("error: not enough elements\n");
   } else {
       double temp = val[sp-1];
       val[sp-1] = val[sp-2];
       val[sp-2] = temp;
   }
}

void clear(void) {
    while (sp > 0) {
        val[sp-1] = 0;
        sp -= 1;
    }
}

void show(void) {
    printf("\tstack: ");
    for (int i = 0; i < sp; i += 1) {
        printf("%.8g ", val[i]);
    }
    printf("\n");
}

int getch(void);
void ungetch(int);

// Single letter, lowercase only... it's very limited
int getvarindex() {
    int ch = getch();
    return ch - 'a';
}

int getop(char s[]) {
    int c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') { }
    s[1] = '\0';

    if (c == '@' || c == '=' || c == '!') {
        return c;
    }

    int i = 0;
    if (isalpha(c)) {
        do {
            i += 1;
            c = getch();
            s[i] = c;
        } while (isalpha(c));
        s[i] = '\0';

        if (c != EOF) {
            ungetch(c);
        }

        if (strcmp(s, "peek") == 0) {
            return PEEK;
        } else if (strcmp(s, "dup") == 0) {
            return DUP;
        } else if (strcmp(s, "swap") == 0) {
            return SWAP;
        } else if (strcmp(s, "clear") == 0) {
            return CLEAR;
        } else if (strcmp(s, "show") == 0) {
            return SHOW;
        } else if (strcmp(s, "sin") == 0) {
            return SIN;
        } else if (strcmp(s, "exp") == 0) {
            return EXP;
        } else if (strcmp(s, "pow") == 0) {
            return POW;
        } else if (strcmp(s, "vars") == 0) {
            return VARS;
        } else {
            return -99;
        }
    }

    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    i = 0;
    if (c == '-') {
        i += 1;
        c = getch();
        if (!isdigit(c) && c != '.') {
            ungetch(c);
            return '-';
        } else {
            s[i] = c;
        }
    } 
    if (isdigit(c)) {
        do { 
            i += 1;
            c = getch();
            s[i] = c;
        } while (isdigit(c));
    }
    if (c == '.') {
        do {
            i += 1;
            c = getch();
            s[i] = c;
        } while (isdigit(c));
    }
    s[i] = '\0';
    
    if (c != EOF) {
       ungetch(c);
    }

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    if (bufp > 0) {
        int val = buf[bufp-1];
        bufp -= 1;
        return val;
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp] = c;
        bufp += 1;
    }
}
