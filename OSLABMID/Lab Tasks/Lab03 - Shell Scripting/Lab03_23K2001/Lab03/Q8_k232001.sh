#!/usr/bin/bash

# You are tasked with creating a bash script that renames multiple files in a directory according to
# a specified naming convention.

dir=$1
nc=$2
if [ -z "$dir" ] || [ -z "$nc" ]; then
    echo "Please provide both: directory & naming convention to proceed!"
    exit 1
fi
if [ ! -d $dir ]; then
	echo "Error: src directory does not exist."
	exit 1
fi

i=0
for file in $dir/*; do
	((i++))
	mv $file "$dir/$nc$i."${file##*.}""
	if [ $? -eq 0 ]; then
        	echo "Renamed: "${file##*/}" to $nc$i."${file##*.}""
    	else
        	echo "Error: Failed to rename $file"
    	fi
done
echo ""
echo "All files have been renamed as required!"
