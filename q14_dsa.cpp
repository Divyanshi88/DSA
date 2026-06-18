#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr + n, greater<int>());

    cout << "Array sorted in descending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
