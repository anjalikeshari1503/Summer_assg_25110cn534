#include <math.h>
int main()
{
    int i,n,isprime=1;
    printf("Enter number\n");
    scanf("%d",&n);
    if(n<=1)
    isprime=0;
    
    for(i=2;i<=n/2;i++){
        if(n%i==0){
            isprime=0;
            break;
        }
    }
    if(isprime)
    printf("prime number\n");
    else
    printf("not a prime number\n");
    return 0;
}