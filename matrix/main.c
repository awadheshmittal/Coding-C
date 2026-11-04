#include <stdio.h>
#include <math.h>

// Function Prototypes..
void submatrix(int n, int row, int column, int A[n][n], int C[n-1][n-1]);
void multiply(int r1, int c1, int r2, int c2, int A[r1][c1], int B[r2][c2], int C[r1][c2]);
double determinant(int n, int A[n][n]);
void inverse(int n, int A[n][n], double C[n][n]);

int main()
{
    int choice;
    do {
        printf("MATRIX CALCULATOR\n");
        printf("1. Multiplication\n");
        printf("2. Determinant\n");
        printf("3. Inverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Multiplication:
            case 1:
            {
                int r1, c1, r2, c2;
                printf("Enter Matrix A rows and columns: ");
                scanf("%d%d", &r1, &c1);
                int A[r1][c1];
                for(int i = 0; i < r1; i++)
                    for(int j = 0; j < c1; j++)
                    {
                        printf("A[R%dC%d]: ", i+1, j+1);
                        scanf("%d", &A[i][j]);
                    }

                printf("Enter Matrix B rows and columns: ");
                scanf("%d%d", &r2, &c2);
                int B[r2][c2];
                for(int i = 0; i < r2; i++)
                    for(int j = 0; j < c2; j++)
                    {
                        printf("B[R%dC%d]: ", i+1, j+1);
                        scanf("%d", &B[i][j]);
                    }

                if(c1 == r2)
                {
                    int C[r1][c2];
                    multiply(r1, c1, r2, c2, A, B, C);
                    printf("\nResultant Matrix C:\n");
                    for(int i = 0; i < r1; i++)
                    {
                        printf("[");
                        for(int j = 0; j < c2; j++)
                            printf("%3d ", C[i][j]);
                        printf("]\n");
                    }
                }
                else printf("\nError: Matrix multiplication not possible!\n");
                break;
            }

            // Determinant:
            case 2:
            {
                int n;
                printf("Enter the order of the matrix: ");
                scanf("%d", &n);
                int A[n][n];
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                    {
                        printf("A[R%dC%d]: ", i+1, j+1);
                        scanf("%d", &A[i][j]);
                    }

                printf("DETERMINANT is: %d\n", determinant(n, A));
                break;
            }

            // Inverse: 
            case 3:
            {
                int n;
                printf("Enter the order of the matrix: ");
                scanf("%d", &n);
                int A[n][n];
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                    {
                        printf("A[R%dC%d]: ", i+1, j+1);
                        scanf("%d", &A[i][j]);
                    }

                if(determinant(n, A) != 0)
                {
                    double C[n][n];
                    inverse(n, A, C);
                    for(int i = 0; i < n; i++)
                    {
                        printf("[");
                        for(int j = 0; j < n; j++)
                            printf("%3.2f ", C[i][j]);
                        printf("]\n");
                    }
                }
                else printf("Inverse not possible!");
                break;
            }

            case 4: break;
            default: printf("Invalid choice!\n\n");
        }
    } while(choice != 4);
    return 0;
}

// Helper Function..
void submatrix(int n, int row, int column, int A[n][n], int C[n-1][n-1])
{
    int index1 = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == row) continue;

        int index2 = 0;
        for(int j = 0; j < n; j++)
        {
            if(j == column) continue;
            C[index1][index2] = A[i][j];
            index2++;
        }
        index1++;
    }
}
// Multiplication: 
void multiply(int r1, int c1, int r2, int c2, int A[r1][c1], int B[r2][c2], int C[r1][c2])
{
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}
// Determinant:
double determinant(int n, int A[n][n])
{
    // Base Case
    if(n == 1)
        return A[0][0];

    // Recursive Case
    double det = 0;
    for(int i = 0; i < n; i++)
    {
        int C[n-1][n-1];
        submatrix(n, 0, i, A, C);
        det += pow(-1, i) * determinant(n-1, C) * A[0][i]; 
    }
    return det;
}
// Inverse:
void inverse(int n, int A[n][n], double C[n][n])
{
    for(int i = 0; i < n; i++)
    {
        int temp[n - 1][n - 1];
        for(int j = 0; j < n; j++)
        {
            submatrix(n, i, j, A, temp);
            C[j][i] = determinant(n - 1, temp) * pow(-1, i + j) / determinant(n, A);
        }
    }
}
