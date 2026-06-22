#include<stdio.h>
int main()
{
    int i,len=0;
    char str[100];
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    for (i = 0; str[i]!='\0'; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i]=str[i]-32;
        }
    }
    printf("\nString in uppercase = %s",str);   
    return 0;
}
