// getMiddle using Tortoise-and-Hare (Two Pointers)
template <typename T>
Node<T>* getMiddle(Node<T>* startNode, Node<T>* lastNode) {
    if (startNode == nullptr) return nullptr;

    Node<T>* slow = startNode;
    Node<T>* fast = startNode->next;

    while (fast != lastNode) {
        fast = fast->next;
        if (fast != lastNode) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// Binary Search on Linked List
template <typename T>
Node<T>* binarySearchLL(Node<T>* head, T key) {
    Node<T>* startNode = head;
    Node<T>* lastNode = nullptr;

    do {
        Node<T>* mid = getMiddle(startNode, lastNode);

        if (mid == nullptr) return nullptr;

        if (mid->data == key) {
            std::cout << "Search element is found!\n";
            return mid;
        } else if (mid->data < key) {
            startNode = mid->next; // Search right half
        } else {
            lastNode = mid; // Search left half
        }
    } while (lastNode == nullptr || lastNode != startNode);

    std::cout << "Search element is not found\n";
    return nullptr;
}