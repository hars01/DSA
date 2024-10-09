#include <stdio.h> 
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
int selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    {
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
           if(min_idx != i) 
            swap(&arr[min_idx], &arr[i]); 
    } 
} 
int function(int nums[], int n)
{
       int temp[n];
       for(int i=0; i<n; i++)
        {
            temp[i]=nums[i];
        }
       selectionSort(temp,n);
        int s=-1,e=-1;
       for(int i=0; i<n; i++)
       {
         if(nums[i]!=temp[i]&&s==-1)
         s=i;
         if(nums[n-i-1]!=temp[n-i-1]&&e==-1)
         e=n-i-1;
       }
       printf("%d : %d",s,e);
    
}
int function2(int arr[],int n)
{
    int l=0,h=n-1;
    while(l<h && arr[l]<arr[l+1])
    l++;
    while(h>l && arr[h]>a[h-1])
    h--;
    for(int i=l;i<=n;i++)
    {
        sub_min=arr[l];
        sub_max=arr[l];
        sub_min=min(sum_min,arr[i]);
        sub_max=max(sub_max,arr[i]);
    }
    while(l>0 && arr[l-1]>min)
       l--;
    while(h<n-1 && arr[h+1]>max)
       h++;
    return h-l+1;   
    }
}
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
int main() 
{ 
    int arr[] ={2,6,4,8,10,9,15}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    function(arr,n);
} 