#include <stdio.h>
#include <stdlib.h>

int Minor(int** matrix, int size, int k);

int Determinant(int** matrix, int size)
{
	if (size == 2)
	{
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += ((i % 2 == 0)? 1 : -1) * matrix[i][0] * Minor(matrix, size, i);
	}
	return sum;
}

int Minor(int** matrix, int size, int k)
{
	int m = 0;

	int** mtx = new int*[size - 1];
	for (int i = 0; i < size; i++)
	{
		if (i == k) continue;

		int n = 0;
		mtx[m] = new int[size - 1];
		for (int j = 1; j < size; j++)
		{
			mtx[m][n++] = matrix[i][j];
		}
		m++;
	}

	int temp = Determinant(mtx, size - 1);

	for (int i = 0; i < size - 1; i++)
	{
		delete[] mtx[i];
	}
	delete[] mtx;

	return temp;
}


int main()
{
    // Test #1
    int size = 3;
    int **matrix = new int*[size];

    int r1[] = { 1, 2, 3 };
	int r2[] = { 4, 5, 6 };
	int r3[] = { 7, 8, 9 };

    matrix[0] = r1;
    matrix[1] = r2;
    matrix[2] = r3;

    printf("Expected: 0\tGot: %d\n", Determinant(matrix, size));

    // Test #2
    int r4[] = {1, -2, 3};
    int r5[] = {7, -5, 6};
    int r6[] = {19, 8, 9};

    matrix[0] = r4;
    matrix[1] = r5;
    matrix[2] = r6;

    printf("Expected: 258\tGot: %d\n", Determinant(matrix, size));
	delete[] matrix;

    // Test #3
    size = 4;
    matrix = new int*[size];

    int r7[] =  { 1, -2, 3, 3};
    int r8[] =  { 7, -5, 6, 11};
    int r9[] =  {19,  8, 9, 27};
    int r10[] = {30, 40, 1, 0};

    matrix[0] = r7;
    matrix[1] = r8;
    matrix[2] = r9;
    matrix[3] = r10;

    printf("Expected: -9310\tGot: %d\n", Determinant(matrix, size));
	delete[] matrix;

    // Test #4
    size = 2;
    matrix = new int*[size];

    int r11[] =  {1, -2};
    int r12[] =  {7, -5};

    matrix[0] = r11;
    matrix[1] = r12;

    printf("Expected: 9\tGot: %d\n", Determinant(matrix, size));
	delete[] matrix;

	system("pause");
	return 0;
}