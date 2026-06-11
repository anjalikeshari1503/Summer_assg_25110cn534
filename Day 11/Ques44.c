#include <stdio.h>
int factorial (int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int main(){
    int num ;
    printf("Enter a number :\n");
    scanf("%d",&num);
    printf("The factorial of %d is %d\n",num , factorial(num));
  
    return 0;
}