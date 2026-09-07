// Matrix Calculations..
#include <stdio.h>
#include <math.h>

// Function Prototypes
void multiply(int r1, int c1, int r2, int c2, int A[r1][c1], int B[r2][c2], int C[r1][c2]);
void submatrix(int n, int column, int A[n][n], int C[n-1][n-1]);
int determinant(int n, int A[n][n]);

int main()
{
    int r1, c1;
    printf("Enter Matrix A rows and columns: ");
    scanf("%d%d", &r1, &c1);
    int A[r1][c1];
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c1; j++)
        {
            printf("R%dC%d: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\n");

    int r2, c2;
    printf("Enter Matrix B rows and columns: ");
    scanf("%d%d", &r2, &c2);
    int B[r2][c2];
    for(int i = 0; i < r2; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            printf("R%dC%d: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }

    if(c1 != r2)
    {
        printf("Matrix multiplication not possible!");
    }
    else
    {
        int C[r1][c2];
        multiply(r1, c1, r2, c2, A, B, C);
        for(int i = 0; i < r1; i++)
        {
            printf("[");
            for(int j = 0; j < c2; j++)
            {
                printf("%3d ", C[i][j]);
            }
            printf("]\n");
        }
    }

    if(c1 == r1)
    {
        printf("Determinant is %d", determinant(c1, A));
    }
    else
    {
        printf("Determinant cannot be calculated for the matrix!");
    }
    
    return 0;
}

// Multiplication: 
void multiply(int r1, int c1, int r2, int c2, int A[r1][c1], int B[r2][c2], int C[r1][c2])
{
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Determinant:
int determinant(int n, int A[n][n])
{
    // Base Case
    if(n == 1)
    {
        return A[0][0];
    }

    // Recursive Case
    int det = 0;
    for(int i = 0; i < n; i++)
    {
        int C[n-1][n-1];
        submatrix(n, i, A, C);
        det += pow(-1, i) * determinant(n-1, C) * A[0][i]; 
    }
    return det;
}
void submatrix(int n, int column, int A[n][n], int C[n-1][n-1]) // Helper Function
{
    int index1 = 0;
    for(int i = 1; i < n; i++)
    {
        int index2 = 0;
        for(int j = 0; j < n; j++)
        {
            if(j != column)
            {
                C[index1][index2] = A[i][j];
                index2++;
            }
        }
        index1++;
    }
}
