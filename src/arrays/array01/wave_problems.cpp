#include <iostream>
using namespace std;

void waveH(int arr[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
        }
        else {
            for (int j = cols - 1; j >= 0; j--) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

void waveV(int arr[][100], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < rows; i++) {
                cout << arr[i][j] << " ";
            }
        }
        else {
            for (int i = rows - 1; i >= 0; i--) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

void spiralPrint(int arr[][100], int rows, int cols) {
    int top = 0, bottom = rows;
    int left = 0, right = cols;

    while (left < right && top < bottom) {
        // Top row → left to right
        for (int i = left; i < right; i++) {
            cout << arr[top][i] << " ";
        }
        top++;

        // Right column ↓ top to bottom
        for (int i = top; i < bottom; i++) {
            cout << arr[i][right - 1] << " ";
        }
        right--;

        // Bottom row ← right to left
        if (top < bottom) {
            for (int i = right - 1; i >= left; i--) {
                cout << arr[bottom - 1][i] << " ";
            }
            bottom--;
        }

        // Left column ↑ bottom to top
        if (left < right) {
            for (int i = bottom - 1; i >= top; i--) {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int arr[100][100];  // Large enough to handle general input
    cout << "enter data for matrix:" << endl;
    // Input
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Output matrix
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Wave traversals
    cout << "Horizontal Wave: ";
    waveH(arr, rows, cols);

    cout << "Vertical Wave: ";
    waveV(arr, rows, cols);

    spiralPrint(arr, rows, cols);

    return 0;
}

