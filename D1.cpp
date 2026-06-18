#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// 1. Reverse an Array
void reverseArray(vector<int>& arr) {

    int left = 0;
    int right = arr.size() - 1;

    while(left < right) {

        swap(arr[left], arr[right]);

        left++;
        right--;
    }
}



// 2. Find Maximum Element
int findMax(vector<int> arr) {

    int maximum = arr[0];

    for(int num : arr) {

        if(num > maximum)
            maximum = num;
    }

    return maximum;
}



// 3. Find Minimum Element
int findMin(vector<int> arr) {

    int minimum = arr[0];

    for(int num : arr) {

        if(num < minimum)
            minimum = num;
    }

    return minimum;
}



// 4. Check Array Sorted
bool isSorted(vector<int> arr) {

    for(int i=0;i<arr.size()-1;i++) {

        if(arr[i] > arr[i+1])
            return false;
    }

    return true;
}



// 5. Remove Duplicates from Sorted Array
vector<int> removeDuplicates(vector<int> arr) {

    vector<int> result;

    result.push_back(arr[0]);


    for(int i=1;i<arr.size();i++) {

        if(arr[i] != arr[i-1])
            result.push_back(arr[i]);
    }

    return result;
}



// 6. Second Largest
int secondLargest(vector<int> arr) {

    int largest = INT_MIN;
    int second = INT_MIN;


    for(int num : arr) {

        if(num > largest) {

            second = largest;
            largest = num;
        }

        else if(num > second && num != largest) {

            second = num;
        }
    }

    return second;
}



// 7. Frequency Count
void frequency(vector<int> arr) {

    unordered_map<int,int> freq;


    for(int num : arr)
        freq[num]++;


    for(auto x : freq)
        cout << x.first << " -> " << x.second << endl;
}



// 8. Move Zeroes to End
void moveZero(vector<int>& arr) {

    int index = 0;


    for(int i=0;i<arr.size();i++) {

        if(arr[i] != 0) {

            swap(arr[i],arr[index]);
            index++;
        }
    }
}



// 9. Missing Number
int missingNumber(vector<int> arr) {

    int n = arr.size()+1;

    int total = n*(n+1)/2;


    int sum = 0;

    for(int x : arr)
        sum += x;


    return total - sum;
}



// 10. Two Sum
vector<int> twoSum(vector<int> nums, int target) {

    unordered_map<int,int> mp;


    for(int i=0;i<nums.size();i++) {

        int diff = target - nums[i];


        if(mp.find(diff) != mp.end()) {

            return {mp[diff], i};
        }


        mp[nums[i]] = i;
    }


    return {};
}



// 11. Reverse String
string reverseString(string s) {

    reverse(s.begin(), s.end());

    return s;
}



// 12. Palindrome Check
bool palindrome(string s) {

    string temp = s;

    reverse(temp.begin(), temp.end());


    return s == temp;
}



// 13. Count Vowels
int countVowels(string s) {

    int count = 0;


    for(char ch : s) {

        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            count++;
    }


    return count;
}



// 14. First Non Repeating Character
char firstUnique(string s) {

    unordered_map<char,int> freq;


    for(char ch:s)
        freq[ch]++;


    for(char ch:s) {

        if(freq[ch]==1)
            return ch;
    }


    return '-';
}



// 15. Anagram Check
bool anagram(string a,string b) {

    sort(a.begin(),a.end());

    sort(b.begin(),b.end());


    return a==b;
}



int main() {


    vector<int> arr = {1,2,3,4,5};


    reverseArray(arr);

    cout<<"1. Reverse Array: ";

    for(int x:arr)
        cout<<x<<" ";


    cout<<"\n\n2. Maximum: ";
    cout<<findMax({3,7,2,9,1});


    cout<<"\n3. Minimum: ";
    cout<<findMin({8,5,2,10});


    cout<<"\n4. Sorted: ";
    cout<<isSorted({1,2,3,4});


    cout<<"\n5. Second Largest: ";
    cout<<secondLargest({10,5,20,8});


    cout<<"\n\n7. Frequency:\n";
    frequency({1,2,2,3,3,3});


    cout<<"\n8. Move Zeroes: ";

    vector<int> zero = {0,1,0,3,12};

    moveZero(zero);

    for(int x:zero)
        cout<<x<<" ";


    cout<<"\n\n9. Missing Number: ";
    cout<<missingNumber({1,2,4,5});


    cout<<"\n10. Two Sum: ";

    vector<int> ans = twoSum({2,7,11,15},9);

    cout<<ans[0]<<" "<<ans[1];


    cout<<"\n11. Reverse String: ";
    cout<<reverseString("hello");


    cout<<"\n12. Palindrome: ";
    cout<<palindrome("madam");


    cout<<"\n13. Vowels: ";
    cout<<countVowels("developer");


    cout<<"\n14. First Unique: ";
    cout<<firstUnique("swiss");


    cout<<"\n15. Anagram: ";
    cout<<anagram("listen","silent");


    return 0;
}