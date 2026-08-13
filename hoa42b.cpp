#include <iostream>

class Node {
public:
    int data;
    Node* next; // Corrected pointer syntax
};

Node *head = NULL;

void push(int newData) { //Allocates a new node dynamically in the heap region and assigns newData to the node, then newNode->next will be assigned to point at the current top node (head), and finally, head will be 
    //assigned to newNode so that newNode becomes the new top.
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head; // Points to current head (top)
    head = newNode;       // New node becomes the new top
}

int pop() { // Removes the topmost element of the stack. First, it checks whether the stack is empty. If it is not empty, it prints the value of the topmost element and decreases the top counter by one.
    if (head == NULL) {
        std::cout << "Stack Underflow." << std::endl;
        return -1;
    }
    Node *temp = head;
    int tempVal = temp->data;
    head = head->next;
    delete temp;
    return tempVal;
}

void Top() { // Displays the topmost element of the stack. First, it checks whether the stack is empty. If it is not empty, it prints the value of the topmost element.
    if (head == NULL) {
        std::cout << "Stack is Empty." << std::endl;
    } else {
        std::cout << "Top of Stack: " << head->data << std::endl;
    }
}

// Added Display operation. Displays all the elements of the stack from top to bottom. First, it checks whether the stack is empty. If it is not empty, it iterates 
// through the stack from top to bottom and prints each element.
void display() {
    if (head == NULL) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    Node *curr = head;
    std::cout << "Stack elements (top to bottom): ";
    while (curr != NULL) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    push(1);
    std::cout << "After first PUSH: "; Top();
    
    push(5);
    std::cout << "After second PUSH: "; Top();

    std::cout << "Displaying stack: "; display();

    pop();
    std::cout << "After first POP: "; Top();

    pop();
    std::cout << "After second POP: "; Top();

    pop(); // Triggers Underflow
    return 0;
}