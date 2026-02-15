#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Textbook implementation using Sentinels (infinity)
void merge(vector<int>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create arrays of size n+1 to hold the sentinel
    vector<long long> L(n1 + 1);
    vector<long long> R(n2 + 1);

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    // Use a sentinel value larger than any possible input integer
    L[n1] = numeric_limits<long long>::max();
    R[n2] = numeric_limits<long long>::max();

    int i = 0;
    int j = 0;

    // Merge back into A
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    // Disable sync to speed up I/O and prevent extra buffering
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    // EXACT formatting: No spaces, semicolon after every element, NO newline at end
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ";";
    }

    return 0;
}