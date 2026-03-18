#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(i<=j){
        if(arr[i]<pivot){
            i++;
        }
        else{
            if(arr[j]>pivot){
                j--;
            }
            else{
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[],int low,int high)
{
    if(low<high){
        int pivotIndex=partition(arr,low,high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}

int main()
{
    int n;
    clock_t start, end;
    double time_taken;
    printf("Enter Size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array Elements: \n");
    for(int i=0;i<n;i++){
        arr[i]=rand();
    }
    start=clock();
    quickSort(arr,0,n-1);
    end=clock();
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nTime taken to sort the array is: %f",time_taken);
    return 0;
}




