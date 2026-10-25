#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int sequentialSearchArray(const int arr[], int size, int key, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int sequentialSearchLL(Node* head, int key, int& comparisons) {
    comparisons = 0;
    Node* curr = head;
    while (curr != nullptr) {
        comparisons++;
        if (curr->data == key) return curr->data;
        curr = curr->next;
    }
    return -1;
}

int main() {
    int data[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = 10;
    int key = 18;
    int comparisons = 0;

    // 1. Array Approach
    sequentialSearchArray(data, size, key, comparisons);
    std::cout << "[Array] Total comparisons to find key " << key << ": " << comparisons << "\n";

    // 2. Linked List Approach
    Node* head = new Node(data[0]);
    Node* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = new Node(data[i]);
        curr = curr->next;
    }

    sequentialSearchLL(head, key, comparisons);
    std::cout << "[Linked List] Total comparisons to find key " << key << ": " << comparisons << "\n";

    return 0;
}