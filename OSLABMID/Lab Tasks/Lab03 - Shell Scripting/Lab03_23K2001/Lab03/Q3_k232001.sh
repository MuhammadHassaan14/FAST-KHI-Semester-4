#!/usr/bin/bash

#Create a script that takes a filename as input and creates a backup of the file with the current
#date appended to the filename.

read -p "Enter the filename to back up: " file

if [ ! -f "$file" ]; then
    echo "Error: File does not exist."
    exit 1
fi

timestamp=$(date +"%d-%m-%Y_%H-%M-%S")
name="$(basename "$file" .${file##*.})_$timestamp.${file##*.}"
cp "$file" "$(dirname "$file")/$name"
echo "Backup created: $(dirname "$file")/$name"
