#include<iostream>
using namespace std;

void insertionsort(int arr[], int n){
    for(int i=0; i<n; i++){
        int key =arr[i];
       int j =i-1 ;

       while (j> =0 && rr[j]> key ){
        arr[j+1]== arr[j];
        j--;
       }
       arr[j+1]= key;

    }
}