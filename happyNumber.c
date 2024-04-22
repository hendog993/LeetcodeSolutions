/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1
*/


#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

bool isHappy(int32_t x)
{
	size_t numLoops = 0;

	int32_t number = x;

	while (true)
	{
		/* Find the number of digits in a number */
		bool areDigitsOver = false;
		size_t numDigits = 1;
		int32_t divisor = 10;
		while (false == areDigitsOver)
		{
			if (number == (number % divisor))
			{
				areDigitsOver = true;
			}
			else
			{
				divisor *= 10;
				numDigits++;
			}
		}

		/* Compute the sum of the squares of the input number  */
		int32_t sumOfSquares = 0;
		while (0 != numDigits)
		{
			int32_t rightMostDigit = number % 10;
			sumOfSquares += pow(rightMostDigit, 2);
			number -= rightMostDigit;
			number /= 10;
			numDigits--;
		}

		if (1 == sumOfSquares)
		{
			return true;
		}

		numLoops++;
		if (numLoops > 10000)
		{
			return false;
		}
		number = sumOfSquares;

	}
	
	

}


void main(void)
{
	isHappy(19);
	isHappy(2);
}
