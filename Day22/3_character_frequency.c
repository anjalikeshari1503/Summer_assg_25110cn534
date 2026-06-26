#include<stdio.h>
int main()
{
    int i,j,count;
    char str[100];
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ' || str[i]=='\n')
        {
            continue;
        }
        count=1;
        for(j=i+1;str[j]!='\0';j++)
        {
            if(str[i]==str[j])
            {
                count++;
                str[j]=' ';
            }
        }
        printf("%c occurs %d times\n",str[i],count);
    }
    return 0;
}