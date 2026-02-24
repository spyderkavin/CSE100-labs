#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum of two integers
int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum sum that crosses the midpoint
int maxCrossingSum(const vector<int>& A, int low, int mid, int high) {
    // Left part of the cross: start at mid and move left
    int sum = 0;
    int left_sum = -2147483647; // Practical minimum for 32-bit int
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    // Right part of the cross: start at mid+1 and move right
    sum = 0;
    int right_sum = -2147483647;
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
}

// Main recursive function for Divide and Conquer
int maxSubarraySum(const vector<int>& A, int low, int high) {
    // Base Case: Only one element
    if (low == high) {
        return A[low];
    }

    // Find the midpoint
    int mid = low + (high - low) / 2;

    // Recursively find max in left and right halves
    int left_max = maxSubarraySum(A, low, mid);
    int right_max = maxSubarraySum(A, mid + 1, high);
    int cross_max = maxCrossingSum(A, low, mid, high);

    // Return the highest of the three
    return maxVal(maxVal(left_max, right_max), cross_max);
}

int main() {
    int n;
    // Read the size of the array
    if (!(cin >> n)) return 0;

    // Read the n integers
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Handle empty array or compute max subarray
    if (n > 0) {
        cout << maxSubarraySum(A, 0, n - 1) << endl;
    }

    return 0;
}