#include<iostream>
using namespace std;

int main(){
    int n;

    cout<<"enter the alue of n:"<<endl;
    cin>>n;
    bool isPrime=1;

    for(int i=2; i<n; i++ ){
        if(n%i==0){
            //cout<<"Not a prime number."<<endl;
            isPrime=0;
            break;
        }
        
    }
    if(isPrime ==0){
        cout<<"Not prime no."<<endl;
    }
    else{
        cout<<"Is a prime no."<<endl;
    }

}