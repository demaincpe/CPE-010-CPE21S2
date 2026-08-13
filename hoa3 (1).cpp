#include <iostream>
#include "singly_ll.h"

int main() {

    //creation of nodes "JLMD"
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;

    //allocate 4 nodes in the heap
    head = new SingleList<char>();
    second = new SingleList<char>();
    third = new SingleList<char>();
    fourth = new SingleList<char>();

    //store data in nodes
    head->data = 'J';
    second->data = 'L';
    third->data = 'M';
    fourth->data = 'D';

    //connect nodes
    head->next = second; //connect first node with the second node
    second->next = third; //connect second node with the third node
    third->next = fourth; //connect third node with the fourth node
    fourth->next = nullptr; //connect fourth node with the null pointer

    std::cout << "Testing of Traversal:\n";
    ListTraversal(head);

    // Test insertion at head
    std::cout << "\nTesting of sllinsertHead:\n";
    sllinsertHead('D', &head);
    ListTraversal(head);

    std::cout << "\nTesting of sllGeneralInsert:\n";
    sllGeneralInsert('X', head->next->next); // Insert 'X' after the second node
    ListTraversal(head);

    std::cout << "\nTesting of sllinsertEnd:\n";
    sllinsertEnd('Z', &head); // Insert 'Z' at the end of the list
    ListTraversal(head);
    std::cout << "\nTesting of deleting the node:\n";
    sllDeleteNode('M', &head);
    ListTraversal(head);

    std::cout << "\nDeleting All nodes:\n";
    sllDeleteList(&head);
    ListTraversal(head);

    return 0;
}