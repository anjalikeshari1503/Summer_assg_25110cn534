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
    int sum = 0;
    for(int i=0 ;i<n;i++){
        sum += arr[i];
    }
    printf("Sum of elements of array is %d :\n",sum);
    int avg = sum/n;
    printf("Average of elements of array is %d:\n",avg);
    return 0;

}