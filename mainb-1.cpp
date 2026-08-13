#include <iostream>
#include "queueLL.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('J', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    enqueue('A', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    enqueue('I', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    enqueue('M', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    enqueue('E', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;

    // Printing all elements in order
    displayAll(front);

    std::cout<<"testing the dequeue operator: \n";
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    dequeue(&front, &back);
    dequeue(&front, &back);
    dequeue(&front, &back);
    dequeue(&front, &back);

    // Checking if empty
    if (isEmpty(front)) {
        std::cout << "The queue is currently empty.\n";
    }
    return 0;
}