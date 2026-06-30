#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int empId[MAX];
    char empName[MAX][50];
    float salary[MAX];

    int count = 0, choice, searchId;

    do {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter Employee ID: ");
            scanf("%d", &empId[count]);

            printf("Enter Employee Name: ");
            scanf(" %[^\n]", empName[count]);

            printf("Enter Salary: ");
            scanf("%f", &salary[count]);

            count++;
            printf("Employee Added Successfully!\n");
            break;

        case 2:
            if(count == 0) {
                printf("No employee records found.\n");
            } else {
                printf("\n%-10s %-20s %-10s\n",
                       "ID", "NAME", "SALARY");

                for(int i = 0; i < count; i++) {
                    printf("%-10d %-20s %.2f\n",
                           empId[i], empName[i], salary[i]);
                }
            }
            break;

        case 3: {
            int found = 0;

            printf("Enter Employee ID to search: ");
            scanf("%d", &searchId);

            for(int i = 0; i < count; i++) {
                if(empId[i] == searchId) {
                    printf("\nEmployee Found\n");
                    printf("ID: %d\n", empId[i]);
                    printf("Name: %s\n", empName[i]);
                    printf("Salary: %.2f\n", salary[i]);
                    found = 1;
                    break;
                }
            }

            if(!found)
                printf("Employee not found.\n");

            break;
        }

        case 4:
            printf("Thank you!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}