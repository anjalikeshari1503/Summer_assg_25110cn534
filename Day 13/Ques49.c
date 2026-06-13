#include <stdio.h>
int main(){
    int n;   // to store the size of arra
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int arr[n] ;
    printf("Enter the elements of array :\n");
    // To read the elements of array
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements of array are :\n");
    // To print the elements of array 
    for(int i=0 ;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;

}