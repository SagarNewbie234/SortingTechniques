#include <stdio.h>
#include <stdbool.h>
#define ARRAY_UTIL_IMPLEMENTATION
#include "arrayutil.h"

void merge(int size, int mid, int* left, int* right, int* arr){
    // Get the sizes of left half and right half arrays
    int lsize = mid;
    int rsize = size - mid;
    // Initialize counters
    int i = 0, j = 0, k = 0;

    // Run a loop while the counters i and j reach their limit
    while(i < lsize || j < rsize){
        // Check if the left half is exhausted or not, if yes copy all the remaining elements in right half to original array
        if(i == lsize && j < rsize){
            arr[k] = right[j++];
        }
        // Check if the right half is exhausted or not, if yes copy all the remaining elements in left half to original array
        else if(j == rsize && i < lsize){
            arr[k] = left[i++];
        }
        // If neither is true, i.e. both right half and left half are not exhausted, follow the nested conditions
        else{
            // If the unused element in left half is less than unused element in right half, copy the left half element
            if(left[i] < right[i]){
                arr[k] = left[i++];
            }
            // Otherwise, copy the right half element
            else{
                arr[k] = right[j++];
            }
        }
        k++;
    }
}

void mergeSort(int size, int* arr){
    // Base Condition : If there is only one item in array return
    if(size == 1){
        return;
    }

    // Calculate the index of middlemost element
    int mid = size / 2;
    // Split the original array in two divisions bisected through mid
    int left[mid];
    int right[size - mid];

    // Copy the array elements in first half
    for(int i = 0; i < mid; i++){
        left[i] = arr[i];
    }

    // Copy the array elements in second half
    for(int i = mid; i < size; i++){
        right[i - mid] = arr[i];
    }

    // Individually sort the first half
    mergeSort(mid, left);
    // Individually sort the second half
    mergeSort(size - mid, right);
    // Merge back the sorted portions into the original array
    merge(size, mid, left, right, arr);
}

int main(){
    int size = 10000;
    int arr[size];
    int lowerbound = 1;
    int upperbound = 1000*1000;

    populateWithDummyData(arr, size, lowerbound, upperbound);    
    double elapsed = calculateRuntimeSorting(mergeSort, size, arr);
    printf("Time Taken to Sort : %.2f ms\n", elapsed * 1000);
}