 #include<stdio.h>
int main()
{
    int a[100],n,i,j,k,key,mid,pos,flag=0;;
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if (a[j]>a[j+1])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
    printf("the sorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("Enter the element to be seached: ");
    scanf("%d",&key);
    i=0;
    j=n-1;
    while(i<=j)
    {
        mid=(i+j)/2;
        if(a[mid]==key)
        {
            flag=1;
            pos=i+1;
            break;
        }
        else if(a[mid]>key)
        {
            j=mid-1;
        }
        else if(a[mid]<key)
        {
            i=mid+1;
        }
    }
    if(flag==1)
    {
        printf("\nElement found at %d position",pos);
    }
    else{
        printf("\nElement not found!");
    }
    return 0;
}