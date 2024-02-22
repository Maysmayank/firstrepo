#include <stdio.h>
#include <stdlib.h>

struct Element {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int numRows;
    int numCols;
    int numElements;
    struct Element* elements;
};

struct SparseMatrix createSparseMatrix(int numRows, int numCols, int numElements) {
    struct SparseMatrix matrix;
    matrix.numRows = numRows;
    matrix.numCols = numCols;
    matrix.numElements = numElements;
    matrix.elements = (struct Element*)malloc(numElements * sizeof(struct Element));

    if (matrix.elements == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    return matrix;
}

void readMatrix(struct SparseMatrix* matrix) {
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &matrix->numRows, &matrix->numCols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &matrix->numElements);

    matrix->elements = (struct Element*)malloc(matrix->numElements * sizeof(struct Element));

    if (matrix->elements == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < matrix->numElements; ++i) {
        scanf("%d %d %d", &matrix->elements[i].row, &matrix->elements[i].col, &matrix->elements[i].value);
    }
}

void printSparseMatrix(struct SparseMatrix matrix) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < matrix.numElements; ++i) {
        printf("(%d, %d) = %d\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}

int main() {
    struct SparseMatrix sparseMatrix;

    // Initialize with createSparseMatrix function
    sparseMatrix = createSparseMatrix(0, 0, 0);

    // Read matrix from user
    readMatrix(&sparseMatrix);

    // Print the sparse matrix
    printSparseMatrix(sparseMatrix);

    // Free allocated memory
    free(sparseMatrix.elements);

    return 0;
}
