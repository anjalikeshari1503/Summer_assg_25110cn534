#include <stdio.h>
#include <math.h>
int main(){
    int num ,digit=0,rem ,sum=0 ;
printf("enter the number :\n");
scanf("%d",&num);
int temp ;
//To find number of digits
temp=num;
do{
    digit++ ;
    temp/=10;
}while(temp!=0);
// To check armstrong number 
temp =num;
while(temp!=0){
    rem =temp%10;
 sum +=pow(rem,digit);
 temp/=10 ;
}
if(sum==num){
    printf("%d is a Armstrong number\n",num);
}
else {
    printf("%d is not a armstrong number\n",num);
}
return 0;

}