#include <stdio.h>
int sumofdigits(int n){
    if(n==0)     // base case
    return 0;
    else
    return (n % 10) + sumofdigits(n/10);  // recursive case
}
int main(){
    int num ;
    printf("Enter the number:\n");
    scanf("%d",&num);
    printf("Sum of digits = %d",sumofdigits(num)); //function calling
    return 0;
}