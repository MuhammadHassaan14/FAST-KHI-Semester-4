#!/usr/bin/bash

#Create a script that lists all files in a directory sorted from smallest to largest.

read -p "Enter the directory to list files: " dir
echo ""

if [ ! -d "$dir" ]; then
    echo "Error: Directory does not exist."
    exit 1
fi

echo -e "File:\t\tSize (in bytes):"
ls -l "$dir" | awk 'NR>1 {printf "%s\t\t%d\n", $9, $5}' | sort -n -k2
