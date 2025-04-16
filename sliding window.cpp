#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> last_seen;
    int left = 0, max_length = 0;

    for (int right = 0; right < s.length(); right++) {
        if (last_seen.count(s[right])) {
            left = max(left, last_seen[s[right]] + 1); // Jump to next valid position
        }

        last_seen[s[right]] = right;
        max_length = max(max_length, right - left + 1);
    }

    return max_length;
}
