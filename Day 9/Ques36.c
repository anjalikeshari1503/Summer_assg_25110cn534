#include <stdio.h>
int main (){
    int n;
    printf("Enter value of rows and columns:\n");
    scanf("%d",&n);
    // outer loop handles rows
    for (int i=1;i<=n;i++){
        // inner loop handles columns
        for(int j=1;j<=n;j++){
            // cases where asterik print
            if(i==1||i==n||j==1||j==n){
                printf("*");
            }
            else {
            printf(" ");
            }
        }
        // to move cusror on next line 
        printf("\n");
    }
    return 0;
}