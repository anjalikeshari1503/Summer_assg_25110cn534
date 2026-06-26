#include<stdio.h>
int main()
{
    int i,j,count;
    char str[100],a[100],k;
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    printf("Enter another string: ");
    fgets(a,sizeof(a),stdin);
    for(i=0;str[i]!='\0';i++)
    {
        for(j=i+1;str[j]!='\0';j++)
        {
            if(str[i]>str[j])
            {
                k=str[i];
                str[i]=str[j];
                str[j]=k;
            }
        }
    }
    for(i=0;a[i]!='\0';i++)
    {
        for(j=i+1;a[j]!='\0';j++)
        {
            if(a[i]>a[j])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    for(i=0;a[i]!='\0';i++)
    {
        count=1;
        if(a[i]!=str[i])
        {
            count=0;
            break;
        }
    }
    if(count==1)
    {
        printf("The given strings are anagrams");
    }
    else{
        printf("The given strings are not anagrams");
    }
    return 0;
}