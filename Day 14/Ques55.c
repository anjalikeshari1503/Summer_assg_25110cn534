#include <stdio.h>
// Function to sort array using bubble sort algorithm 
void bubble_sort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main (){
    int n ; // To store the size of the array 
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    // Loop to read the elements of array 
    for (int i=0;i<n;i++){    
        scanf("%d",&arr[i]);
    }
    // To sort the array in ascending order using bubble sort alogorithm 
    bubble_sort(arr,n);
    printf("Second largest element is :%d\n",arr[n-2]);
    return 0;
}