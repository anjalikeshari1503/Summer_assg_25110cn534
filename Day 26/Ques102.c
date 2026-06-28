#include <stdio.h>
int main (){
    char name[50];
    int age ;
    printf("Enter your name :\n");
    scanf("%s",name);
    printf("Enter your age:\n");
    scanf("%d",&age);
    if(age>=18){
        printf("%s,you are eligible to vote.\n",name);
    }
    else {
        printf("%s,you are not eligible to vote.\n",name);
    }
    return 0;
}