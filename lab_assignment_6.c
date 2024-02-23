#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value)
{
    if (low > high) {
        return -1; // Base case: value not found
    }

    int mid = low + (high - low) / 2; // Find the mid index 

    if (numbers[mid] == value) {
        return mid; // Value found
    }
    else if (numbers[mid] > value) {
        return search(numbers, low, mid - 1, value); // Search in the left half
    }
    else {
        return search(numbers, mid + 1, high, value); // Search in the right half
    }
}


void printArray(int numbers[], int sz)
{
    int i;
    printf("Number array : ");
    for (i = 0; i < sz; ++i)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void)
{
    int i, numInputs;
    float average;
    int value;
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt", "r");

    if (inFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *) malloc(countOfNums * sizeof(int));
        if (numArray == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        average = 0;
        for (i = 0; i < countOfNums; i++)
        {
            fscanf(inFile, " %d", &numArray[i]);
            average += numArray[i];
        }

        printArray(numArray, countOfNums);
        value = (int)(average / countOfNums); // Ensuring value is an integer
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0)
        {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        }
        else
        {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}