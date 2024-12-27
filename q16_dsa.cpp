#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> arr = {"banana", "apple", "cherry"};
    std::sort(arr.begin(), arr.end());
    for (const auto& str : arr) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}
