 #include<stdio.h>
int main()
{
    int i=0,j,k;
    char str[100];
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    for(i=0;str[i]!='\0' && str[i]!='\n';i++)
    {
        for(j=i+1;str[j]!='\0' && str[j]!='\n';)
        {
            if(str[i]==str[j])
             {
                for(k=j;str[k]!='\0';k++)
                { 
                    str[k]=str[k+1];     
                }
             }
             else{
                j++;
             }
        }
    }
    printf("String after removing duplicates: %s",str);
    return 0;
}