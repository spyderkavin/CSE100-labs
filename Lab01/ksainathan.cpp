#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    
    // Step 1: Read the number of elements (n)
    if (!(cin >> n)) return 0;

    // Step 2: Store the elements in a vector
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Insertion Sort logic with snapshot output
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Compare key with elements to its left and move them 
        // if they are larger than the key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Step 4: Print the current sorted portion (snapshot)
        // Per instructions, for each k where 2 <= k <= n, print first k elements
        for (int k = 0; k <= i; k++) {
            cout << arr[k] << ";";
        }
        cout << endl;
    }

    return 0;
}