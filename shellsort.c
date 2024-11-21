#include <stdio.h>
#include <stdbool.h>
#define ARRAY_UTIL_IMPLEMENTATION
#include "arrayutil.h"

void shellSort(int size, int* arr){
    for(int gap = size/2; gap > 0; gap /= 2){           // Initialize the gap from half the array size, and reduce it by half in every iteration
        for(int i = gap; i < size; i++){                // Start a loop from this gap variable and select the corresponding pairs at the specific gap
            int j = i;                                  // Initialize a second variable j with i
            while(j >= gap && arr[j] < arr[j - gap]){   // Run a loop while j is greater than or equals to gap, and element at j is less than element at j - gap
                swap(arr + j, arr + j - gap);           // Swap them if both are true
                j -= gap;                               // Decrement the j by gap
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
    double elapsed = calculateRuntimeSorting(shellSort, size, arr);
    printf("Time Taken to Sort : %.2f ms\n", elapsed * 1000);
}