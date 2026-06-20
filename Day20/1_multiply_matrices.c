#include<stdio.h>
int main()
{
    int a[100][100],b[100][100],c[100][100],m,n,p,q,i,j,k;
    printf("Enter the number of rows and columns of first matrix:");
    scanf("%d%d",&m,&n);
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d%d",&p,&q);
    printf("enter the elements of first matrix: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the elements of second matrix: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    if(n!=p)
    {
        printf("Matrix multiplication not possible!");
    }
    else{
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                c[i][j]=0;
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                for(k=0;k<n;k++)
                {
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
    }
    printf("multiplication of matrices:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}