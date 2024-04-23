#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct
{
	int32_t value;
	size_t numOccurrances;
} evenNumberStruct ;


int32_t compareEvenNumberStructs(const void* a, const void* b)
{
	evenNumberStruct* aVal = (evenNumberStruct*)a;
	evenNumberStruct* bVal = (evenNumberStruct*)b;

	int32_t diff = aVal->numOccurrances - bVal->numOccurrances;

	if (diff < 0)
	{
		return 1;
	}
	else if (diff > 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


/*
* Description:
*		1. Iterate the entire list of input numbers 
*		2. When an even number is found
*			- Store the number itself in a 2D array 
*			- Research the input array for matches, and if a match is found, increment the 2D array's # counter, then set the value to 1
*		3. Find the final answer in the 2D array 
* 
*/
int32_t mostFrequentEven(int32_t * nums, size_t numsSize) 
{

	size_t evenCounter = 0;
	evenNumberStruct* result = malloc(sizeof(evenNumberStruct) * numsSize); // TODO this wastes memory! 

	int32_t thisNumber;
	evenNumberStruct* thisEvenNumber = result;
	for (size_t i = 0; i < numsSize; i++)
	{
		thisNumber = nums[i];
		if (0 == (thisNumber % 2))
		{
			/* An even number is found */
			thisEvenNumber->value = thisNumber;
			thisEvenNumber->numOccurrances = 0; // reset to known value 

			/* Iterate the newNums list to find all occurrances - if an occurrance is found, increment the numOccurrances, then set the value to zero */
			for (size_t j = 0; j < numsSize; j++)
			{
				if (thisNumber == nums[j])
				{
					thisEvenNumber->numOccurrances++;
					nums[j] = 1;
				}
			}
			thisEvenNumber++;
			evenCounter++;
		}

	}
	

	/* Find which even number has the most occurrances - if there is a tie, choose the smallest */
	if (0 == evenCounter)
	{
		return -1;
	}


	evenNumberStruct* updatedEvenNumsStruct = malloc(sizeof(evenNumberStruct) * evenCounter);
	memcpy(updatedEvenNumsStruct, result, sizeof(evenNumberStruct) * evenCounter);
	free(result);

	qsort(updatedEvenNumsStruct, evenCounter, sizeof(evenNumberStruct), compareEvenNumberStructs);

	if (evenCounter > 1)
	{
		evenNumberStruct evenNumber1 = updatedEvenNumsStruct[0];
		evenNumberStruct evenNumber2 = updatedEvenNumsStruct[1];

		if (evenNumber1.numOccurrances == evenNumber2.numOccurrances)
		{
			/* Return minimum value */
			int32_t evenValue1 = evenNumber1.value;
			int32_t evenValue2 = evenNumber2.value;
			return min(evenValue1, evenValue2);
		}

		return evenNumber1.value;


	}

	else
	{
		return updatedEvenNumsStruct[0].value;
	}

	return 1;

}
