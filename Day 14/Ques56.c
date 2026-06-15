#include <stdio.h>
int main (){
 int n ; // To store the size of array 
 printf("Enter the size of array :\n");
 scanf("%d",&n);
 int arr[n];
  printf("Enter array element:\n");
  // To read the elements of array
 for (int i=0;i<n;i++){
    scanf("%d",&arr[i]);
 }
 // Loop to find the duplicate element in the array 
 for (int i=0;i<n-1;i++){
    for (int j=i+1;j<n;j++){
        if(arr[i]==arr[j]){
            printf("Duplicate element : %d ",arr[i]);
        }
    }
 }
 return 0;

}