#include <stdio.h>
#include <string.h>
#include "student.h"

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached!\n");
        return;
    }
    
    printf("Enter Student ID: ");
    scanf("%d", &students[student_count].id);
    
    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[student_count].name);

    student_count++;
    printf("Student added successfully!\n");
}

