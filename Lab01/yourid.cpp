#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int n) {
    // The problem asks to output snapshots for 2 <= k <= n
    // k represents the number of elements currently being considered/sorted
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Output the snapshot: first i + 1 elements followed by ;
        for (int k = 0; k <= i; k++) {
            cout << arr[k] << ";";
        }
        cout << endl;
    }
}

int main() {
    int n;
    // Read the number of elements
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    // Read n elements from the input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform sort and print snapshots
    insertionSort(arr, n);

    return 0;
}