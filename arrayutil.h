#ifndef __ARRAY_UTIL_H__
#define __ARRAY_UTIL_H__

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int _generateRandom(int upperbound, int lowerbound);
void populateWithDummyData(int* arr, int size, int upperbound, int lowerbound);
void swap(int* a, int* b);
void printArray(int size, int* arr);
double calculateRuntimeSorting(void (*func)(int, int*), int size, int* arr);
void copyArray(int size, int* dest, int* src);
int maxInArray(int size, int* arr);

#ifdef ARRAY_UTIL_IMPLEMENTATION

int _generateRandom(int upperbound, int lowerbound){
    int data = rand() % (upperbound - lowerbound + 1) + lowerbound;
    return data;
}

void populateWithDummyData(int* arr, int size, int upperbound, int lowerbound){
    srand(time(0));

    for(int i = 0; i < size; ++i){
        *(arr + i) = _generateRandom(upperbound, lowerbound);
    }
}

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void printArray(int size, int* arr){
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%d", *(arr + i));

        if(i != size - 1) printf(", ");
    }
    printf("]\n");
}

double calculateRuntimeSorting(void (*func)(int, int*), int size, int* arr){
    clock_t start, end; // clock variables
    start = clock(); // Start the clock
    func(size, arr); // Calls the function to execute the process
    end = clock(); // end the clock
    return (double) (end - start) / CLOCKS_PER_SEC; // returns the time elapsed in double format
}

void copyArray(int size, int* dest, int* src){
    for(int i = 0; i < size; i++){
        *(dest + i) = *(src + i);
    }
}

int maxInArray(int size, int* arr){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

#endif
#endif