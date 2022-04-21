#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///<summary>Bubble Sort Algorithm</summary>
///<param name="array">Pointer Array to be sorted</param>
///<param name="size">Size of the array</param>
///<returns>Void</returns>
void sortArray(int *array, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


int main(){
    // Length of the data set
    int dataLength;

    system("clear");

    // Get user input for the length of the data set
    printf("\nPlease Enter How many numbers you want sorted: ");
    scanf("%d", &dataLength);

    // Initialize data set as an array of integers 
    // with the length of the data set
    int data[dataLength];

    // Seed the random number generator
    srand(time(NULL));

    // Generate random numbers for the data.
    for(int i = 0; i < dataLength; i++){
        data[i] = rand() % 100;
    }

    // Print the unsorted data set
    printf("\n\nUnsorted Data:\n");
    for(int i = 0; i < dataLength; i++){
        printf("%d ", data[i]);
    }

    // Sort the data set
    sortArray(data, dataLength);

    // Print the sorted data set
    printf("\n\n\nSorted Data:\n");
    for(int i = 0; i < dataLength; i++){
        printf("%d ", data[i]);
    }

    printf("\n\n\n");
    return 0;
}
