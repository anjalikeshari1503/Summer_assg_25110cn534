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
    b=a[0];
    count=1;
    for(i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            count++;
        }
        else{
            if(count>max)
            {
                max=count;
                b=a[i];
            }
            count=1;
        }
    }
    if(count>max)
    {
        max=count;
        b=a[n-1];
    }
    printf("The maximum frequency element is %d and its frequency is %d",b,max);
}