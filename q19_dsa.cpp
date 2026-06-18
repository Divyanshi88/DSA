#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {10, 7, 2, 5, 8, 1, 9, 3, 6, 4};

    std::cout << "Before sorting: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::sort(numbers.begin(), numbers.end());

    std::cout << "After sorting in ascending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    std::cout << "After sorting in descending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
