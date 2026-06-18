#include <iostream>
using namespace std;

void printLowerTriangle(int N){
    for(int i =0; i<=N; i++){
        for(int j=0; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    } 
}
int main(){
    int N;
    cout<<"Enter the value of N:";
    cin>>N;
    printLowerTriangle(N);
    return 0;
}