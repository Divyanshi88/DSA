#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    
    while (start <= end ){
        int mid = start +(end-start)/2;
        if(arr[mid] == target)
            return mid;
        else if (arr[mid] < target) 
            start = mid +1;

        else
            end =mid -1;


    }
    return -1;
}
int main(){
    int arr[]= {2,5,8,10,15,20};
     cout<< binarysearch(arr, 6,15);
     return 0;
}