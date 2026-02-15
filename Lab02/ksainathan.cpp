#include <iostream>
#include <vector>

using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp vectors back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, r - m > 0 ? m + 1 : m, r); // Simplified recursive call
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Overloaded mergeSort for easier calling
void mergeSort(vector<int>& arr) {
    if (arr.empty()) return;
    mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    int n;
    // Read number of elements
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    // Read the elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform Merge Sort
    mergeSort(arr, 0, n - 1);

    // Output formatting: No spaces, semicolon after EVERY element
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ";";
    }
    cout << endl;

    return 0;
}