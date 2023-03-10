#!/bin/bash

EXPORT_FILE="coding-style-reports.log"

docker run --rm -i -v ".":"/mnt/delivery" -v ".":"/mnt/reports" ghcr.io/epitech/coding-style-checker:latest "/mnt/delivery" "/mnt/reports"

./style $EXPORT_FILE
rm -f $EXPORT_FILE
