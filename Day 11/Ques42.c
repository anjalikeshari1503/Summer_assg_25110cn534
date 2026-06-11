#include <stdio.h>
int maximum(int a , int b){
    if(a>b){
        return a;
    }
    else 
    return b ;
}
int main(){
    int num1, num2 ;
    printf("Enter two numbers :\n");
    scanf("%d%d",&num1, &num2);
    int result = maximum(num1,num2);
    printf("The maixmum of %d and %d is %d\n",num1,num2,result);
    return 0;
}