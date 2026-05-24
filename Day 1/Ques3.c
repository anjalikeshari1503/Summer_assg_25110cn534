#include <stdio.h>
int main()
{
    int n, fact=1;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        fact=fact*i;
    }
    printf("factorial of number=%d\n",fact);
return 0;
}