#include<stdio.h>
int main()
{
    int n,i,sum=0;
    int *ptr;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    ptr=arr;
    for(i=0;i<n;i++)
    {
        sum=sum+*ptr;
        ptr++;

    }
    printf("%d",sum);
    return 0;
}