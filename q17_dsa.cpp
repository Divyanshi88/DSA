#include <iostream>
#include <vector>

void sortColors(std::vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            std::swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            std::swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    std::vector<int> arr = {2, 0, 1, 2, 0};
    sortColors(arr);

    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
