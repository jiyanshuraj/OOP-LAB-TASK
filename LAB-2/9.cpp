#include<iostream>
using namespace std;

int** AllocateMemory(int row, int col) {
    int** arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }
    return arr;
}

void inputUser(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Matrix[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }
}

int** Transpose(int** arr, int row, int col) {
    int** transposed = AllocateMemory(col, row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transposed[j][i] = arr[i][j];
        }
    }
    return transposed;
}

void Deallocate(int** arr, int row) {
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void printMatrix(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int r, c;
    cout << "Enter Rows: ";
    cin >> r;
    cout << "Enter Columns: ";
    cin >> c;

    int** arr = AllocateMemory(r, c);
    inputUser(arr, r, c);

    cout << "Original Matrix:" << endl;
    printMatrix(arr, r, c);

    int** transposed = Transpose(arr, r, c);

    cout << "Transposed Matrix:" << endl;
    printMatrix(transposed, c, r);

    Deallocate(arr, r);
    Deallocate(transposed, c);

    return 0;
}
