#include <stdio.h>
#include <string.h>

void printArray(int size, char arr[size][25]){
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%s", arr[i]);

        if(i != size - 1) printf(", ");
    }
    printf("]\n");
}

int longestWordSize(int size, char arr[size][25]){
    int maxWordSize = 0, wordSize;
    for(int i = 0; i < size; i++){
        wordSize = 0;
        for(int j = 0; arr[i][j] != '\0'; j++){
            wordSize++;
        }
        if(wordSize > maxWordSize) maxWordSize = wordSize;
    }
    return maxWordSize;
}

char toLowerCase(char c){
    if(c >= 'A' && c <= 'Z'){
        return c + 32;
    }
}

void _countingSort(int size, char arr[size][25], int letter){
    int count[128] = {0};                                       // Initialize a count array to store counts
    char aux[size][25];                            // Auxillary array to hold the sorted array for the given place

    for(int i = 0; i < size; i++){                              // Run a loop to count the occurence of the digit in the given place
        count[toLowerCase(arr[i][letter])]++;
    }

    for(int i = 1; i < 128; i++){                                // Run a loop to calculate the max index of each digit for aux array
        count[i] += count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--){                        // Run a loop from back to put the array element corresponding the given count_index in the aux array
        strcpy(aux[count[toLowerCase(arr[i][letter])] - 1], arr[i]);
        count[toLowerCase(arr[i][letter])]--;
    }

    for(int i = 0; i < size; i++){
        strcpy(arr[i], aux[i]);
    }
}

void radixSort(int size, char arr[size][25]){
    // int minWordLength = shortestWordSize(size, arr);
    int maxWordLength = longestWordSize(size, arr);

    for(int letter = maxWordLength - 1; letter >= 0; letter--){
        _countingSort(size, arr, letter);
    }
}

int main(){
    char names[][25] = {"Alpha", "Beta", "Gamma", "Delta", "Omega", "Ashton", "Boulevard", "Tau", "Rick", "Captcha", "Cecil"};
    int size = sizeof(names)/(sizeof(char) * 25);

    radixSort(size, names);
    printArray(size, names);
}