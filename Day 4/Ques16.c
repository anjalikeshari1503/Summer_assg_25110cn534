#include <stdio.h>
#include <math.h>
int main(){
   int start ,end ;
   int num;
printf("enter start and end of range :\n");
scanf("%d%d",&start,&end);

for(int num=start; num<=end;num++){
    int digit=0,rem ,sum=0 ;
    int temp ;
//To find number of digits
temp=num;
while(temp>0){
    digit++ ;
    temp/=10 ;
}
// To check armstrong number 
temp =num;
while(temp!=0){
    rem =temp%10;
 sum +=pow(rem,digit);
 temp/=10 ;
}

if(sum==num){
    printf("%d ",num);
}
}

return 0;

}