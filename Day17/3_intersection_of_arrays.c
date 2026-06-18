#include<stdio.h>
int main()
{
    int a[100],b[100],c,n,m,i,j,k,found;
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
    printf("The intersection of arrays:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            found=0;
            if(a[i]==b[j])
            {
                found=1;
                break;
            }
        }
         c=0;
         for(k=0;k<i;k++)
         {
            if(a[i]==a[k])
            {
                c=1;
                break;
            }
         }
         if(found==1 && c==0)
         {
            printf("%d ",a[i]);
         }
    }        
    return 0;

}