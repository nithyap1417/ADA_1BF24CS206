#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int Larr[n1];
    int Rarr[n2];
    for(int i=0;i<n1;i++){
        Larr[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        Rarr[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(Larr[i]<=Rarr[j]){
            arr[k]=Larr[i];
            i++;
        }
        else{
            arr[k]=Rarr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=Larr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=Rarr[j];
        j++;
        k++;
    }

}
void mergeSort(int arr[],int l,int r)
{
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,(m+1),r);
        merge(arr,l,m,r);
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
    printf("Unsorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    start=clock();
    mergeSort(arr,0,n-1);
    end=clock();
    printf("\nSorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nTime taken to sort the array is: %f",time_taken);
    return 0;
}


