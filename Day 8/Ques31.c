#include <stdio.h>
int main (){
    int n;
    printf("Enter number of rows and columns:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a=1;
        for(int j=1;j<=i;j++){
            printf("%c",a+64);
            a++ ;
        }
        printf("\n");
    }
    return 0;
}