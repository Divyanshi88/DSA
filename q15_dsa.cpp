#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, discriminant, root1, root2;

    cin >> a >> b >> c;
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Root 1: " << root1 << "\nRoot 2: " << root2 << endl;
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        cout << "Root: " << root1 << endl;
    } else {
        cout << "No real roots" << endl;
    }

    return 0;
}
