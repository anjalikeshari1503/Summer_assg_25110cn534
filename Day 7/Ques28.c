#include <stdio.h>
int reversenum(int n , int rev){
    if(n<=0)
    return rev;
    else
    return reversenum(n/10 , rev*10 + n%10);
}
int main (){
    int num;
    printf("Enter the number:\n");
    scanf("%d",&num);
    printf("Reversed number of %d is %d",num,reversenum(num,0));
    return 0;
} 