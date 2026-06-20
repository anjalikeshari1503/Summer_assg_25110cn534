#include<stdio.h>
int main()
{
    int a[100][100],m,n,i,j,flag=1;
    printf("Enter the number of rows:");
    scanf("%d",&m);
    printf("Enter the number of columns: ");
    scanf("%d",&n);
    if(m==n)
    {
        printf("enter the elements of matrix: ");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]!=a[j][i])
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)
        {
            printf("symmetric matrix");
        }
        else{
            printf("not symmetric");
        }
    }
    else{
        printf("not symmetric");
    }
    return 0;
}