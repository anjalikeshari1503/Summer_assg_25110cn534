#include <stdio.h>
int fabonacci(int num){
    int a=0,b=1,next ;
    if(num==0)
    return a;
    else if(num==1)
    return b;
    else{
        for(int i=2;i<=num;i++){
            next = a+b;
            a = b;
            b = next;
        }
        return next;
    }
}
int main (){
    int num;
    printf("Enter a number:\n");
    scanf("%d",&num);
    printf("The %dth Fibonacci number is %d.\n", num, fabonacci(num));
    return 0;

}