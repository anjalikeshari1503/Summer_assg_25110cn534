#include <stdio.h>
int fabonacci(int n){
    if(n<=1)     // base case
    return n;
    else
    return fabonacci(n-1)+fabonacci(n-2);  //recursive case
}
int main(){
    int n;
    printf("Enter the number of terms:\n");
    scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("%d ",fabonacci(i)); //function calling
  }

}