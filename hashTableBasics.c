#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>


#define TOTAL_NUM_CHARS 26 

int32_t frequency[TOTAL_NUM_CHARS];



static size_t getCharArrayLength(char* input)
{
	size_t numCharsInString = 0;
	char* thisCharacter = input;
	while (*thisCharacter != '\0')
	{
		numCharsInString++;
		thisCharacter++;
	}
	return numCharsInString;
}


int32_t hashFunction(char c)
{
	return (c - 'a');
}


int32_t countFrequnecy(char* input)
{
	/* Get length of input string */
	size_t numCharsInString = getCharArrayLength(input);

	for (size_t i = 0; i < numCharsInString; i++)
	{
		int32_t index = hashFunction(input[i]);
		frequency[index]++;
	}

	/* Print out hash result */
	char startChar = 'a';
	for (size_t j = 0; j < TOTAL_NUM_CHARS; j++)
	{
		printf(" %c  :  %i  \n", startChar, frequency[j]);
		startChar++;
	}
	return 0;
}


void main(void)
{
	char* testString = "asdfasdf;lkj;lkjasdftestWordasdflkwjenlsdkfj";
	countFrequnecy(testString);
	int32_t val = testHashFunction("abcdef");


	return;
}
