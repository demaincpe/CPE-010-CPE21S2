// Linear Search on Linked List for Table 6-2b
template <typename T>
void linearLS(Node<T>* head, T dataFind) {
    Node<T>* curr = head;
    while (curr != nullptr) {
        if (curr->data == dataFind) {
            std::cout << "Searching is successful\n";
            return;
        }
        curr = curr->next;
    }
    std::cout << "Searching is Unsuccessful\n";
}