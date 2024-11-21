#include <stdio.h>
#include <stdbool.h>
#define ARRAY_UTIL_IMPLEMENTATION
#include "arrayutil.h"

void selectionSort(int size, int* arr){
    // ALGORITHM EXPLAINED

    // Start a loop to traverse the array from 0 to size-1
    for(int i = 0; i < size; ++i){
        // This process is to find the minimum element from the unsorted array, given that unsorted starts from i+1 to size - 1
        int* minIndex = arr + i;
        for(int j = i + 1; j < size; ++j){
            if(*minIndex > *(arr + j)){
                minIndex = arr + j;
            }
        }
        // Swap the minimum element found with the first index of unsorted array, and mark it sorted
        swap(minIndex, arr + i);
    }
}

int main(){
    int size = 10000;
    int arr[size];
    int lowerbound = 1;
    int upperbound = 1000*1000;

    populateWithDummyData(arr, size, lowerbound, upperbound);
    double elapsed = calculateRuntimeSorting(selectionSort, size, arr);
    printf("Time Taken to Sort : %.2f ms\n", elapsed * 1000);
}