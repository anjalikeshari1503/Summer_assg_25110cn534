#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
#define NAME_LENGTH 50

int main (){
    char names[MAX_STUDENTS][NAME_LENGTH];
    int marks [MAX_STUDENTS];
    int n;
    printf("Enter number of students:\n");
    scanf("%d",&n);
    // Input student records 
    for (int i=0;i<n;i++){
        printf("\nStudent %d\n",i+1);

        printf("Enter name: ");
        getchar();   // clear new line before fgets
        fgets(names[i],50,stdin);
        names[i][strcspn(names[i],"\n")]='\0';
        
        printf("Enter marks: ");
        scanf("%d",&marks[i]);
    }
    // Display student records
    printf("\n---Student Records---\n");
    printf("%-5s %-20s %-10s\n","No.","NAME","Marks") ;

    for (int i=0;i<n;i++){
        printf("%-5d %-20s %-10d\n",i+1,names[i],marks[i]);
    }

    return 0;

}