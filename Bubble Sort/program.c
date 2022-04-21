#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///<summary>Bubble Sort Algorithm</summary>
///<param name="array">Pointer Array to be sorted</param>
///<param name="size">Size of the array</param>
///<returns>Void</returns>
void BubbleSort(int *array, int size) {
    // Initialize Variables
    int i, j, temp;

    // Loop through the array
    for (i = 0; i < size; i++) {
        // Loop through the array again, but stopping 1 ahead of the previous last.
        for (j = 0; j < size - i - 1; j++) {
            
            // If the current element is greater than the next element.
            if (array[j] > array[j + 1]) {

                // Assign the current element(higher number) to a temporary variable.
                temp = array[j];

                // Swap the current element with the next element.
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
    // by allocating the required amount of memory
    // with the length of the data set
    int *data = malloc(dataLength * sizeof(int));

    // Seed the random number generator
    srand(time(NULL));

    // Generate random numbers for the data.
    for(int i = 0; i < dataLength; i++){
        data[i] = rand() % 100;
    }
    
    printf("\n\nFinished Creating Dataset\n\n");

    // Get the stopwatch ready
    clock_t timer;
    timer = clock();

    // Sort the data set
    BubbleSort(data, dataLength);

    // Get Completion Time
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds
    printf("\n\n\nBubble Sort took %f seconds to execute \n", time_taken);


    printf("\n\n\n");
    
    // Free the memory used by the array.
    free(data);
    
    return 0;
}
