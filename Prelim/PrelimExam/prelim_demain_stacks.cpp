#include <iostream>

const size_t maxCap = 100;
int stack1[maxCap];
int stack2[maxCap];
int top = -1, i, newData;

void push(); // Adds a new element to the stack. First, it checks whether top == i - 1 to avoid Stack Overflow. If there is enough room in the stack, 
// it increases the top counter by one and adds the value entered by the user to stack[top].
void pop1(); // Removes the topmost element of the stack. First, it checks whether the stack is empty. If it is not empty, it prints the value of the topmost element and decreases the top counter by one.
void pop2();
void Top1(); // Displays the topmost element of the stack. First, it checks whether the stack is empty. If it is not empty, it prints the value of the topmost element.
void Top2();
bool isEmpty(); // Returns a boolean response (true or false) indicating whether the stack is empty. It checks whether top == -1. If it is, the stack is empty; otherwise, it is not.
void display1(); // Added function requirement. Displays all the elements of the stack from top to bottom. First, it checks whether the stack is empty. If it is not empty, it iterates through the stack 
// from top to bottom and prints each element.
void display2();

int main() {
    int choice;
    std::cout << "Enter number of max elements for new stack: ";
    std::cin >> i;

    while (true) {
        std::cout << "\nStack Operations: " << std::endl;
        std::cout << "1. PUSH, 2. POP STACK 1, 3. POP STACK 2, 4. TOP OF STACK 1, 5. TOP OF STACK 2., 6. isEMPTY, 7. DISPLAY STACK 1, 8. DISPLAY STACK 2, 9. EXIT" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop1(); break;
            case 3: pop2(); break;
            case 4: Top1(); break;
            case 5: Top2(); break;
            case 6: std::cout << (isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << std::endl; break;
            case 7: display1(); break;
            case 8: display2(); break;
            case 9: return 0;
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
    stack1[++top] = newData;
}

void pop1() {
    if (isEmpty()) {
        std::cout << "Stack Underflow." << std::endl;
        return;
    }
    std::cout << "Popping: " << stack1[top] << std::endl;
    top--;

}

void Top1() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    std::cout << "The element on the top of the stack is " << stack1[top] << std::endl;
}

// Added Display Function
void display1() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    std::cout << "Stack elements (top to bottom): ";
    for (int idx = top; idx >= 0; idx--) {
        std::cout << stack1[idx] << " ";
    }
    std::cout << std::endl;
}

void display2() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    std::cout << "Stack elements (top to bottom): ";
    for (int idy = top; idy >= 0; idy--) {
        std::cout << stack2[idy] << " ";
    }
    std::cout << std::endl;
}