#include <stdio.h>
int main(){
   int num ;
   printf("Enter the number:\n");
   scanf("%d",&num);
   printf("Factors of a number %d is=",num);
   // Loop to find divisors of a number 
    for(int i=1;i<=num/2;i++){
        if(num%i==0){
            printf("%d ",i);
        }
    }
   
    return 0;
}