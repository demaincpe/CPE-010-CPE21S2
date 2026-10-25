#include <iostream>
#include "queueLL-1.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('1', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    enqueue('2', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    enqueue('3', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    enqueue('2', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    enqueue('1', &front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;

    // Printing all elements in order for queue 1
    displayAll(front);

    std::cout<<"testing the dequeue operator: \n";
    dequeue1(&front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    dequeue1(&front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    dequeue1(&front, &back);
    dequeue1(&front, &back);
    dequeue1(&front, &back);
    dequeue1(&front, &back);

    // Printing all elements in order for queue 2
    displayAll(front);

    std::cout<<"testing the dequeue operator: \n";
    dequeue2(&front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    dequeue2(&front, &back);
    std::cout<<"front: "<< front->data << " " << "back: "<< back->data<<std::endl;
    dequeue2(&front, &back);
    dequeue2(&front, &back);
    dequeue2(&front, &back);
    dequeue2(&front, &back);


    // Checking if empty
    if (isEmpty(front)) {
        std::cout << "The queue is currently empty.\n";
    }
    return 0;
}