#include <stdio.h>
#include <stdbool.h>
#define ARRAY_UTIL_IMPLEMENTATION
#include "arrayutil.h"

void bubbleSort(int size, int* arr){
    bool swapped;

    // ALGORITHM EXPLAINED

    // Start a loop from last index size - 1 upto 0
    for(int i = size - 1; i >= 0; i--){
        // Set the swapped flag to false;
        swapped = false;
        // Start another loop from 0 to i
        for(int j = 0; j < i; j++){
            // Check if the current item is greater than the next item
            if(arr[j] > arr[j+1]){
                // If true, swap them and set swapped to true
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
            // The greatest element will shift to end, before the next greatest element
            // The swapped will remain false, if no swaps takes place, i.e. the array is sorted
        }
        if(!swapped) break; // break the loop if array is already sorted
    }

}

int main(){
    // Sample Size 10000
    int size = 10000;
    int arr[size];
    int lowerbound = 1;
    int upperbound = 1000*1000;

    populateWithDummyData(arr, size, lowerbound, upperbound);    
    double elapsed = calculateRuntimeSorting(bubbleSort, size, arr);
    printf("Time Taken to Sort : %.2f ms\n", elapsed * 1000);
}