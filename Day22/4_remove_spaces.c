 #include<stdio.h>
int main()
{
    int i,j;
    char str[100];
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
            for(j=i;str[j]!='\0';j++)
            {
                str[j]=str[j+1];  
            }
        }
    }
    printf("  %s\n",str);
    return 0;
}