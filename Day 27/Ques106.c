#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.txt"

// Define the Employee Structure
typedef struct {
    int id;
    char name[50];
    char dept[30];
    float salary;
} Employee;

// Function Declarations
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: printf("Exiting system...\n"); exit(0);
            default: printf("Invalid choice! Please select 1-5.\n");
        }
    }
    return 0;
}

// 1. Append a new employee to the database
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear trailing newline from buffer

    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Strip newline

    printf("Enter Department: ");
    fgets(emp.dept, sizeof(emp.dept), stdin);
    emp.dept[strcspn(emp.dept, "\n")] = 0; 

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // Write structure to file with a trailing format newline
    fprintf(fp, "%d,%s,%s,%.2f\n", emp.id, emp.name, emp.dept, emp.salary);
    fclose(fp);

    printf("Employee record added successfully!\n");
}

// 2. Read and parse all records
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo employee records found.\n");
        return;
    }

    Employee emp;
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("-------------------------------------------------------------\n");

    // Scan the comma-separated data format
    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &emp.id, emp.name, emp.dept, &emp.salary) != EOF) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp.id, emp.name, emp.dept, emp.salary);
    }
    fclose(fp);
}

// 3. Look up a record matching a specific ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found to search.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    Employee emp;
    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &emp.id, emp.name, emp.dept, &emp.salary) != EOF) {
        if (emp.id == searchId) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\nName: %s\nDept: %s\nSalary: %.2f\n", emp.id, emp.name, emp.dept, emp.salary);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Employee with ID %d not found.\n", searchId);
}

// 4. Delete an item by filtering items into a temporary file
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found to delete.\n");
        return;
    }

    FILE *tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int deleteId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    Employee emp;
    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &emp.id, emp.name, emp.dept, &emp.salary) != EOF) {
        if (emp.id == deleteId) {
            found = 1; // Drop this record by skipping the print sequence
        } else {
            fprintf(tempFp, "%d,%s,%s,%.2f\n", emp.id, emp.name, emp.dept, emp.salary);
        }
    }

    fclose(fp);
    fclose(tempFp);

    // Swap files out to make mutations permanent
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) printf("Employee record deleted successfully.\n");
    else printf("Employee with ID %d not found.\n", deleteId);
}