#include<stdio.h>
int main()
{
    int i,len=0;
    char str[100];
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
    printf("The length of given string is %d",len);
    return 0;
}
