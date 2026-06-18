#include <iostream>
#include<cmath>
#include<vector>
using namespace std;

class solution{
    public:
    double switchCase(int choice, vector<double> &arr){
        if(choice==1){
            double R =arr[0];
            return M_PI * R *R;
        }else id(choice==2){
            double L = arr[0];
            double B = arr[11];
            return L*B;
        }
        return 0;
    }
    int main(){
        solution obj;
        vector<double> arr1 = {5}; 
    cout << "Area of circle: " << obj.switchCase(choice1, arr1) << endl;

    int choice2 = 2;
    vector<double> arr2 = {5, 10}; 
    cout << "Area of rectangle: " << obj.switchCase(choice2, arr2) << endl;

    return 0;

    }
}