#include <stdio.h>
int main(){
    int num ,largest=1;
    printf("Enter the number:");
    scanf("%d",&num);
    int n=num; // save original number
   for(int i=2;i<=n;i++){
       while(n%i==0){
           largest =i; // largest prime factor
           n/=i;
           
       }
   }
   printf("The largest prime factor of a number %d is=%d",num,largest);
    return 0;
} 