// main.cpp for Table 6-2b
#include <iostream>
#include "nodes.h"
#include "searching6-2b.h"

int main() {
    // Linked list using first name: JAIME
    Node<char>* name1 = new_node('J');
    Node<char>* name2 = new_node('a');
    Node<char>* name3 = new_node('i');
    Node<char>* name4 = new_node('m');
    Node<char>* name5 = new_node('e');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = nullptr;

    std::cout << "Searching for 'm':\n";
    linearLS(name1, 'm');

    std::cout << "Searching for 'n':\n";
    linearLS(name1, 'z');

    return 0;
}