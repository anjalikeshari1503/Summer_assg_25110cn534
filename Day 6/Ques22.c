#include <stdio.h>
#include <math.h>
int main(){
    int num,i=0,decimal=0,rem;
    printf("Enter the binary number:\n");
    scanf("%d",&num);
    int binary =num;
    while(binary!=0){
        rem = binary % 10;
        decimal+= rem*pow(2,i);
        binary/=10;
        i++ ;
    }
    printf("Decimal number of %d is %d",num,decimal);

    return 0;
}