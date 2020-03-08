#include <stdio.h>
#include <string.h>

#define NUM_ROWS 10
#define NUM_COL 10

const int input[NUM_ROWS][NUM_COL] =  { { -25, -26, 36, 69, 82, -19, 89, 88, -4, -2 },
                                        { -13, 22, 72, 40, -37, 73, 66, -14, -26, 94 },
                                        { -11, 24, -23, -12, -40, 96, 60, 49, 65, 26 },
                                        { -6, 61, 25, 62, 42, -20, 80, -28, -24, -40 },
                                        { 8, 85, -31, 80, 43, 78, 42, 60, 46, 84 },
                                        { -24, -36, -48, 33, 63, 67, -12, -32, 80, -2 },
                                        { 23, -6, 66, -11, -42, 96, 70, 48, 50, 52 },
                                        { 20, 25, 89, -21, -31, 69, 78, -15, 32, -30 },
                                        { 24, 63, 49, -18, 22, 88, -42, 57, 83, 59 },
                                        { 23, -40, 65, -9, 87, -33, -5, 36, 24, -30 } };

const int output[NUM_ROWS][NUM_COL] = { {-26, -25, -19, -4, -2, 36, 69, 82, 88, 89 },
                                        {-37, -26, -14, -13, 22, 40, 66, 72, 73, 94},
                                        {-40, -23, -12, -11, 24, 26, 49, 60, 65, 96},
                                        {-40, -28, -24, -20, -6, 25, 42, 61, 62, 80},
                                        {-31, 8, 42, 43, 46, 60, 78, 80, 84, 85},
                                        {-48, -36, -32, -24, -12, -2, 33, 63, 67, 80},
                                        {-42, -11, -6, 23, 48, 50, 52, 66, 70, 96},
                                        {-31, -30, -21, -15, 20, 25, 32, 69, 78, 89},
                                        {-42, -18, 22, 24, 49, 57, 59, 63, 83, 88},
                                        {-40, -33, -30, -9, -5, 23, 24, 36, 65, 87} };

int* BubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				int temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
	return array;
}

int compare_arrays(const int* A, const int* B, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (A[i] != B[i])
            return -1;
    }
    return 0;
}

void print_array(const int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d%s", array[i], (i==len-1)?"\n":", ");
	}
}

int main()
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        int temp[NUM_COL];
        memcpy(temp, input[i], sizeof(int)*NUM_COL);

        BubbleSort(temp, NUM_COL);

        printf("Input:\t\t"); print_array(input[i], NUM_COL);
        printf("Expected:\t"); print_array(output[i], NUM_COL);
        printf("Got:\t\t"); print_array(temp, NUM_COL);

        if (compare_arrays(output[i], temp, NUM_COL) != 0)
            printf("THE RESULT IS WRONG!!!\n");
        printf("\n");
    }
    return 0;
}