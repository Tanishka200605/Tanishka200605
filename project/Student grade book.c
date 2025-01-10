#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing student information
typedef struct {
    int rollNo;
    char name[50];
    float total_marks;
} Student;

// Function prototypes
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\nStudent Grade Book System\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student by Roll Number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add a student to the gradebook
void addStudent() {
    FILE *file = fopen("students.dat", "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    getchar(); // Clear the input buffer
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove newline character
    printf("Enter Total Marks: ");
    scanf("%f", &s.total_marks);

    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);

    printf("Student added successfully!\n");
}

// Function to view all students in the gradebook
void viewStudents() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    Student s;
    printf("\n%-10s %-30s %-10s\n", "Roll No", "Name", "Total Marks");
    printf("----------------------------------------------------\n");
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("%-10d %-30s %-10.2f\n", s.rollNo, s.name, s.total_marks);
    }

    fclose(file);
}

// Function to search for a student by roll number
void searchStudent() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    int rollNo;
    int found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollNo);

    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNo == rollNo) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", s.rollNo);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.total_marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found!\n", rollNo);
    }

    fclose(file);
}

// Function to delete a student by roll number
void deleteStudent() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        fclose(file);
        return;
    }

    int rollNo;
    int found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollNo);

    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNo == rollNo) {
            found = 1;
        } else {
            fwrite(&s, sizeof(Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        printf("Student with Roll No %d deleted successfully!\n", rollNo);
    } else {
        printf("Student with Roll No %d not found!\n", rollNo);
    }
}
