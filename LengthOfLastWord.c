/*

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

*/




const char escapeCharacter = '\0';

typedef enum 
{
    INITIAL,
    SPACE_ENCOUNTERED,
    WITHIN_WORD,
} TraverseState ;


int lengthOfLastWord(char* s) 
{
    size_t currentIndex = 0;
    char thisCharacter;
    int currentWordLength = 0;
    bool isStringEnded = false;
    TraverseState state = WITHIN_WORD;

    while (false == isStringEnded)
    {
        thisCharacter = s[currentIndex];

        if (escapeCharacter == thisCharacter)
        {
            break;
        }
        currentIndex++;

        switch (state)
        {
            case SPACE_ENCOUNTERED:
                if (thisCharacter != ' ')
                {
                    currentWordLength = 1;
                    state = WITHIN_WORD;
                }

                break;

            case WITHIN_WORD:

                if (thisCharacter != ' ')
                {
                    currentWordLength++;
                }

                else if (thisCharacter == ' ')
                {
                    state = SPACE_ENCOUNTERED;
                }

                break;
        }
    }

    return currentWordLength;

}
