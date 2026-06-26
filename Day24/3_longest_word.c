 #include<stdio.h>
int main()
{
    int i=0,j,len=0,max=0;
    char str[100],a[100];
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    while(1)
    {
        if(str[i]!= ' ' && str[i]!='\0' && str[i]!='\n')
        {
            len++;
        }
        else{
            if(len>max)
            {
                max=len;
                for(j=0;str[i-len+j];j++)
                {
                    a[j]=str[i-len+j];
                    a[len]='\0';
                }
            }
            len=0;
            if(str[i]=='\0' || str[i]=='\n')
            {
                break;
            }
        }
        i++;
    }
    printf("Longest word: %s",a);
    return 0;
}