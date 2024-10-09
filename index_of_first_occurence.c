#include <stdio.h>
int b(int arr[],int l,int h, int k)
{
    if(h>l)
    return -1;
    int mid;
    mid=(l+h)/2;
    if(arr[mid]<k)
    return b(arr,mid+1,h,k);
    else if(arr[mid]>k)
    return b(arr,l,mid-1,k);
    else 
        if(mid==0 || arr[mid-1] != arr[mid])
        return  mid;
        else
        return b(arr,l,mid-1,k);
}
void main() {
    int arr[]={10,20,20,30,40};
    int l=0,h=5,k=20;
    printf("%d",b(arr,h,l,k));
}
