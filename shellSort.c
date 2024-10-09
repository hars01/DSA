#include <stdio.h>
void ShellSort(int nums[], int n) 
{
        for(int gap=n/2;gap>0;gap=gap/2)
        {
            for(int i=gap; i<n; i++)
            {
                int temp=nums[i];
                int j=i;
                while(j>gap && nums[j-gap]>temp)
                {
                    nums[j]=nums[j-gap];
                    j=j-gap;
                } 
                nums[j]=temp;
            }
        }
}
void CyclicSort(int nums[], int n)
{
    int i=0,j;
    while(i<n)
    {
        j=nums[i]-1;
        if(nums[i]!=nums[j])
        {
            int t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
        else
        {
            i++;
        }
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
    int arr[] = {2,6,4,3,1,5}; 
    int n = 6; 
    ShellSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 
