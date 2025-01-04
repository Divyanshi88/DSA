#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform binary search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // To avoid overflow
        
        if (arr[mid] == target)
            return mid; // Target found
        
        if (arr[mid] < target)
            left = mid + 1; // Search in the right half
        else
            right = mid - 1; // Search in the left half
    }
    
    return -1; // Target not found
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int target;
    
    cout << "Enter the number to search: ";
    cin >> target;
    
    int result = binarySearch(arr, target);
    
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;
    
    return 0;
}
