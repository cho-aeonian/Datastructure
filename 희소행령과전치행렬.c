#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    Element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

SparseMatrix transposeMatrix(SparseMatrix a) {
    SparseMatrix b;
    int numTerms = a.terms;
    int numCols = a.cols;
    
    b.rows = numCols;
    b.cols = a.rows;
    b.terms = numTerms;
    
    if (numTerms > 0) {
        int currentB = 0;
        for (int currentCol = 0; currentCol < numCols; currentCol++) {
            for (int i = 0; i < numTerms; i++) {
                if (a.data[i].col == currentCol) {
                    b.data[currentB].row = a.data[i].col;
                    b.data[currentB].col = a.data[i].row;
                    b.data[currentB].value = a.data[i].value;
                    currentB++;
                }
            }
        }
    }
    
    return b;
}

void printMatrix(SparseMatrix a) {
    for (int i = 0; i < a.terms; i++) {
        printf("(%d, %d, %d)\n", a.data[i].row, a.data[i].col, a.data[i].value);
    }
    printf("---------------------\n");
}

int main() {
    SparseMatrix matrix;
    
    scanf("%d %d %d", &matrix.terms, &matrix.rows, &matrix.cols);
    
    for (int i = 0; i < matrix.terms; i++) {
        scanf("%d %d %d", &matrix.data[i].row, &matrix.data[i].col, &matrix.data[i].value);
    }
    
    printMatrix(matrix);
    
    SparseMatrix transposedMatrix = transposeMatrix(matrix);
    printMatrix(transposedMatrix);
    
    return 0;
}