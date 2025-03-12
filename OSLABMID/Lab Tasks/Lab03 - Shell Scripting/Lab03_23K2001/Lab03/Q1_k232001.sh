#!/usr/bin/bash

# Write a script that moves files into separate folders based on their extensions (e.g., .jpg files into
# an Images folder, .txt files into a Documents folder).

read -p "Enter the source directory: " SRC_DIR

if [ ! -d "$SRC_DIR" ]; then
	echo "Error: Source directory does not exist"
	exit 1
fi

for file in "$SRC_DIR"/*; do
	if [[ "$file" == *.txt ]]; then
		if [[ ! -d "$SRC_DIR/Documents" ]]; then
			mkdir -p "$SRC_DIR/Documents"
		fi
		mv "$file" "$SRC_DIR/Documents"
		echo "File: $file moved to $SRC_DIR/Documents"
	elif [[ "$file" == *.jpg ]]; then
		if [[ ! -d "$SRC_DIR/Images" ]]; then
			mkdir -p "$SRC_DIR/Images"
		fi
		mv "$file" "$SRC_DIR/Images"
		echo "File: $file moved to $SRC_DIR/Images"
	fi
done

