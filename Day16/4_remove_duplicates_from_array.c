#include<stdio.h>
int main()
{
    int n,a[100],i,j,k,m,count=1,max=0,b;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("enter the array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    count=1;
    for(i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            for(j=i+1;j<n-1;j++)
            {
                a[j]=a[j+1];
            }
            n--;
            i--;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}    