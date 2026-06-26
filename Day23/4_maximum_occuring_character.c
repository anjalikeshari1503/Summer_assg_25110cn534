#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,count,max=0;
    char str[100],maxchar;
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);
    for(i=0;str[i]!='\0';i++)
    {
        count=1;
        for(j=i+1;str[j]!='\0';j++)
        {
            if(str[i]==str[j])
            {
                count++;
            }
        }
        if(count>max)
        {
            max=count;
            maxchar=str[i];
        }
    }
    printf("Maximum occuring character: %c\n",maxchar);
    printf("Frequency: %d\n",max);
    return 0;
}