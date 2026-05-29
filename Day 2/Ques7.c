#include <stdio.h>
int main(){
    int num,digit,product=1;
    printf("enter the number:\n");
    scanf("%d",&num);
    while(num!=0){
        digit =num%10;
        product = product*digit ;
        num =num/10;
    }
    printf("product of digits=%d\n",product);
    return 0;
}