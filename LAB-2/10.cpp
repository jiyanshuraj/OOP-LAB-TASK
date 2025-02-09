#include <iostream>

using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void populateMatrix(int** matrix, int rows, int cols) {
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** addMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        return nullptr; // Indicate that multiplication is not possible
    }

    int** result = allocateMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize to 0
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter number of rows for matrix 1: ";
    cin >> rows1;
    cout << "Enter number of columns for matrix 1: ";
    cin >> cols1;
    int** matrix1 = allocateMatrix(rows1, cols1);
    populateMatrix(matrix1, rows1, cols1);

    cout << "Enter number of rows for matrix 2: ";
    cin >> rows2;
    cout << "Enter number of columns for matrix 2: ";
    cin >> cols2;
    int** matrix2 = allocateMatrix(rows2, cols2);
    populateMatrix(matrix2, rows2, cols2);

    cout << "Matrix 1:" << endl;
    displayMatrix(matrix1, rows1, cols1);
    cout << "Matrix 2:" << endl;
    displayMatrix(matrix2, rows2, cols2);

    cout << "Matrix Addition:" << endl;
    int** sum = addMatrices(matrix1, matrix2, rows1, cols1);
    if (sum) {
      displayMatrix(sum, rows1, cols1);
      deallocateMatrix(sum, rows1);
    }
    

    cout << "Matrix Subtraction:" << endl;
    int** difference = subtractMatrices(matrix1, matrix2, rows1, cols1);
    if (difference) {
      displayMatrix(difference, rows1, cols1);
      deallocateMatrix(difference, rows1);
    }

    cout << "Matrix Multiplication:" << endl;
    int** product = multiplyMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);
    if (product) {
      displayMatrix(product, rows1, cols2);
      deallocateMatrix(product, rows1);
    } else {
        cerr << "Error: Matrices cannot be multiplied." << endl;
    }

    deallocateMatrix(matrix1, rows1);
    deallocateMatrix(matrix2, rows2);

    return 0;
}
