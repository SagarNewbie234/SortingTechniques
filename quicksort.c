#include <stdio.h>
#include <stdbool.h>
#define ARRAY_UTIL_IMPLEMENTATION
#include "arrayutil.h"

int partition(int size, int* arr){
    int pivot = *(arr + size - 1);
    int partitionIndex = 0;
    for(int i = 0; i < size; i++){
        if(*(arr + i) <= pivot){
            swap(arr + partitionIndex, arr + i);
            partitionIndex++;
        }
    }

    return partitionIndex - 1; 
}

void quickSort(int size, int* arr){
    if(size > 1){
        int pivotIndex = partition(size, arr);
        quickSort(pivotIndex, arr);
        quickSort(size - pivotIndex - 1, arr + pivotIndex + 1);
    }
}

int main(){
    int size = 50000;
    int arr[size];
    int lowerbound = 1;
    int upperbound = 1000*1000;

    populateWithDummyData(arr, size, lowerbound, upperbound);    
    double elapsed = calculateRuntimeSorting(quickSort, size, arr);
    printf("Time Taken to Sort : %.2f ms\n", elapsed * 1000);
}