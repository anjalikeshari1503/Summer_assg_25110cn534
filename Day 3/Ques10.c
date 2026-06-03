#include <math.h>
int main()
{
    int i,n,isprime=1;
    printf("Enter number\n");
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        isprime=1;
        for(int j=2;j<=i/2;j++){
            if(i%j==0)
            isprime=0;
        }
        if(isprime)
        printf("%d\n",i);
    }
    
    return 0;
}