// 23K2001 - Muzammil
/*Write a program that lists all files and directories in the current directory using system calls. The program should traverse the
directory structure recursively and print the names of all files and directories found, along with their respective types (file or
directory).*/

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void listFiles(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) return;

    struct dirent *entry;
    char newPath[1024];

    while ((entry = readdir(dir))) {
        if (entry->d_name[0] == '.')
          continue;

        printf("%s/%s\n", path, entry->d_name);
        struct stat st;
        snprintf(newPath, sizeof(newPath), "%s/%s", path, entry->d_name);
        if (stat(newPath, &st) == 0 && S_ISDIR(st.st_mode))
            listFiles(newPath);
    }

    closedir(dir);
}

int main() {
    listFiles("."); // Current directory
    return 0;
}
