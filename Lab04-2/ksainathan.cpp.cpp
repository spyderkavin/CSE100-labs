#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Standard Partitioning
int partition(vector<int>& A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

// Randomized Partitioning as required by Lab04-2
int randomizedPartition(vector<int>& A, int p, int r) {
    // Generate random index between p and r
    int i = p + rand() % (r - p + 1);
    swap(A[r], A[i]);
    return partition(A, p, r);
}

void quickSort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = randomizedPartition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    // Read exactly n elements
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    if (n > 0) {
        quickSort(A, 0, n - 1);
    }

    // Strict output format: No spaces, each element followed by ;
    for (int i = 0; i < n; i++) {
        cout << A[i] << ";";
    }
    
    return 0;
}