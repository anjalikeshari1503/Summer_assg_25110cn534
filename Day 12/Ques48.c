#include <stdio.h>
int perfect(int num){
    int sum = 0;
    for(int i = 1; i < num; i++){
        if(num % i == 0){
            sum += i;
        }
    }
    if(sum == num){
        return printf("%d is a perfect number.\n", num);
    }
    else{
        return printf("%d is not a perfect number.\n", num);
    }
}
int main (){
    int num;
    printf("Enter a number:\n");
    scanf("%d",&num);
    perfect(num);
    return 0;
}