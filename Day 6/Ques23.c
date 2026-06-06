int main(){
    int num ,i=0,binary[45];
    int count =0;
    printf("Enter the decimal number:\n");
    scanf("%d",&num);
    int decimal =num ;
    if(decimal==0){
        printf("Binary=0");
    }
    // To find binary form
    while(decimal>0){
        binary[i]=decimal % 2;
        decimal/=2;
        i++ ;
    }
    // To Print binary form
    printf("The binary number of %d is ",num);
    for(int j=i-1;j>=0;j--){
        printf("%d",binary[j]);
    }
    // loop for checking set bits in binary form
for(int j=0;j<=i;j++){
    if(binary[j]==1)
    count++;
}
// To print number of set bits in a given number
printf("\nNumber of set bits in %d is = %d",num,count);
    return 0;
}