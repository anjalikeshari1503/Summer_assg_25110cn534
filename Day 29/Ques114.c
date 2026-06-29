#include <stdio.h>
#include <stdlib.h>
int main (){
    int choice ;
    do {
        printf("\n===MENU DRIVEN OPERATING SYSTEM===\n");
        printf("1. Show current directory\n");
        printf("2. List files and folders\n");
        printf("3. Create a directory\n");
        printf("4. Delete a directory\n");
        printf("5. EXIT\n");
        printf("Enter tour choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                   system("cd");
                   break ;
            case 2: 
                   system ("dir");
                   break;
            case 3: {
                char dirname[50];
                printf("Enter directory name:");
                scanf("%s",dirname);
                char command[100];
                sprintf(command,"mkdir %s",dirname);
                system(command);
                break ;
            }
            case 4: {
                char dirname[50];
                printf("Enter directory name to remove:");
                scanf("%s",dirname);
                char command[100];
                sprintf(command,"rmdir %s",dirname);
                system(command);
                break ;
            }    
            case 5: 
                   printf("....Exiting....\n");
                   break ;
            default : printf("Invalid choice!\n");

        }
    }while(choice!=5);
    return 0;
}