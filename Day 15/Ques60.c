#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n ; // To store the size of array 
    printf("Enter the size of array :\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
// To read the elements of array
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    } 
    // Here nz stands for non zero element and z stands for zero element .
    int nz = 0, z = 0;
    while(nz<n){
        if(arr[nz]!=0){
            swap(&arr[nz], &arr[z]);  // Swap non zero element with zero element 
            z++ ;
        }
        nz++;
    }
    printf("\nArray after moving zeros to end:\n");
    // Loop to print array after moving zero to end .
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;

}