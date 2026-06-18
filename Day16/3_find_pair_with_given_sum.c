#include<stdio.h>
int main()
{
    int a[100],n,i,j,sum;
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the sum: ");
    scanf("%d",&sum);
    printf("enter the array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==sum)
            {
                printf(" the pairs are %d and %d\n",a[i],a[j]);
            }
        }
    }
    return 0;
}