// MINI PROJECT--
 // STUDENT REPORT CARD GENERATOR 
    
#include <stdio.h>

int main() {
    char name[50];
    int rollNo;
    float marks[5], total = 0, percentage;
    char grade;

    // Input student details
    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Roll Number: ");
    scanf("%d", &rollNo);


    // Input marks for 5 subjects
    printf("\nEnter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        total += marks[i];
    }

    // Calculate percentage
    percentage = total / 5;

    // Determine grade
    if (percentage >= 90)
        grade = 'A';
    else if (percentage >= 80)
        grade = 'B';
    else if (percentage >= 70)
        grade = 'C';
    else if (percentage >= 60)
        grade = 'D';
    else
        grade = 'F';

    // Display report card
    printf("\n=================================\n");
    printf("         STUDENT REPORT CARD\n");
    printf("=================================\n");
    printf("Name       : %s\n", name);
    printf("Roll No    : %d\n", rollNo);

    for (int i = 0; i < 5; i++) {
        printf("Subject %d  : %.2f\n", i + 1, marks[i]);
    }

    printf("---------------------------------\n");
    printf("Total Marks: %.2f / 500\n", total);
    printf("Percentage : %.2f%%\n", percentage);
    printf("Grade      : %c\n", grade);
    printf("=================================\n");

    return 0;
}