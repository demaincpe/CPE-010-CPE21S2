#ifndef SINGLY_LL_H
#define SINGLY_LL_H

template <typename T>
class SingleList {
    public:
    T data; //this contains the data of the node
    SingleList<T>* next = nullptr; //this contains the pointer to the next node
};

template <typename T>
void ListTraversal(SingleList<T>* head) {
    while (head != nullptr) {
        //PRINT data of n
        std::cout << head->data;
        if (head->next != nullptr) {
        std::cout << " -> ";
        }
        //GO TO NEXT NODE n := next
        head = head->next;
    }
}

template <typename T>
void sllinsertHead(T newData, SingleList<T>** currentHead) {
    //1. Allocate memory for new node
    SingleList<T>* newNode = new SingleList<T>();
    //2. Put our data into the new node
    newNode->data = newData;
    //3. Set Next of new node to point to the previous head
    newNode->next = *currentHead;
    //4. Reset head to point to the new node
    *currentHead = newNode;
}

template <typename T>
void sllGeneralInsert(T newData, SingleList<T>* preNode) {
    //1. Check if the given previous node is NULL
    if (preNode == nullptr) {
        //2. If the given previous node is NULL, we cannot insert a new node after it
        std::cout << "The given previous node cannot be NULL";
        return;
    }
    //3. Allocate a new node
    SingleList<T>* newNode = new SingleList<T>();
    //4. Store data in the new node
    newNode->data = newData;
    //5. Point new node's next to the previous node's next
    newNode->next = preNode->next;
    //6. Point previous node to the new node
    preNode->next = newNode;
}

template <typename T>
void sllinsertEnd(T newData, SingleList<T>** head){
    //1. Allocate a new node
    SingleList<T>* newNode = new SingleList<T>();
    //2. Dereference to the head node
    SingleList<T>* currentNode = *head;
    //3. Store data in the new node
    newNode->data = newData;
    //4. Point to Null
    newNode->next = nullptr;
    //5. Traverse the list to find the last node
    while (currentNode ->next != nullptr) {
        currentNode = currentNode->next;
    }
    //6. Point the last node's next to the new node
    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SingleList<T>** head) {

    //if there is nothing to be deleted?
    if (*head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    //search for the node to be deleted
    while (currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    //if the node to be deleted is not found
    if (currNode == nullptr) {
        std::cout << "the data is not found  \n";
        return;
    }

    //if data was found, delete the node
    if (prevNode == nullptr) {
        //the node to be deleted is the head node
        *head = currNode->next;
    } else {
        //the node to be deleted is not the head node
        prevNode->next = currNode->next;
    }

    delete currNode; //free memory
}

template <typename T>
void sllDeleteList(SingleList<T> **head){
    SingleList<T>* current = *head;

    while (current != nullptr) {
        SingleList<T>* temp = current;
        delete current; // Free memory of the current node
        current = current->next; // Move to the next node
        delete temp; // Free memory of the temporary node
    }

    *head = nullptr; // Set head to nullptr after deletion
}

#endif