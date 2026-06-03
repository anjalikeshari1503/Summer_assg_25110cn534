#include <stdio.h>
int main(){
    int m,n,gcd ;
    printf("Enter two numbers m and n:\n");
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m && i<=n;i++){
        if(m%i==0&&n%i==0)
        gcd=i;
    }
    printf("Gcd of %d and %d is=%d\n",m,n,gcd);
    return 0;

}
