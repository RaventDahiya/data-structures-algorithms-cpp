#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Square matrix 3x3
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = mat.size(); // square matrix, so rows = cols

    // Transpose in-place by swapping elements across diagonal
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Print transposed matrix
    cout << "In-place Transposed Matrix:\n";
    for (const auto& row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
