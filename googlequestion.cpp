#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 1. Two-pointer technique: Find a pair with a given sum in a sorted array
bool twoPointerPairSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        (sum < target) ? left++ : right--;
    }
    return false;
}

// 2. Sliding Window: Maximum sum subarray of size k
int maxSumSubarray(vector<int>& arr, int k) {
    int maxSum = 0, windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += arr[i];
    maxSum = windowSum;

    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

// 3. Prefix Sum: Get sum of subarray (l, r) in O(1)
vector<int> prefixSumArray(vector<int>& arr) {
    vector<int> prefixSum(arr.size());
    prefixSum[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    return prefixSum;
}

// 4. HashMap (unordered_map): Two Sum Problem
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.count(complement)) return {mp[complement], i};
        mp[nums[i]] = i;
    }
    return {};
}

// 5. Binary Search
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        (arr[mid] < target) ? left = mid + 1 : right = mid - 1;
    }
    return -1;
}

// 6. Sorting Algorithms
void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int pivot = arr[high], i = low;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot) swap(arr[i++], arr[j]);
    swap(arr[i], arr[high]);

    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// 7. Basic Dynamic Programming (Fibonacci & Knapsack)
int fibonacci(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

int knapsack(vector<int>& weights, vector<int>& values, int capacity, int n) {
    if (n == 0 || capacity == 0) return 0;
    if (weights[n - 1] > capacity) return knapsack(weights, values, capacity, n - 1);
    return max(values[n - 1] + knapsack(weights, values, capacity - weights[n - 1], n - 1),
               knapsack(weights, values, capacity, n - 1));
}

// 8. Greedy Algorithm: Activity Selection (Max Activities that can be done)
int activitySelection(vector<pair<int, int>>& activities) {
    sort(activities.begin(), activities.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 1, end = activities[0].second;
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].first >= end) {
            count++;
            end = activities[i].second;
        }
    }
    return count;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    vector<int> arr2 = {2, 1, 3, 6, 5, 4};

    // Two-pointer technique
    cout << "Two-pointer Pair Sum (target=10): " << twoPointerPairSum(arr, 10) << endl;

    // Sliding Window
    cout << "Max Sum Subarray (k=3): " << maxSumSubarray(arr2, 3) << endl;

    // Prefix Sum
    vector<int> prefixSum = prefixSumArray(arr2);
    cout << "Prefix Sum (index 1 to 4): " << prefixSum[4] - (1 > 0 ? prefixSum[1 - 1] : 0) << endl;

    // Two Sum using HashMap
    vector<int> twoSumRes = twoSum(arr2, 6);
    if (!twoSumRes.empty()) cout << "Two Sum Indices: " << twoSumRes[0] << ", " << twoSumRes[1] << endl;

    // Binary Search
    cout << "Binary Search (target=7): " << binarySearch(arr, 7) << endl;

    // Sorting
    quickSort(arr2, 0, arr2.size() - 1);
    cout << "QuickSorted Array: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    // Fibonacci DP
    vector<int> dp(10, -1);
    cout << "Fibonacci(9): " << fibonacci(9, dp) << endl;

    // Activity Selection
    vector<pair<int, int>> activities = {{1, 3}, {2, 5}, {4, 6}, {5, 7}};
    cout << "Max Activities Selected: " << activitySelection(activities) << endl;

    return 0;
}
