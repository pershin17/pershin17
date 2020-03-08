#include <stdio.h>

#define NUM_ROWS 10
#define NUM_COL 10

const int input[NUM_ROWS][NUM_COL] =  { {-26, -25, -19, -4, -2, 36, 69, 82, 88, 89 },
                                        {-37, -26, -14, -13, 22, 40, 66, 72, 73, 94},
                                        {-40, -23, -12, -11, 24, 26, 49, 60, 65, 96},
                                        {-40, -28, -24, -20, -6, 25, 42, 61, 62, 80},
                                        {-31, 8, 42, 43, 46, 60, 78, 80, 84, 85},
                                        {-48, -36, -32, -24, -12, -2, 33, 63, 67, 80},
                                        {-42, -11, -6, 23, 48, 50, 52, 66, 70, 96},
                                        {-31, -30, -21, -15, 20, 25, 32, 69, 78, 89},
                                        {-42, -18, 22, 24, 49, 57, 59, 63, 83, 88},
                                        {-40, -33, -30, -9, -5, 23, 24, 36, 65, 87} };

const int values[NUM_ROWS] = { 88, -26, 97, -40, 85, 68, 48, 25, 50, 36 };
const int results[NUM_ROWS] = { 8, 1, -1, 0, 9, -1, 4, 5, -1, 7 };

int BinarySearch(int value, const int* array)
{
	int size = NUM_COL;
	int low = 0;
	int high = size - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (value == array[mid])
		{
			return mid;
		}
		else if (value > array[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}		
	}
	return -1;
}

int main()
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        int res = BinarySearch(values[i], input[i]);
        printf("Expected: %d\tGot: %d\t", results[i], res);

        if (res == results[i])
            printf("+\n");
        else
            printf("THE RESULT IS WRONG!!!\n");
    }
    return 0;
}