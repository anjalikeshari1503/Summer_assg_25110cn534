#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure
struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra;
    float da;
    float pf;
    float gross_salary;
    float net_salary;
};

// Function Declarations
void addEmployee();
void displayEmployees();
void searchEmployee();

const char* FILE_NAME = "payroll_data.bin";

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Payslips");
        printf("\n3. Search Employee by ID");
        printf("\n4. Exit");
        printf("\n=================================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new record and calculate financial breakdowns
void addEmployee() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("\nError opening database file!\n");
        return;
    }

    struct Employee emp;

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", emp.name); // Accepts spaces in names
    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);

    // Automated Salary Formulas
    emp.hra = emp.basic_salary * 0.20; // 20% HRA
    emp.da = emp.basic_salary * 0.10;  // 10% DA
    emp.pf = emp.basic_salary * 0.12;  // 12% PF Deduction
    emp.gross_salary = emp.basic_salary + emp.hra + emp.da;
    emp.net_salary = emp.gross_salary - emp.pf;

    fwrite(&emp, sizeof(struct Employee), 1, file);
    fclose(file);

    printf("\nRecord added successfully!\n");
}

// Function to display all employee financial records
void displayEmployees() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found! Add an employee first.\n");
        return;
    }

    struct Employee emp;
    printf("\n==========================================================================================");
    printf("\nID\tName\t\tBasic\t\tHRA\t\tDA\t\tPF\t\tNet Salary");
    printf("\n==========================================================================================");

    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        printf("\n%d\t%-12s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f", 
               emp.id, emp.name, emp.basic_salary, emp.hra, emp.da, emp.pf, emp.net_salary);
    }
    printf("\n==========================================================================================\n");
    fclose(file);
}

// Function to find an employee and print a structured payslip
void searchEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int search_id, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        if (emp.id == search_id) {
            found = 1;
            printf("\n=================================");
            printf("\n        EMPLOYEE PAYSLIP        ");
            printf("\n=================================");
            printf("\nID          : %d", emp.id);
            printf("\nName        : %s", emp.name);
            printf("\nBasic Salary: $%.2f", emp.basic_salary);
            printf("\nHRA (20%)   : $%.2f", emp.hra);
            printf("\nDA (10%)    : $%.2f", emp.da);
            printf("\n---------------------------------");
            printf("\nGross Pay   : $%.2f", emp.gross_salary);
            printf("\nPF Ded.(12%): $%.2f", emp.pf);
            printf("\n---------------------------------");
            printf("\nNET SALARY  : $%.2f", emp.net_salary);
            printf("\n=================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee Record with ID %d not found.\n", search_id);
    }
    fclose(file);
}