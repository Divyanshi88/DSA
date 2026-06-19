#include <iostream>
using namespace std;

// Example of basic recursion
// Function calls itself until base case is reached

void printNumbers(int n)
{
    // Base Case
    if(n == 0)
        return;

    cout << n << " ";

    // Recursive Call
    printNumbers(n - 1);
}

int main()
{
    int n = 5;

    printNumbers(n);

    return 0;
}
#include <iostream>
using namespace std;

// Fibonacci recursion
// fib(n) = fib(n-1) + fib(n-2)

int fib(int n)
{
    if(n <= 1)
        return n;

    return fib(n-1) + fib(n-2);
}

int main()
{
    int n = 5;

    cout << "Fibonacci: " << fib(n);

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    /*
    
    Time Complexity:

    O(1)
    -> Constant time

    O(n)
    -> Linear

    O(log n)
    -> Divide by 2 type operations

    O(n^2)
    -> Nested loops

    O(n log n)
    -> Efficient sorting patterns


    Space Complexity:

    O(1)
    -> No extra memory

    O(n)
    -> Array / Recursion stack


    Recursion:

    Time = Total calls in recursion tree

    Space = Maximum depth of recursion stack

    */

    cout << "DSA Foundation Complete";

    return 0;
}
