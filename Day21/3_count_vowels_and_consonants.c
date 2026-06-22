#include<stdio.h>
int main()
{
    int i,vow=0,cons=0;
    char str[100];
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    i=0;
    while(str[i]!='\0')
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            if(str[i]=='a'|| str[i]=='e'|| str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
            {
                vow++;
            }
            else{
                cons++;
            }
        }
        i++;
    }
    printf("\nTotal number of vowels =%d\n Total number of consonant=%d",vow,cons);
    return 0;
}
