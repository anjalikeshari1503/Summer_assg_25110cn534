#include<stdio.h>
int main()
{
    int i,j,len=0,k;
    char str[100],a[100];
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    for(i=0;str[i]!='0';i++)
    {
        if(str[i]=='\n')
        {
            break;
        }
        len++;
    }
    j=0;
    for(i=len-1;i>=0;i--)
    {
        a[j]=str[i];
        j++;
    }
    a[j]='\0';
    printf("reverse of the string is %s",a);
    return 0;
}
