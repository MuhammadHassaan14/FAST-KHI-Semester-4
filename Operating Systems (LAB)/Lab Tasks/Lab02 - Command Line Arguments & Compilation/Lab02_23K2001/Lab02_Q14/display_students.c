#include <stdio.h>
#include "student.h"

void display_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    printf("--------------------------\n");
    for (int i = 0; i < student_count; i++)
        printf("ID: %d\t| Name: %s\n", students[i].id, students[i].name);
    
    printf("--------------------------\n");
}

