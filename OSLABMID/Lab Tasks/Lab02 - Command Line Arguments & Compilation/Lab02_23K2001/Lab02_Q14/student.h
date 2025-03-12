#ifndef STUDENT_H
#define STUDENT_H
#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Student;

extern Student students[MAX_STUDENTS];
extern int student_count;

void add_student();
void display_students();
void search_student();

#endif

