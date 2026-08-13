#include <iostream>

class Node {
public:
    char data;
    Node* next;
};

// List Traversal
void listTraversal(Node* n) {
    while (n != nullptr) {
        std::cout << n->data;
        n = n->next;
    }
    std::cout << std::endl;
}

// Insertion at Head
void insertAtHead(Node** head_ref, char new_data) {
    // 1. Allocate memory for the new node
    Node* new_node = new Node();
    
    // 2. Put data into new node
    new_node->data = new_data;
    
    // 3. Set Next of new node to point to previous Head
    new_node->next = *head_ref;
    
    // 4. Reset Head to point to new node
    *head_ref = new_node;
}

// Insertion after a specific previous node
void insertAfter(Node* prev_node, char new_data) {
    // 1 & 2. Check if the previous node is null
    if (prev_node == nullptr) {
        std::cout << "Previous node cannot be null.\n";
        return;
    }

    // 3. Allocate a new node
    Node* new_node = new Node();

    // 4. Store data in the new node
    new_node->data = new_data;

    // 5. Point new node to the node previous node was pointing to
    new_node->next = prev_node->next;

    // 6. Point previous node to the new node
    prev_node->next = new_node;
}

// Insertion at the End
void insertAtEnd(Node** head_ref, char new_data) {
    // 1. Allocate new node
    Node* new_node = new Node();

    // 2. Dereference to the head node (used to traverse)
    Node* last = *head_ref;

    // 3. Store data in new node
    new_node->data = new_data;

    // 4. Point next of new node to NULL
    new_node->next = nullptr;

    // If the Linked List is empty, make new_node the head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    // 5. Traverse the list until next of the node is null
    while (last->next != nullptr) {
        last = last->next;
    }

    // 6. Point the next of the current node to the new node
    last->next = new_node;
}

// Deletion of a node containing target data
void deleteNode(Node** head_ref, char key) {
    Node* temp = *head_ref;
    Node* prev = nullptr;

    // If head node itself holds the key to be deleted
    if (temp != nullptr && temp->data == key) {
        *head_ref = temp->next; // Change head
        delete temp;            // Free memory
        return;
    }

    // 1. Find previous node of the node to be deleted
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == nullptr) return;

    // 2. Change the next of previous node
    prev->next = temp->next;

    // 3. Free memory for the node to be deleted
    delete temp;
}

int main() {
    Node* head = nullptr;

    // Build initial list "CPE101" using insertAtEnd
    insertAtEnd(&head, 'C');
    insertAtEnd(&head, 'P');
    insertAtEnd(&head, 'E');
    insertAtEnd(&head, '1');
    insertAtEnd(&head, '0');
    insertAtEnd(&head, '1');

    // (a) Initial Traversal
    std::cout << "(a) Initial List: ";
    listTraversal(head); // Output: CPE101

    // (b) Insert element 'G' at head (output -> GCPE101)
    insertAtHead(&head, 'G');
    std::cout << "(b) After inserting 'G' at start: ";
    listTraversal(head); // Output: GCPE101

    // (c) Insert element 'E' after previous node 'P' (output -> GCPEE101)
    Node* temp = head;
    while (temp != nullptr && temp->data != 'P') {
        temp = temp->next;
    }
    insertAfter(temp, 'E');
    std::cout << "(c) After inserting 'E' after 'P': ";
    listTraversal(head); // Output: GCPEE101

    // (d) Delete node containing 'C'
    deleteNode(&head, 'C');
    std::cout << "(d) After deleting 'C': ";
    listTraversal(head); // Output: GPEE101

    // (e) Delete node containing 'P'
    deleteNode(&head, 'P');
    std::cout << "(e) After deleting 'P': ";
    listTraversal(head); // Output: GEE101

    // (f) Show final elements in the list (output -> GEE101)
    std::cout << "(f) Final List Elements: ";
    listTraversal(head); // Output: GEE101

    // Memory Cleanup
    while (head != nullptr) {
        Node* next_node = head->next;
        delete head;
        head = next_node;
    }

    return 0;
}