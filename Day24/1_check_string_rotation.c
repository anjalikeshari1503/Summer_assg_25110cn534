#include<stdio.h>
int main()
{
    int i,j,count,len1=0,len2=0,found=0;;
    char str[100],a[100],k,b[100];
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    printf("Enter another string: ");
    fgets(a,sizeof(a),stdin);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='\n')
        {
            break;
        }
        len1++;
    }
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='\n')
        {
            break;
        }
        len2++;
    }
    if(len1!=len2)
    {
        printf("Not a rotation");
    }
    else{  
        for(i=0;str[i]!='\0';i++)
        {
            b[i]=str[i];
        }
        for(i=0;str[i]!='\0';i++)
        {
            b[len1+i]=str[i];
        }
        b[2*len1]='\0';
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(b[i+j]!=a[j])
                {
                    break;
                }
            }
            if(j==len2)
                {
                    found=1;
                    break;
                } 
        }
        if(found==1)
        {
            printf("Strings are rotations");
        }
        else{
            printf("Strings are not rotations");
        }
    }
    return 0;
}