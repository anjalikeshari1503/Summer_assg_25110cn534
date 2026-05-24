#include <stdio.h>
int main()
{
    int n,sum=0;
    printf("enter value of n:\n");

    scanf("%d",&n);
    for (int i=0;i<=n;i++){
      sum +=i ;
      
    }
    printf("sum of n numbers=%d\n",sum);
    return 0;
}