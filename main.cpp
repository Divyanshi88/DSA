#include <iostream>
#include <vector>
using namespace std;

void insertelement(vector<int> &arr, int position, int val) {
    if(position < 0 || position > arr.size()) {
        cout << "Invalid position!" << endl;
        return;  // Exit if the position is invalid
    }
    arr.insert(arr.begin() + position, val);  // Use the correct variable name
}

void displayArray(vector<int> &arr) {
    for (int num : arr)  // C++11 range-based for loop
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr;  // Old initialization method
    arr.push_back(3);
    arr.push_back(8);
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(9);

    cout << "Original Array: ";
    displayArray(arr);

    // Example: Insert element 7 at position 2
    insertelement(arr, 2, 7);
    
    cout << "Array after insertion: ";
    displayArray(arr);

    return 0;
}
