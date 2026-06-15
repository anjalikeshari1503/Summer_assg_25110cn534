#include <stdio.h>
int frequency(int arr[], int n,int key){
    int count =0;
    for (int i=0;i<n;i++){
        if(arr[i]== key){
            count++ ;
        }
    }
    return count;
}
int main (){
int n ; // To store the size of the array 
printf("Enter the size of array:\n");
scanf("%d",&n);
int arr[n];
printf("Enter the elements of array:\n");
for (int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int key;
printf("Enter the element to search:\n");
scanf("%d",&key);
// To calculate the frequency of the element in the array
int result = frequency(arr,n,key);
printf("Frequency of %d is %d.\n",key,result);
    return 0;
} 