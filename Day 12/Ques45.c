#include <stdio.h>
int palindrome(int num){
    int original = num;
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10; // Get the reverse of the number
        num /= 10;
    }
    return original == reversed;   // Check if the original number is equal to the reversed number or not 
}
int main(){
    int num;
    printf("Enter a number :\n");
    scanf("%d",&num);
    if(palindrome(num)) // function calling 
    printf("%d is a palindrome number.\n",num);
    else 
    printf("%d is not a palindrome number.\n",num);
    return 0;
}