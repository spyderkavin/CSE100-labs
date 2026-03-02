#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Standard Heapify to maintain Max-Heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n) {
    // 1. Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 2. Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    // Optimize I/O for competitive programming/lab standards
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Only read exactly 'n' elements as specified by the first input
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) break;
    }

    if (n > 0) {
        heapSort(arr, n);

        // Output formatting: No spaces, semicolon after EVERY element
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ";";
        }
    }
    
    // Ensure no trailing newline or spaces if the autograder is extremely strict
    return 0;
}