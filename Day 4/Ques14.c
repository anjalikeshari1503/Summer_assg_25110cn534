#include <stdio.h>
int fabonacci(int n){
    if(n<=0)
    return 0;
    if(n==1)
    return 1;
    int a=0 ,b=1,next=0 ;
for(int i=2;i<=n;i++){
    next =a+b;
    a=b;
    b=next;
    }
    return b;

}
int main(){
    int m;
    printf("enter value of m:\n");
    scanf("%d",&m);
    printf("The %dth term of fabonacci is=%d",m,fabonacci(m));
 return 0;
}