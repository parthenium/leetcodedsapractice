//asked in OYO interview

#include <iostream>
#include <vector>
using namespace std;

int findFirst(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1; // look on left side
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int findLast(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1; // look on right side
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int countOccurrences(const vector<int>& arr, int target) {
    int first = findFirst(arr, target);
    if (first == -1) return 0; // not found
    int last = findLast(arr, target);
    return last - first + 1;
}

int main() {
    vector<int> arr = {2, 4, 4, 4, 6, 7};
    int target = 4;
    cout << "Count of " << target << ": " << countOccurrences(arr, target) << endl;

    // More test cases
    cout << countOccurrences({5,5,5}, 5) << endl;        // Output: 3
    cout << countOccurrences({1,2,3,3}, 3) << endl;      // Output: 2
    cout << countOccurrences({1,2,3}, 4) << endl;        // Output: 0

    return 0;
}
