#include <iostream>

const size_t maxCap = 100;
int stack[maxCap];
int top = -1, i, newData;

void push(); // Adds a new element to the stack. First, it checks whether top == i - 1 to avoid Stack Overflow. If there is enough room in the stack, 
// it increases the top counter by one and adds the value entered by the user to stack[top].
void pop(); // Removes the topmost element of the stack. First, it checks whether the stack is empty. If it is not empty, it prints the value of the topmost element and decreases the top counter by one.
void Top(); // Displays the topmost element of the stack. First, it checks whether the stack is empty. If it is not empty, it prints the value of the topmost element.
bool isEmpty(); // Returns a boolean response (true or false) indicating whether the stack is empty. It checks whether top == -1. If it is, the stack is empty; otherwise, it is not.
void display(); // Added function requirement. Displays all the elements of the stack from top to bottom. First, it checks whether the stack is empty. If it is not empty, it iterates through the stack 
// from top to bottom and prints each element.

int main() {
    int choice;
    std::cout << "Enter number of max elements for new stack: ";
    std::cin >> i;

    while (true) {
        std::cout << "\nStack Operations: " << std::endl;
        std::cout << "1. PUSH, 2. POP, 3. TOP, 4. isEMPTY, 5. DISPLAY, 6. EXIT" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: Top(); break;
            case 4: std::cout << (isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << std::endl; break;
            case 5: display(); break;
            case 6: return 0;
            default: std::cout << "Invalid Choice." << std::endl; break;
        }
    }
    return 0;
}

bool isEmpty() {
    return (top == -1);
}

void push() {
    if (top == i - 1) {
        std::cout << "Stack Overflow." << std::endl;
        return;
    }
    std::cout << "New Value: ";
    std::cin >> newData;
    stack[++top] = newData;
}

void pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow." << std::endl;
        return;
    }
    std::cout << "Popping: " << stack[top] << std::endl;
    top--;
}

void Top() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    std::cout << "The element on the top of the stack is " << stack[top] << std::endl;
}

// Added Display Function
void display() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    std::cout << "Stack elements (top to bottom): ";
    for (int idx = top; idx >= 0; idx--) {
        std::cout << stack[idx] << " ";
    }
    std::cout << std::endl;
}