#include <stdio.h>
int main(){
    int original ;
    int num,rem,reverse=0;
    printf("enter the number:\n");
    scanf("%d",&num);
    original=num ;
    while(num!=0){
        rem =num%10;
        reverse = reverse*10+rem ;
        num =num/10;
    }
    if(original==reverse){
printf("The number is palidrome\n");
    }
    
    return 0;

}