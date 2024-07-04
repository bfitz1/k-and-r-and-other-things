#!/usr/bin/env bash

# Still playing around with this run script idea.
# It might look different from chapter to chapter.

PATH=./bin/:$PATH

function debug { # Build C program with debug information
    local name="$1"
    shift
    cc -o "./bin/$name" -g3 -O0 "$@"
}

function build { # Build C programs
    # Right now this is a silly command that wraps the C compiler.
    # Maybe it'll turn into something more useful later?
    local name="$1"
    shift
    cc -o "./bin/$name" "$@"
}

function help { # Show available binaries and tasks
    # Because grep, sed and friends are line-based I came up with the
    # awkward kludge of having the description on the same line.
    echo "Available tasks:"
    sed -n -E 's/^function (.*) { \# (.*)$/    \1 - \2/p' run.sh

    echo "Available binaries:"
    for bin in ./bin/*; do
        echo -e "    ${bin##*/}"
    done
}

function default { # Task run when no parameters are given
    # Also a bit silly.
    help
}

"${@:-default}"
