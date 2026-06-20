#include<stdio.h>
int main()
{
    int a[100][100],m,n,i,j,sum=0;
    printf("Enter the number of rows:");
    scanf("%d",&m);
    printf("Enter the number of columns: ");
    scanf("%d",&n);
    printf("enter the elements of matrix: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("sum of columns: \n");
    for(i=0;i<m;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        {
            sum+=a[j][i];
        }
        printf("%d\n",sum);
    }
    return 0;
}