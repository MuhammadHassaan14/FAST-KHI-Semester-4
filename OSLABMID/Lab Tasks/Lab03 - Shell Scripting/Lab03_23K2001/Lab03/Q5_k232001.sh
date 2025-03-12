#!/usr/bin/bash

#Write a script that moves all files older than 7 days from the current directory to a backup/folder.

read -p "Enter source directory: " src
read -p "Enter destination (backup) directory: " backup

if [ ! -d $src ]; then
	echo "Error: src directory does not exist."
	exit 1
fi
if [ ! -d $backup ]; then
	mkdir -p $backup
fi

mv $(find $src -type f -mtime +7) "$backup" 
echo "All files older than 7 days have been moved to $backup/"
