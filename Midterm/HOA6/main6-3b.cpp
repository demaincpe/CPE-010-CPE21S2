// main.cpp for Table 6-3b testing 3 Cases (Found Middle, Found Boundary, Not Found)
#include <iostream>
#include "nodes.h"
#include "searching6-3b.h"

int main() {
    // Construct sorted linked list: 10 -> 20 -> 30 -> 40 -> 50
    Node<int>* head = new_node(10);
    head->next = new_node(20);
    head->next->next = new_node(30);
    head->next->next->next = new_node(40);
    head->next->next->next->next = new_node(50);

    std::cout << "Case 1 (Search Middle 30): ";
    binarySearchLL(head, 30);

    std::cout << "Case 2 (Search Boundary 50): ";
    binarySearchLL(head, 50);

    std::cout << "Case 3 (Search Non-existent 15): ";
    binarySearchLL(head, 15);

    return 0;
}