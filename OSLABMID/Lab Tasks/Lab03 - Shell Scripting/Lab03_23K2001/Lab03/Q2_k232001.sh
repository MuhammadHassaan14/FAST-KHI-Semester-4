#!/usr/bin/bash

# Write a script that compresses a specified directory into a “.tar.gz” archive with a timestamp
# and allows restoring from a backup.

echo "1. Compress a dir		2. Restore from backup"
read -p "Select an option: " ch

if [ $ch == 1 ]; then
    read -p "Enter directory to compress: " dir
    read -p "Enter destination directory to save backup: " dest
    
    if [ ! -d $dir ]; then
    	echo "Error: Directory does not exist."
        exit 1
    fi
    if [ ! -d $dest ]; then
    	mkdir -p $dest
    fi
    
    timestamp=$(date +"%d-%m-%Y_%H-%M-%S")
    tar -czf "$dest/backup_$timestamp.tar.gz" -C "$(dirname "$dir")" "$(basename "$dir")"
    echo "DIR: $dir successfully compressed to $dest!"

elif [ $ch == 2 ]; then
    read -p "Enter backup file to restore: " backup
    read -p "Enter target directory to restore backup: " dir
    
    if [ ! -f $backup ]; then
    	echo "Error: Backup does not exist."
        exit 1
    fi
    if [ ! -d $dir ]; then
    	mkdir -p $dir
    fi
    
    tar -xzf $backup -C $dir
    echo "Backup: $backup successfully restored to $dir!"
else
    echo "Invalid selection."
fi

