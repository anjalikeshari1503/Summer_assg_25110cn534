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
        if(count==1)
        {
            printf(" First non-repeating character is %c ",str[i]);
            break;
        }
    }
    return 0;
}