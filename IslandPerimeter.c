/*

463. Island Perimeter
Easy
Topics
Companies
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.

*/


#include <stddef.h>
#include <stdint.h>




/*
Iterate each row. Check if a number if 0, ie, water.
If land, ignore.
If water,
	Check all "+" perimeter pieces for a piece of land.
		If + piece is out of bounds, ignore.
		If + piece is land, add 1 to perimeter.
		If + piece is water, ignore

Check outer perimeter:
If corner
	
If wall, ad 1
*/
int islandPerimeter(int** grid, int gridSize, int* gridColSize)
{
	int perimeter = 0;
	int rows = gridSize;
	int cols = *gridColSize;

	// Iterate each row 
	int* thisRow;
	for (size_t i = 0; i < rows; i++)
	{
		thisRow = grid[i];

		for (size_t j = 0; j < cols; j++)
		{
			if (0 == thisRow[j])
			{
				// Water found - check + perimeter for a piece of land 
				


			}
		}
	}
}
