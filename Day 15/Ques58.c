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
    printf("\nEnter number of left rotations:\n");
    scanf("%d",&k);
    // Loop to print the elements of array after left rotation
    for(int i=0;i<k;i++){
        int temp = arr[0];
        for(int j=0;j<n-1;j++){
            arr[j] = arr[j+1];
        }
        arr[n-1] = temp;
    }
    printf("Array after left rotation:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}