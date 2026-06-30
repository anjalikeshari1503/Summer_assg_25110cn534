#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50

int main (){
    char books[MAX_BOOKS][TITLE_LENGTH];
    int n,choice,count=0;
    do{
        printf("\n====MINI LIBRARY SYSTEM====\n");
        
        printf("1. Add Books\n");
        printf("2. Display books\n");
        printf("3. Search book\n");
        printf("4. EXIT\n");
        printf("Enter choice;\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                   printf("Enter how many books to add\n");
                   scanf("%d",&n);
                   for (int i=0;i<n;i++){
                    printf("Enter book title %d:",count+1);
                    scanf("%[^\n]",books[count]);
                    count ++ ;
                    break ;
                }
            case 2: 
                   if(count==0){
                    printf("No books is available,\n");
                   }
                   else {
                    printf("\n---Book List---\n");
                    for(int i=0;i<count;i++){
                        printf("%d.%s\n",i+1,books[i]);
                    }
                   }
                   break ;
            case 3: 
                   {
                    char search[TITLE_LENGTH];
                    int found=0;
                    printf("Enter book title to search:");
                    scanf("%[^\n]",search);
                    for(int i=0;i<count;i++){
                        if(strcmp(books[i],search)==0){
                            printf("Book Found:%s\n",books[i]);
                            found =1;
                            break;
                        }
                    }
                    if(!found)
                    printf("Book not found.\n");
                    break;
                   }
            case 4: 
                   printf("...EXITING...\n");
                   break;
            default : printf("Invalid choice.\n");              
        }
        
    }while(choice!=4);
    return 0;

}
