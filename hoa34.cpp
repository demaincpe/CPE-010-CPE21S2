#include <iostream>

class Node {
public:
    char data;
    Node* next;
    Node* prev; // Added pointer to previous node
};

// List Traversal (Forward)
void listTraversal(Node* n) {
    while (n != nullptr) {
        std::cout << n->data;
        n = n->next;
    }
    std::cout << std::endl;
}

// Insertion at Head
void insertAtHead(Node** head_ref, char new_data) {
    // 1. Allocate memory for new node
    Node* new_node = new Node();
    
    // 2. Assign data and set pointers
    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = nullptr; // New head's prev is always null

    // 3. Update old head's prev pointer if list was not empty
    if (*head_ref != nullptr) {
        (*head_ref)->prev = new_node;
    }

    // 4. Reset head to point to new node
    *head_ref = new_node;
}

// Insertion after a specific previous node
void insertAfter(Node* prev_node, char new_data) {
    if (prev_node == nullptr) {
        std::cout << "Previous node cannot be null.\n";
        return;
    }

    // 1. Allocate new node and store data
    Node* new_node = new Node();
    new_node->data = new_data;

    // 2. Set pointers for new node
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    // 3. Set new node as prev of prev_node's next node
    if (prev_node->next != nullptr) {
        prev_node->next->prev = new_node;
    }

    // 4. Point prev_node's next to new node
    prev_node->next = new_node;
}

// Insertion at the End
void insertAtEnd(Node** head_ref, char new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = nullptr;

    // If list is empty, new node becomes head
    if (*head_ref == nullptr) {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    while (last->next != nullptr) {
        last = last->next;
    }

    // Link last node and new node
    last->next = new_node;
    new_node->prev = last;
}

// Deletion of a node containing target data
void deleteNode(Node** head_ref, char key) {
    Node* temp = *head_ref;

    // Search for the node to delete
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    // Key not found
    if (temp == nullptr) return;

    // If node to be deleted is head node
    if (*head_ref == temp) {
        *head_ref = temp->next;
    }

    // Change next only if node to be deleted is NOT the last node
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    // Change prev only if node to be deleted is NOT the first node
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    // Free memory
    delete temp;
}

int main() {
    Node* head = nullptr;

    // Build initial list "CPE101"
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