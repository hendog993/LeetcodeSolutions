#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>



static size_t getLengthOfCharArray(char* input)
{
	size_t numChars = 0;
	char* thisChar = input;

	while (*thisChar != '\0')
	{
		numChars++;
		thisChar++;
	}

	return numChars;
}




int strStr(char* haystack, char* needle)
{
	/* Get lengths of input strings */
	const size_t haystackLength = getLengthOfCharArray(haystack);
	const size_t needleLength = getLengthOfCharArray(needle);

	if (haystackLength < needleLength)
	{
		return -1;
	}

	size_t numTriesToCompare = haystackLength - needleLength+1;
	char* haystackPtr = haystack;
	int returnVal = -1;

	for (size_t i = 0; i < numTriesToCompare; i++)
	{
		if (0 == memcmp(haystackPtr, needle, needleLength))
		{
			returnVal = i;
			break;
		}
		haystackPtr++;
	}

	return returnVal;

}
