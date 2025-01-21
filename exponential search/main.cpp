#include <iostream>
#include <vector>
using namespace std;
// Binary search to find an element within a sorted array
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high)/ 2;

        if (arr[mid] == target) {
            return mid; // Element found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}

// Exponential Search algorithm
int exponentialSearch(int arr[], int l, int r, int target) {
    if (arr[l] == target) {
        return l; // Element found at the beginning
    }

    int i = l+1;
    while (i <= r && arr[i] <= target) {
        i *= 2;
    }
    cout<<i<<endl;
    return binarySearch(arr, i / 2, std::min(i, r), target);
}

int main() {
    int arr[] = {2, 3, 4, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 30;
    int result = exponentialSearch(arr, 0, n-1, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
