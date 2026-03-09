#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A stable counting sort based on a specific digit (index)
void countingSort(vector<vector<int>>& A, int digit) {
    int n = A.size();
    vector<vector<int>> B(n, vector<int>(10));
    // Since values are only 0, 1, 2, 3, we only need 4 buckets
    vector<int> C(4, 0);

    // Count occurrences of each value at the specific digit
    for (int i = 0; i < n; i++) {
        C[A[i][digit]]++;
    }

    // Update C[i] to contain the actual position of this digit in B
    for (int i = 1; i < 4; i++) {
        C[i] += C[i - 1];
    }

    // Build the output array B by iterating backwards to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i][digit]] - 1] = A[i];
        C[A[i][digit]]--;
    }

    // Copy B back to A
    A = B;
}

void radixSort(vector<vector<int>>& A) {
    // Sort from the least significant digit (index 9) to most significant (index 0)
    for (int d = 9; d >= 0; d--) {
        countingSort(A, d);
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> vectors(n, vector<int>(10));

    // Read input vectors
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> vectors[i][j];
        }
    }

    radixSort(vectors);

    // Print output in the required format: value;value;...;value;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << vectors[i][j] << ";";
        }
        cout << endl;
    }

    return 0;
}