
#include <iostream>
using namespace std;

void printReverseTable(int n){
    int i=10;
    while(i>=1){
    cout<<n*i<<" ";
    i--;
    }
    cout <<endl;
}
int main(){
    int n;
    
    cout<<"Enter a number (1<=n<=1000):";
    cin>>n;

    if(n >= 1 && n <= 1000){
        printReverseTable(n);
    }else{
         cout << "Invalid input! Please enter a number between 1 and 1000." << endl;
    }
    return 0;



}