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
    int m, n;
    printf("Enter two numbers m and n:\n");
    scanf("%d%d",&m,&n);
    int result ;
   result = Gcd(m,n);
   printf("gcd of %dand %d =%d", m,n,result);
    return 0;

}
