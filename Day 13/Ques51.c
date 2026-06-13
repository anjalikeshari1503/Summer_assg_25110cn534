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
    // To  find maximum element in the array
    int max =arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max =arr[i];        }
    }
    printf("The maximum element in the array is %d \n",max);
    // To find the minimum element in the array
    int min =arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min =arr[i];        }
    }
    printf("The minimum element in the array is %d \n",min);
    return 0;

}