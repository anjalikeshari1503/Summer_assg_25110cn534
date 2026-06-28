
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILE_NAME "students.dat"

// Define the structure of a student record
typedef struct {
    int roll_no;
    char name[50];
    float gpa;
} Student;

// Function Prototypes
void add_student();
void display_all();
void search_student();
void delete_student();

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by Roll No\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: display_all(); break;
            case 3: search_student(); break;
            case 4: delete_student(); break;
            case 5: printf("Exiting system. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. Add a new student record to the file
void add_student() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append binary mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);
    getchar(); // Clear trailing newline from buffer

    printf("Enter Full Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove newline character

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    fwrite(&s, sizeof(Student), 1, fp); // Write struct block directly to file
    fclose(fp);
    printf("Record added successfully!\n");
}

// 2. Read and display all student records
void display_all() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read binary mode
    if (fp == NULL) {
        printf("\nNo records found. File is empty!\n");
        return;
    }

    Student s;
    printf("\n---------------------------------------------\n");
    printf("%-10s %-25s %-5s\n", "Roll No", "Name", "GPA");
    printf("---------------------------------------------\n");

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        printf("%-10d %-25s %-5.2f\n", s.roll_no, s.name, s.gpa);
    }
    printf("---------------------------------------------\n");
    fclose(fp);
}

// 3. Search a student record by Roll Number
void search_student() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records to search!\n");
        return;
    }

    int target_roll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &target_roll);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == target_roll) {
            printf("\nRecord Found!");
            printf("\nRoll No: %d", s.roll_no);
            printf("\nName   : %s", s.name);
            printf("\nGPA    : %.2f\n", s.gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record with Roll Number %d not found.\n", target_roll);
    }
    fclose(fp);
}

// 4. Delete a record using a temporary file transfer
void delete_student() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found to delete!\n");
        return;
    }

    FILE *temp_fp = fopen("temp.dat", "wb");
    if (temp_fp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int target_roll, found = 0;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &target_roll);

    Student s;
    // Copy all records except the matching one to the temporary file
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == target_roll) {
            found = 1; // Skip writing this record
        } else {
            fwrite(&s, sizeof(Student), 1, temp_fp);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    if (found) {
        remove(FILE_NAME);             // Delete old database file
        rename("temp.dat", FILE_NAME); // Rename temp file to main database file
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.dat"); // Clean up temp file if nothing changed
        printf("Record with Roll Number %d not found.\n", target_roll);
    }
}