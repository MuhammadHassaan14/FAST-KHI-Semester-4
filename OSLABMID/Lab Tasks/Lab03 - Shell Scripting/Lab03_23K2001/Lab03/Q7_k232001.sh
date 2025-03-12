#!/usr/bin/bash

# Create a script that copies all .txt files from one directory to another specified directory.

read -p "Enter the source directory: " SRC_DIR
if [ ! -d "$SRC_DIR" ]; then
	echo "Error: Source directory does not exist"
	exit 1
fi

read -p "Enter the destination directory: " dest
if [[ ! -d "$dest" ]]; then
			mkdir -p $dest
fi
for file in "$SRC_DIR"/*; do
	if [[ "$file" == *.txt ]]; then
		mv "$file" $dest
		echo "File: $file moved to $dest"
	fi
done
