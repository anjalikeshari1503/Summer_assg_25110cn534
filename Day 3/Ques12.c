#include <stdio.h>
int Gcd (int a,int b){
    int temp ;
    while(b!=0){
   temp =b;
  b=a%b;
  a=temp;
    }
  return a;
}
int main(){
    int m,n,lcm;
    printf("Enter two numbers m and n:\n");
    scanf("%d%d",&m,&n);
    lcm = (m*n)/Gcd(m,n);
    printf("LCM of %dand %d=%d\n",m,n,lcm);
    return 0;

}
