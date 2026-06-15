#include <stdio.h>
int linear_search(int arr[],int n,int key){
    for (int i=0;i<n;i++){
        if (arr[i]== key){
            return i;// return the index of the element if found
        }
    }
            return -1; // return -1 if the element not found 
} 
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
    int key; // To store the element to search
    printf("Enter the element to search :\n");
    scanf("%d",&key);
    int result = linear_search(arr,n,key);
    if (result == -1){
        printf("Element not found.\n");
    }
    else{
        printf("Element found at index %d.\n",result);
    }
    return 0;
}