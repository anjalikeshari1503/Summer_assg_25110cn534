#include <stdio.h>
int main (){
    int n ; // To store the size of the array
    printf("Enter the size of array :\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array :\n");
 // To read the elements of array
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }    
    printf("Reversed array :\n");
    // Loop to print the elements of array in reverse order 
    for (int i=n-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
    return 0;
}