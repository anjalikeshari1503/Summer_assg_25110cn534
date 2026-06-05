#include <stdio.h>
int main(){
    int num ,sum=0;
    printf("Enter the positive number :\n");
    scanf("%d",&num);
    // To check if number is negative
    if(num<=1){
        printf("The number is not perfect\n");
    }
        // Loop for finding divisors
        for(int i=1;i<=num/2;i++){
            // if i divides the number,then it is a divisor
            if(num%i==0){
               sum += i;
            }
        }
        // checks if sum of divisors is equal to number or not
     if(sum==num){
        printf("%d is a perfect number",num);
     }
     else{
        printf("%d is not a perfect number",num);
     }
    

    return 0;

}