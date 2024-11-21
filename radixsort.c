#include <stdio.h>
#include <stdbool.h>
#define ARRAY_UTIL_IMPLEMENTATION
#include "arrayutil.h"

void _countingSort(int size, int* arr, int place){
    int count[10] = {0};                                       // Initialize a count array to store counts
    int aux[size];                                             // Auxillary array to hold the sorted array for the given place

    for(int i = 0; i < size; i++){                             // Run a loop to count the occurence of the digit in the given place
        count[(arr[i] / place) % 10]++;
    }

    for(int i = 1; i < 10; i++){                               // Run a loop to calculate the max index of each digit for aux array
        count[i] += count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--){                        // Run a loop from back to put the array element corresponding the given count_index in the aux array
        aux[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    copyArray(size, arr, aux);                                 // Copy the auxillary to original array back
}

void radixSort(int size, int* arr){
    int max = maxInArray(size, arr);                           // Find the max element in array

    for(int place = 1; max/place > 0; place *= 10){            // Run a loop to sort the array for each place
        _countingSort(size, arr, place);
    }
}

int main(){
    int size = 10000;
    int arr[size];
    int lowerbound = 1;
    int upperbound = 1000*1000;

    populateWithDummyData(arr, size, lowerbound, upperbound);    
    double elapsed = calculateRuntimeSorting(radixSort, size, arr);
    printf("Time Taken to Sort : %.2f ms\n", elapsed * 1000);
}