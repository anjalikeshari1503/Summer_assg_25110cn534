#include<stdio.h>
int main()
{
    int i,j,count=0,words=0;
    char str[100],a[100];
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    for(i=0;str[i]!='\0';i++)
    {
        if((str[i]!=' ' && str[i]!='\n') && (str[i+1]==' ' || str[i+1]=='\n' || str[i+1]=='\0'))
        {
            words++;
        }
    }
    printf("Number of words = %d\n",words);
    return 0;
}