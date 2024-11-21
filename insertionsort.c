#include <stdio.h>
#define ARRAY_UTIL_IMPLEMENTATION
#include "arrayutil.h"

void insertionSort(int size, int* arr){

    // ALGORITHM EXPLAINED
    for(int i = 1; i < size; ++i){                  // Start a loop from 1 to size-1
        if(arr[i] < arr[i-1]){                      // Check if the the current item is less than its preceeding item
            for(int j = i; j > 0; --j){             // If true, start another loop to backtrack from i to 0
                if(arr[j] < arr[j - 1]){            // Now check if the current item is less than the succeeding item or not
                    swap(&arr[j], &arr[j - 1]);     // If true, swap them
                }
            }
        }
    }
}

int main(){
    int size = 10000;
    int arr[size];
    int lowerbound = 1;
    int upperbound = 1000*1000;

    populateWithDummyData(arr, size, lowerbound, upperbound);
    double elapsed = calculateRuntimeSorting(insertionSort, size, arr);
    printf("Time Taken to Sort : %.2f ms\n", elapsed * 1000);
}