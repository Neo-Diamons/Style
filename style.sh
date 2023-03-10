#!/bin/bash

EXPORT_FILE="coding-style-reports.log"

function cat_readme() {
    echo "Usage: ./style.sh [OPTION]..."
    echo "Check the coding style of your project."
    echo ""
    echo "Options:"
    echo "  -u, --update    Update the coding style checker."
    echo "  -v, --version   Display the coding style checker version."
    echo "  -h, --help      Display this help and exit."
}

function cat_version() {
    echo "Coding style checker version 1.0.0"
}


if [ $# -eq 1 ]; then
    if [ "$1" == "-u" ] || [ "$1" == "--update" ]; then
        sudo docker pull ghcr.io/epitech/coding-style-checker:latest && sudo docker image prune -f
        exit 0

    elif [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
        cat_readme
        exit 0

    elif [ "$1" == "-v" ] || [ "$1" == "--version" ]; then
        cat_version
        exit 0

    else
        cat_readme
        exit 1
    fi

else
    if [ $# -ne 0 ]; then
        cat_readme
        exit 1

    else
        docker run --rm -i -v ".":"/mnt/delivery" -v ".":"/mnt/reports" ghcr.io/epitech/coding-style-checker:latest "/mnt/delivery" "/mnt/reports"
    fi
fi

if [ -f $EXPORT_FILE ]; then
    ./style $EXPORT_FILE
    rm -f $EXPORT_FILE
fi
