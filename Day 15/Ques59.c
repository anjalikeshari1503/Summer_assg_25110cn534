#include <stdio.h>
int main (){
int n ,k;
printf("Enter the size of array:\n");
scanf("%d",&n);
int arr[n];
printf("Enter the elements of array:\n");
// To read the elements of array
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    } 
    // Display original array 
    printf("Original array:\n");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }   
    printf("\nEnter number of right rotations:\n");
    scanf("%d",&k);
    // Loop to print the elements of array after right rotation
    for(int i=0;i<k;i++){
        int temp = arr[n-1];
        for(int j=n-1;j>0;j--){
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }
    printf("Array after right rotation:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}