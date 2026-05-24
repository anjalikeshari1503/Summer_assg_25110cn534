#include <stdio.h>
int main (){
  int num ,count=0;
  printf("enter number:\n");
  scanf("%d",&num);
 do {
    num/=10;
    ++count ;
 }while(num!=0);
 
 printf("number of digits in a number=%d\n",count);
    return 0;
}