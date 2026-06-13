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
    int even_count =0 ,odd_count =0;
    for(int i=0;i<n;i++){
        if(arr[i]%2 ==0){
            even_count++ ;
        }
        else {
            odd_count++ ;
        }

    }
    printf("The number of even elements in the array is %d. \n",even_count);
    printf("The number of odd elements in the array is %d. \n",odd_count);
    return 0;
}