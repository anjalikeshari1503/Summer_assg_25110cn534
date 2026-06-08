#include <stdio.h>
int main (){
    int n;
    printf("Enter the number of rows or columns:\n");
    scanf("%d",&n);
    int a=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%c",a+64);
        }
        a++ ;
    printf("\n");
    }
    return 0;
}