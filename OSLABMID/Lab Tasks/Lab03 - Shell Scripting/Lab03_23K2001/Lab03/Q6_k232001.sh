#!/usr/bin/bash

#Create a script that finds and deletes all empty files in a directory.

read -p "Enter directory to check for empty files: " dir
if [ ! -d "$dir" ]; then
    echo "Error: Directory does not exist."
    exit 1
fi

empty=$(find "$dir" -type f -empty)
if [ -z "$empty" ]; then
    echo "No empty files found in $dir."
    exit 0
fi

echo "The following empty files were found:"
echo "$empty"
for file in $empty; do
	rm $file
done

echo ""
echo "All empty files have been deleted from $dir."


