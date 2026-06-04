#include <stdio.h>
int main(){
    int a=0 ,b=1;
    int n, next ;
    printf("enter value of n:\n");
    scanf("%d",&n);
    printf("Fabonacci series:\n");

    while(a<=n){
    printf("%d ",a);
    next =a+b;
    a=b;
    b=next;
    }
 return 0;
}