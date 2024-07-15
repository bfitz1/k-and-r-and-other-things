#!/usr/bin/env bash

PATH=./bin/:$PATH

function build {
    local name=$1
    shift

    cc -o "./bin/$name" -g -O0 "$@"
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
