#!/usr/bin/env bash

PATH=./bin/:$PATH

function build-debug {
    local name=$1
    shift

    cc -o "./bin/$name" -std=c99 -Wall -g3 -O0 "$@"
}

function build-release {
    local name=$1
    shift

    cc -o "./bin/$name" -std=c99 -Wall "$@"
}

function help {
    echo "Available tasks"
    sed -n -E 's/^function (.*) {/    \1/p' run.sh

    echo "Available binaries"
    for file in ./bin/*; do
        if [[ $file != *.dSYM ]]; then
            echo "    ${file##*/}"
        fi
    done
}

function default {
    help
}

"${@-default}"
