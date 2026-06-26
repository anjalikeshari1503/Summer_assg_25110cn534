 #include<stdio.h>
int main()
{
    int i,j,len=0,k,flag=0;
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
    for(k=0;k<len;k++)
    {
        if(str[k]!=a[k])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nPalindrome string");
    }
    else{
        printf("\nNot palindrome");
    }
    return 0;
}
