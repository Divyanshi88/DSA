#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    int dataTypeSize(string str) {
        if (str == "Character") {
            return sizeof(char);
        }
        if (str == "Integer") {
            return sizeof(int);
        }
        if (str == "Long") {
            return sizeof(long);
        }
        if (str == "Float") {
            return sizeof(float);
        }
        if (str == "Double") {
            return sizeof(double);
        }
        return -1; // Invalid input
    }
};

int main() {
    Solution solution;

    vector<string> testCases = {"Character", "Integer", "Long", "Float", "Double", "Unknown"};
    for (const string& testCase : testCases) {
        cout << "Size of " << testCase << ": " << solution.dataTypeSize(testCase) << " byte(s)" << endl;
    }

    return 0;
}
