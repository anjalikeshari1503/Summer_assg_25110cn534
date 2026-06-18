#include<stdio.h>
int main()
{
    int a[100],b[100],c[100],n,m,i;
    printf("enter the size of both the arrays :");
    scanf("%d%d",&n,&m);
    printf("enter the elements of first array :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the elements of second array:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        c[i]=a[i];
    }
    for(i=0;i<m;i++)
    {
        c[n+i]=b[i];
    }
    printf("The merged array: ");
    for(i=0;i<n+m;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;

}