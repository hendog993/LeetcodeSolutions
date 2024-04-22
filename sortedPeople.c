/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.




*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>


typedef struct 
{
    int height;
    char * name;
} Person;


/*
Notes
1. Assume namesSize and heightsSize are equal 
2. Return a 2D char array 

*/

int comparePerson( const void * a, const void * b)
{
    Person * pa = (Person*)a;
    Person * pb = (Person*)b;

    int val =  (pa->height) - (pb->height);
    if (val < 0)
    {
        return 1;
    }
    else if (val > 0)
    {
        return -1;
    }
    else 
    {
        return 0;
    }
}

/*
1. Populate a list of Person structs with the input names and heights 
2. Use quicksort to sort the person list based on height 
3. Dynamically create a 2D char array of proper size 
4. Populate the 2D char array, then return a pointer to it (double ptr)
*/
char** sortPeople(char** names, 
                int namesSize, 
                int* heights,
                int heightsSize,
                int* returnSize) 
{

    Person * listOfPeople = malloc(sizeof(Person) * namesSize);

    size_t i;
    for (i = 0; i < namesSize; i++)
    {
        listOfPeople[i].name = names[i];
        listOfPeople[i].height = heights[i];
    }

    qsort(listOfPeople, namesSize, sizeof(Person), comparePerson);

    // Create the result array
    char** result = (char**)malloc(namesSize * sizeof(char*));
    
    // Copy names from sorted Person array to result
    for (int i = 0; i < namesSize; i++) {
        result[i] = listOfPeople[i].name;
    }
    *returnSize = namesSize;
    return result;

}
