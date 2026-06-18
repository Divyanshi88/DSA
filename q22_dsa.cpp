#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed onto the stack." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    stack.display();

    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.display();

    return 0;
}
