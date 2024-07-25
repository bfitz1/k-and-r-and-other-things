// The book's approach uses a garbage value so the array indexes
// match with the current month. I'm noting this because I really
// don't care for cutesy shit like this, and it tripped me up when
// I read the for-loop in day_of_year. 
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

// Set day of year from month and day
int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++) {
        day += *(daytab + 13*i + leap);
    }
    return day;
}

// Set month, day from day of year
// As far as error checking goes, the only screwy thing I see is that
// the variable i can exceed the array bounds
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < 13 && yearday > daytab[leap][i]; i++) {
        yearday -= *(daytab + 13*i + leap);
    }
    *pmonth = i;
    *pday = yearday;
}
