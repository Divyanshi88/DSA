#include<iostream>
using namespace std;

void slectionsort(int arr[], int n){
    for(int i =0; i<n-1; i++){
        int minindex= i;

        for(int j=0; j<n; j++){
            if(arr[j] < arr[minindex]){
                minindex = arr[j];
            }
        }
        swap(arr[i] ,arr[minindex]);
    }
}
int main()
{
    int arr[] = {5,3,8,1,2};

    slectionsort(arr,5);

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}