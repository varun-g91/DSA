#include <stdio.h>
#include <stdlib.h>

struct Matrices
{
    int nrows, ncols, mrows, mcols;
    int Matrix1[50][50], Matrix2[50][50], Product[50][50];
} m1, m2, m3, m4, m5, m6, m7;

void restartingProgram()
{
    printf("Please check the order of your matrix such that the number of rows in the first matrix is equal to the number of columns in the second matrix\n");
}

int inputMatrix()
{
    printf("Enter number of rows for first matrix:\n");
    scanf("%d", &m4.nrows);
    printf("Enter the number of columnss of first matrix:\n");
    scanf("%d", &m5.ncols);
    printf("Enter elements for first matrix:\n");
    printf("Enter number of rows for the second matrix:\n");
    scanf("%d|%d", &m6.mrows);
    printf("Enter the number of columnss of second matrix:\n");
    scanf("%d", &m7.mcols);

    if (m5.ncols != m6.mrows)
    {
        printf("Matrix multiplication can only be performed when the number of columns of the first matrix is equal to the number of rows of the second matrix.\n");
        restartingProgram();
        exit(0);
    }
     printf("Enter elements for first matrix:\n");
    for (int i = 0; i < m4.nrows; i++)
    {
        for (int j = 0; j < m5.ncols; j++)
        {
            printf("Enter element of row %d, column %d:\t", i + 1, j + 1);
            scanf("%d", &m1.Matrix1[i][j]);
        }
    }
	
	printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < m6.mrows; i++)
    {
        for (int j = 0; j < m7.mcols; j++)
        {
            printf("Enter element of row %d, column %d:\t", i + 1, j + 1);
            scanf("%d", &m2.Matrix2[i][j]);
        }
    }

}

struct Matrices MultiplyMatrix()
{
    struct Matrices result;

    for (int i = 0; i < m4.nrows; i++)
    {
        for (int j = 0; j < m7.mcols; j++)
        {
            result.Product[i][j] = 0;
            for (int k = 0; k < m5.ncols; k++)
            {
                result.Product[i][j] += m1.Matrix1[i][k] * m2.Matrix2[k][j];
            }
        }
    }

    result.nrows = m4.nrows;
    result.ncols = m7.mcols;

    return result;
}

void displayMatrix(struct Matrices m)
{
    printf("After Matrix multiplication, this is the resultant matrix of order %dx%d\n", m.nrows, m.ncols);
    for (int i = 0; i < m.nrows; i++)
    {
        for (int j = 0; j < m.ncols; j++)
        {
            printf("%d\t", m.Product[i][j]);
        }
        printf("\n\n");
    }
}

int main()
{
    inputMatrix();
    struct Matrices m3 = MultiplyMatrix();
    displayMatrix(m3);

    return 0;
}
