#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
/*
|  X
0  0  0  0  1  1  2  3   3  3  3  4  4  4  4

|
0
*/



int removeDuplicates(int* nums, int numsSize)
{

    int32_t* newArray2 = malloc(numsSize * sizeof(int32_t)); // Working array 

    /* Copy the very first element into the working array */
    newArray2[0] = nums[0];

    int32_t numUniqueEntries = 1;
    size_t entriesLeft = numsSize - 1;

    int32_t* resultPointer = &(newArray2[0]);
    int32_t* sourcePointer = nums + 1;
    int32_t sourceNumber;
    int32_t resultNumber;

    while (0 != entriesLeft)
    {
        sourceNumber = *sourcePointer;
        resultNumber = *resultPointer;

        if (resultNumber == sourceNumber)
        {
            ;
        }
        else
        {
            resultPointer++;
            *resultPointer = sourceNumber;
            numUniqueEntries++;
        }

        sourcePointer++;
        entriesLeft--;

    }

    memcpy(nums, newArray2, numUniqueEntries * sizeof(int32_t));
    free(newArray2);
    return numUniqueEntries;

}


void main(void)
{

    int vals[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int32_t numUnique = removeDuplicates(vals, sizeof(vals) / sizeof(int32_t));
    
    printf(" %i unique numbers found: \n", numUnique);
    for (int i = 0; i < numUnique; i++)
    {
        printf(" %i , ", vals[i]);
    }

}
