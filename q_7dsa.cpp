#include <iostream>
using namespace std;

void printForest(int N){
    for(i=0; i<N; i++){
        for(int j; j<N; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    int N;
    cout<<"Enter the value of N:";
    cin>>N;
    printForest(N)
    return 0;
}