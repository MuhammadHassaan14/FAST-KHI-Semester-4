#include <stdio.h>
#include "student.h"

void search_student() {
    int search_id;
    printf("Enter Student ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == search_id) {
            printf("Student found - ID: %d, Name: %s\n", students[i].id, students[i].name);
            return;
        }
    }
    printf("Student with ID %d not found.\n", search_id);
}

