#include <stdio.h>
int main(){
    int n;
    printf("Enter the value of rows or columns:\n");
    scanf("%d",&n);
    for (int i=n;i>=1;i--){
        for (int j=0;j<n-i;j++){
            printf(" ");
        }
        for(int k=1;k<=2*i-1;k++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}