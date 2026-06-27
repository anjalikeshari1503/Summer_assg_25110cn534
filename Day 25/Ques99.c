#include <stdio.h>
#include <string.h>
#include <math.h>
int main (){
    char names[][50]={"Aman","Karan","Rahul","Sumit","Ritu"};
    int n = sizeof(names) / sizeof(names[0]);
    char temp[50];
    // Bubble sort 
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(strcmp(names[j],names[j+1])>0){
                strcpy(temp ,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);          
              }
        }
    }
printf("Names in alphabetically order \n");
for (int i=0;i<n;i++){
    printf("%s\n",names[i]);
}
return 0;
}