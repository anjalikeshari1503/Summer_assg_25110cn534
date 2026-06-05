# include <stdio.h>
// To find factorial of a number 
int factorial(int n){
    int fact =1;
    if(n<1)
    return 0;
    else if(n==1)
    return 1;
    else {
      for(int i=1;i<=n;i++){
        fact=fact*i;
      }
    }
    return fact;
}
int main(){
int num,rem,sum=0;
printf("enter the number:\n");
scanf("%d",&num);   
while(num>0){
  // To find sum of factorials of each digit
  rem =num%10;
  sum +=factorial(rem);
  num/=10;
}  
// To check if sum of factorials is equal to a number or not
if(sum==num){
  printf("%d is a strong number",num);
}
else{
  printf("%d is not a strong number",num);
}
return 0;
}