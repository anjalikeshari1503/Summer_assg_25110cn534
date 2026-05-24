#include <stdio.h>
int main(){
 int n ;
 printf("enter value of number:\n");
 scanf("%d",&n);
 for (int i=1;i<=10;i++){
    n*i ;
    printf("%d*%d=%d\n",n,i,n*i);
 }
 return 0;
}