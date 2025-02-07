#include <stdio.h>
#include "student.h"

int main() {
    int choice;
    
    while (1) {
        printf("\nFLEX Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:{
                add_student();
                break;}
            case 2:{
                display_students();
                break;}
            case 3:{
                search_student();
                break;}
            case 4:{
                printf("Exited.\n");
                return 0;}
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

