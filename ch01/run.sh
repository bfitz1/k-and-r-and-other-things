#!/bin/bash

PATH=./bin/:$PATH

function build {
    local name=$1
    shift 

    cc $@ -o ./bin/$name

    if [ $? -eq 0 ]; then
        echo "Successfully built $name."
    fi
}

function help {
    echo "Available commands:"
    for x in $(compgen -A function); do
        echo "    $x"
    done

    echo "Available binaries:"
    for x in bin/*; do
        echo "    ${x##*/}"
    done
}

"${@:-help}"
