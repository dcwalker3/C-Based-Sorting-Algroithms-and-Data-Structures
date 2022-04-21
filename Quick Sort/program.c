#include <stdlib.h>
#include <stdio.h>
#include <time.h>


///<summary> Function to swap two elements of the passed array </summary>
///<param name="array"> The array to be sorted </param>
///<param name="index1"> The first of the indexes to be swapped </param>
///<param name="index2"> The second of the indexes to be swapped </param>
void swap(int *array, int index1, int index2){
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

///<summary> Function to partition the array around a pivot </summary>
///<param name="array"> The array to be sorted </param>
///<param name="start"> The start of the partition </param>
///<param name="end"> The end of the partition </param>
///<returns> The index of the pivot </returns>
int partition(int *array, int start, int end){
    // Set the values we will use to pivot the array.
    int pivotIndex = start;
    int pivotValue = array[end];

    // Loop through the array and swap the values 
    // that are less than the pivot value.
    for(int i = start; i < end; i++){
        if(array[i] < pivotValue) {
            swap(array, i, pivotIndex);

            pivotIndex++;
        }
    }

    // Swap th pivotIndex with the end value, so when we return
    // the pivotIndex will be the index of the pivot index it will be 
    // at the correct position.
    // We moved the pivotValue to the end of the array, so we need to swap
    // it with the end value
    swap(array, pivotIndex, end);
    return pivotIndex;
}

///<summary> Function to sort the array using the quick sort algorithm</summary>
///<param name="array"> The array to be sorted </param>
///<param name="start"> The start of the partition </param>
///<param name="end"> The end of the partition </param>
void quickSort(int *array, int start, int end){
    // If the start is greater than or equal to the end, we have
    // to stop, because that means the array is sorted.
    // It has gone from both sides of the pivot all the way to the middle.
    if(start >= end){
        return;
    }

    // Get the pivot index
    int index = partition(array, start, end);
    
    // Recursively quick sort the left side of the array 
    // and the right side of the array by changing start and end
    quickSort(array, start, index-1);
    quickSort(array, index+1, end);

}

int main(){
    // Length our dataset will be.
    int dataLength;
    printf("\nEnter the length of the data: ");
    scanf("%d", &dataLength);


    // Allocate the memory for the array(important for extremely large arrays).
    int *data = malloc(dataLength * sizeof(int));
    
    // Seed the random number generator.
    srand(time(NULL));

    // Fill the array with random numbers.
    for(int i = 0; i < dataLength; i++){
        data[i] = rand() % 100;
    }

    printf("\n\nFinished Createing data set:\n");

    // Get Stopwatch ready.
    clock_t timer;
    timer = clock();

    // Sort the data set
    quickSort(data, 0, dataLength - 1);
    
    // Get the completion time of quick sort.
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds
    printf("\n\n\nQuick Sort took %f seconds to execute \n", time_taken);

    // Free the memory used by the array.      
    free(data);

    // Return 0 to the operating system, indicating the program ran successfully.
    printf("\n");
    return 0;
}