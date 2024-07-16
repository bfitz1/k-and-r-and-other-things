#!/usr/bin/env bash

PATH=./bin/:$PATH

function build {
    local name=$1
    shift

    cc -o "./bin/$name" -g -O0 "$@"
}

function help {
    echo "Available commands:"
    sed -n -E 's/^function (.*) {$/    \1/p' run.sh

    echo "Available binaries:"
    for x in ./bin/*; do
        if [[ $x != *.dSYM ]]; then
            echo "    ${x##*/}"
        fi
    done
}

function default {
    help
}

"${@:-default}"
