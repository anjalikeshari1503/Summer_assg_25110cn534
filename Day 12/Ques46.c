#include <stdio.h>
#include <math.h>
int armstrong(int num){
    int sum =0,rem, temp;
    int digit =0;
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
if(sum==num)
    return printf("%d is a Armstrong number\n",num);

else 
   return  printf("%d is not a armstrong number\n",num);

}
int main (){
    int num;
    printf("Enter a number:\n");
    scanf("%d",&num);
    armstrong(num);
    return 0;

}