 #include<stdio.h>
 int main()
 {
    int a[100],n,i,sum=0,exp_sum,k;
    printf("enter the size of array:");
    scanf("%d",&n);
    exp_sum=n*(n+1)/2;
    printf("enter %d elements",n-1);
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    k=exp_sum-sum;
    printf("missing number is %d",k);
    return 0;
 }