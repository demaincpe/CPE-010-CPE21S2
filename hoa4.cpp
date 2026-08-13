#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> newStack;

    newStack.push(3); // Adds 3 to the stack
    newStack.push(8);
    newStack.push(15);

    // returns a boolean response (1 or 0)
    cout << "Stack Empty? " << newStack.empty() << endl;

    // returns the size of the stack
    cout << "Stack Size: " << newStack.size() << endl;

    // returns the topmost element of the stack
    cout << "Top Element of the Stack: " << newStack.top() << endl;

    // removes the topmost element of the stack
    newStack.pop();

    cout << "Top Element of the Stack: " << newStack.top() << endl;
    cout << "Stack Size: " << newStack.size() << endl;

    return 0;
}