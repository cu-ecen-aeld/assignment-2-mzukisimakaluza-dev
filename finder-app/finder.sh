#!/bin/bash

if [ $# -lt 2 ]
then
    echo "Invalid number of arguments, expected 2 instead got $# arguments"
    exit 1
else
    filesdir=$1
    searchstr=$2

    if [ -d "$filesdir" ]
    then
        FILES="$(grep -lr ${searchstr} ${filesdir} | wc -l)" # Correct
        LINES="$(grep -r ${searchstr} ${filesdir} | wc -l)" # This counts all matching lines [Correct]
        echo "The number of files are ${FILES} and the number of matching lines are ${LINES}"
    else
        echo "No directory named ${filesdir}"
        exit 1
    fi
fi
exit 0
