#include <stdio.h>
#include <string.h>

// Define a structure to hold student details
struct Student {
    int roll_no;
    char name[50];
    int marks[5]; // Array to hold marks for 5 subjects
    int total;
    float percentage;
    char grade[5];
    char status[10];
};

// Function prototypes
void calculate_results(struct Student *s);
void display_marksheet(struct Student s);

int main() {
    struct Student s;
    
    printf("=== STUDENT MARKSHEET GENERATION SYSTEM ===\n\n");
    
    // 1. Gather Student Details
    printf("Enter Student Roll Number: ");
    scanf("%d", &s.roll_no);
    getchar(); // Clear newline character left by scanf
    
    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline from fgets
    
    // 2. Input Marks for 5 Subjects
    char subjects[5][20] = {"Mathematics", "Science", "English", "History", "Computer"};
    printf("\nEnter marks out of 100:\n");
    for(int i = 0; i < 5; i++) {
        do {
            printf("%s: ", subjects[i]);
            scanf("%d", &s.marks[i]);
            if(s.marks[i] < 0 || s.marks[i] > 100) {
                printf("Invalid marks! Please enter between 0 and 100.\n");
            }
        } while(s.marks[i] < 0 || s.marks[i] > 100);
    }
    
    // 3. Process calculations
    calculate_results(&s);
    
    // 4. Generate the formatted marksheet
    display_marksheet(s);
    
    return 0;
}

// Function to handle math and grading rules
void calculate_results(struct Student *s) {
    s->total = 0;
    int failed_any = 0;
    
    // Sum total and check for individual subject passing marks (assume 33 is passing)
    for(int i = 0; i < 5; i++) {
        s->total += s->marks[i];
        if(s->marks[i] < 33) {
            failed_any = 1;
        }
    }
    
    // Calculate percentage
    s->percentage = (float)s->total / 5.0;
    
    // Grade and status allocation
    if (failed_any) {
        strcpy(s->grade, "F");
        strcpy(s->status, "FAIL");
    } else {
        strcpy(s->status, "PASS");
        if (s->percentage >= 90) strcpy(s->grade, "A+");
        else if (s->percentage >= 80) strcpy(s->grade, "A");
        else if (s->percentage >= 70) strcpy(s->grade, "B");
        else if (s->percentage >= 60) strcpy(s->grade, "C");
        else if (s->percentage >= 50) strcpy(s->grade, "D");
        else strcpy(s->grade, "E");
    }
}

// Function to print the formatted report card layout
void display_marksheet(struct Student s) {
    printf("\n====================================================\n");
    printf("                 OFFICIAL MARKSHEET                 \n");
    printf("====================================================\n");
    printf(" Roll No: %-10d | Name: %-25s\n", s.roll_no, s.name);
    printf("----------------------------------------------------\n");
    printf(" %-25s | %-15s\n", "SUBJECT", "MARKS OBTAINED");
    printf("----------------------------------------------------\n");
    printf(" %-25s | %-15d\n", "Mathematics", s.marks[0]);
    printf(" %-25s | %-15d\n", "Science", s.marks[1]);
    printf(" %-25s | %-15d\n", "English", s.marks[2]);
    printf(" %-25s | %-15d\n", "History", s.marks[3]);
    printf(" %-25s | %-15d\n", "Computer", s.marks[4]);
    printf("----------------------------------------------------\n");
    printf(" %-25s | %-15d\n", "TOTAL MARKS (Out of 500)", s.total);
    printf(" %-25s | %-15.2f%%\n", "PERCENTAGE", s.percentage);
    printf(" %-25s | %-15s\n", "FINAL GRADE", s.grade);
    printf(" %-25s | %-15s\n", "RESULT STATUS", s.status);
    printf("====================================================\n");
}