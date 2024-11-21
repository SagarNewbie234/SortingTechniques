#include <stdio.h>
#include <stdbool.h>
#define ARRAY_UTIL_IMPLEMENTATION
#include "arrayutil.h"

// Sorting Algorithms

// Bubble Sort
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
            if(*(arr + j) > *(arr + j + 1)){
                // If true, swap them and set swapped to true
                swap(arr + j, arr + j + 1);
                swapped = true;
            }
            // The greatest element will shift to end, before the next greatest element
            // The swapped will remain false, if no swaps takes place, i.e. the array is sorted
        }
        if(!swapped) break; // break the loop if array is already sorted
    }

}

// Insertion Sort
void insertionSort(int size, int* arr){
    // ALGORITHM EXPLAINED

    // Start a loop from 1 to size -1
    for(int i = 1; i < size; ++i){
        // Check if the the current item is less than its previous item
        if(*(arr + i - 1) > *(arr + i)){
            // If true, start another loop to backtrack from i to 0
            for(int j = i; j >= 0; --j){
                // Now check if the current item is less than the previous item or not
                if(*(arr + j) > *(arr + j + 1)){
                    // If true, swap them
                    swap(arr + j, arr + j + 1);
                }
                // Continue until the item has reached its correct place
            }
        }
        // Continue until the complete array has been traversed
    }
}

// Selection Sort
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

// Merge Sort
void merge(int size, int mid, int* left, int* right, int* arr){
    int lsize = mid;
    int rsize = size - mid;
    int i = 0, j = 0, k = 0;

    while(i < lsize || j < rsize){
        if(i == lsize && j < rsize){
            *(arr + k) = *(right + j);
            j++;
        }else if(j == rsize && i < lsize){
            *(arr + k) = *(left + i);
            i++;
        }else{
            if(*(left + i) < *(right + j)){
                *(arr + k) = *(left + i);
                i++;
            }else{
                *(arr + k) = *(right + j);
                j++;
            }
        }
        k++;
    }
}

void mergeSort(int size, int* arr){
    if(size == 1){
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for(int i = 0; i < mid; i++){
        left[i] = *(arr + i);
    }

    for(int i = mid; i < size; i++){
        right[i - mid] = *(arr + i);
    }

    mergeSort(mid, left);
    mergeSort(size - mid, right);
    merge(size, mid, left, right, arr);
}

// Quick Sort
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

// Shell Sort
void shellSort(int size, int* arr){
    for(int gap = size/2; gap > 0; gap /= 2){           // Initialize the gap from half the array size, and reduce it by half in every iteration
        for(int i = gap; i < size; i++){           // Start a loop from this gap variable and select the corresponding pairs at the specific gap
            int j = i;                                  // Initialize a second variable j with i
            while(j >= gap && arr[j] < arr[j - gap]){   // Run a loop while j is greater than or equals to gap, and element at j is less than element at j - gap
                swap(arr + j, arr + j - gap);           // Swap them if both are true
                j -= gap;                               // Decrement the j by gap
            }
        }
    }
}

// Radix Sort
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
    int size = 50000;
    int arr1[size], arr2[size], arr3[size], arr4[size], arr5[size], arr6[size], arr7[size];
    int lowerbound = 1;
    int upperbound = 1000*1000;

    populateWithDummyData(arr1, size, lowerbound, upperbound);
    copyArray(size, arr2, arr1);
    copyArray(size, arr3, arr1);
    copyArray(size, arr4, arr1);
    copyArray(size, arr5, arr1);
    copyArray(size, arr6, arr1);
    copyArray(size, arr7, arr1);

    double bubbleTime, insertionTime, selectionTime, mergeTime, quickTime, shellTime, radixTime;

    bubbleTime = calculateRuntimeSorting(bubbleSort, size, arr1);
    insertionTime = calculateRuntimeSorting(insertionSort, size, arr2);
    selectionTime = calculateRuntimeSorting(selectionSort, size, arr3);
    mergeTime = calculateRuntimeSorting(mergeSort, size, arr4);
    quickTime = calculateRuntimeSorting(quickSort, size, arr5);
    shellTime = calculateRuntimeSorting(shellSort, size, arr6);
    radixTime = calculateRuntimeSorting(radixSort, size, arr7);

    printf("Bubble Sort : %.2f ms\n", bubbleTime * 1000);
    printf("Insertion Sort : %.2f ms\n", insertionTime * 1000);
    printf("Selection Sort : %.2f ms\n", selectionTime * 1000);
    printf("Merge Sort : %.2f ms\n", mergeTime * 1000);
    printf("Quick Sort : %.2f ms\n", quickTime * 1000);
    printf("Shell Sort : %.2f ms\n", shellTime * 1000);
    printf("Radix Sort : %.2f ms\n", radixTime * 1000);
}