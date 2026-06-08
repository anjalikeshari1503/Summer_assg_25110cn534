#include <stdio.h>
int main(){
    int n;
    printf("Enter the value of rows or columns:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for (int nsp=1;nsp<=n-i;nsp++){
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}