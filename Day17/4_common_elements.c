#include<stdio.h>
int main()
{
    int a[100],b[100],c[100],n,m,i,j,found;
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
    int k=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            found=0;
            if(a[j]==b[i])
            {
                found=1;
                break;
            }
            else{
                found=0;
            }
        }
        if(found==1)
        {
            c[k]=b[i];
            k++;
        }
    }
    printf("The common elements are: ");
    for(i=0;i<k;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;

}