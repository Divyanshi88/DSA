#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
       
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
      
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr1 = {4, 1, 3, 9, 7};
    vector<int> arr2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> arr3 = {38, 31, 20, 14, 30};

    selectionSort(arr1);
    selectionSort(arr2);
    selectionSort(arr3);

   
    for (int num : arr1) cout << num << " ";
    cout << endl;

    for (int num : arr2) cout << num << " ";
    cout << endl;

    for (int num : arr3) cout << num << " ";
    cout << endl;

    return 0;
}
