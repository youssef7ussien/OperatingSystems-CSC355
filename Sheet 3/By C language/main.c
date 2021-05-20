#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    double **ptr;
    int row, column;
};

void initMatrix(struct Matrix *matrix) {
    matrix->ptr = (double **) malloc(matrix->row * sizeof(double *));

    for(int i=0 ; i<matrix->row ; i++)
        matrix->ptr[i] = (double *) malloc(matrix->column * sizeof(double));
}

void freeMatrix(struct Matrix *matrix) {
    for(int i=0 ; i<matrix->row ; i++)
        free(matrix->ptr[i]);
    free(matrix->ptr);
    matrix->ptr = NULL;
    matrix->row = matrix->column = 0;
}

void inputMatrix(struct Matrix *matrix) {
    for(int i=0 ; i<matrix->row ; i++)
        for(int j=0 ; j<matrix->column ; j++)
            scanf("%lf", &matrix->ptr[i][j]);
}

void printMatrix(const struct Matrix matrix) {
    for(int i=0 ; i<matrix.row ; i++) {
        for(int j=0 ; j<matrix.column ; j++)
            printf("  %10g", matrix.ptr[i][j]);
        printf("\n");
    }
}

struct Matrix multiplyMatrices(struct Matrix firstMatrix,struct Matrix secondMatrix) {

    if(firstMatrix.column != secondMatrix.row) {
        printf("ERROR: The number of columns in the first matrix"
        " should be equal to the number of rows in the second.\n");
        exit(EXIT_FAILURE);
    }

    struct Matrix result;

    result.row=firstMatrix.row, result.column=secondMatrix.column;
    initMatrix(&result);

    for(int i=0 ; i<firstMatrix.row ; i++)
        for(int j=0 ; j<secondMatrix.column ; j++) {
            result.ptr[i][j]=0;
            for(int k=0 ; k<secondMatrix.row ; k++)
                result.ptr[i][j] += firstMatrix.ptr[i][k] * secondMatrix.ptr[k][j];
        }

    return result;
}

int main() {
    struct Matrix firstMatrix, secondMatrix;

    printf("Enter first matrix size (M*N): ");
    scanf("%d", &firstMatrix.row);
    scanf("%d", &firstMatrix.column);

    initMatrix(&firstMatrix);

    printf("Enter first matrix:\n");
    inputMatrix(&firstMatrix);

    printf("Enter second matrix size (M*N): ");
    scanf("%d", &secondMatrix.row);
    scanf("%d", &secondMatrix.column);

    initMatrix(&secondMatrix);

    printf("Enter second matrix:\n");
    inputMatrix(&secondMatrix);

    printf("-------------------\nThe result matrix:\n");
    printMatrix(multiplyMatrices(firstMatrix, secondMatrix));

    freeMatrix(&firstMatrix);
    freeMatrix(&secondMatrix);

    return 0;
}