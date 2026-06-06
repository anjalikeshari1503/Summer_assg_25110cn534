#include <stdio.h>
int main(){
    int num ,i=0,binary[45];
    printf("Enter the decimal number:\n");
    scanf("%d",&num);
    int decimal =num ;
    if(decimal==0){
        printf("Binary=0");
    }
    while(decimal>0){
        binary[i]=decimal % 2;
        decimal/=2;
        i++ ;
    }
    printf("The binary number of %d is ",num);
    for(int j=i-1;j>=0;j--){
        printf("%d",binary[j]);
    }
    return 0;
}