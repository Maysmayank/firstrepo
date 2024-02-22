#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 3

void matrixVectorMultiply(double matrix[SIZE][SIZE], double vector[SIZE], double result[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        result[i] = 0;
        for (int j = 0; j < SIZE; ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

double vectorMagnitude(double vector[SIZE]) {
    double sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += vector[i] * vector[i];
    }
    return sqrt(sum);
}

void normalizeVector(double vector[SIZE]) {
    double magnitude = vectorMagnitude(vector);
    for (int i = 0; i < SIZE; ++i) {
        vector[i] /= magnitude;
    }
}

int main() {
    double matrix[SIZE][SIZE] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    double vector[SIZE] = {1.0, 1.0, 1.0}; // Initial guess for the eigenvector

    double result[SIZE];

    int iterations = 100;
    double tolerance = 1e-6;

    for (int i = 0; i < iterations; ++i) {
        matrixVectorMultiply(matrix, vector, result);
        double magnitude = vectorMagnitude(result);

        if (magnitude < tolerance) {
            break;
        }

        normalizeVector(result);

        for (int j = 0; j < SIZE; ++j) {
            vector[j] = result[j];
        }
    }

    double eigenvalue = vectorMagnitude(result);
    printf("THe Eigenvalue is : %lf\n", eigenvalue);

    return 0;
}
