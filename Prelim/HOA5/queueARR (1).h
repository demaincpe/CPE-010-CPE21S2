#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>

template <typename T>
class queueArr {
private:
    // Pointer to dynamically allocated array
    T* q_array;
    // Maximum number of elements a queue can hold
    size_t q_capacity;
    // Current number of elements in the queue
    size_t q_size;
    // Index of the front element
    int q_front;
    // Index of the back element
    int q_back;

public:
    // Constructor
    queueArr(size_t capacity = 10);
    // Copy Constructor
    queueArr(const queueArr& other);
    // Copy Assignment Operator
    queueArr& operator=(const queueArr& other);
    // Destructor
    ~queueArr();

    // Queue Operations
    bool Empty();
    bool Full();
    size_t Size();
    void Clear();
    T Front();
    T Back();
    void Enqueue(T value);
    T Dequeue();
};

// Constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    q_capacity = capacity;
    q_array = new T[q_capacity];
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

// Copy Constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }
}

// Copy Assignment Operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other) {
    if (this != &other) {
        delete[] q_array;
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        q_array = new T[q_capacity];
        for (size_t i = 0; i < q_capacity; i++) {
            q_array[i] = other.q_array[i];
        }
    }
    return *this;
}

// Destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array;
}

// Empty()
template <typename T>
bool queueArr<T>::Empty() {
    return q_size == 0;
}

// Full()
template <typename T>
bool queueArr<T>::Full() {
    return q_size == q_capacity;
}

// Size()
template <typename T>
size_t queueArr<T>::Size() {
    return q_size;
}

// Front()
template <typename T>
T queueArr<T>::Front() {
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T();
    }
    return q_array[q_front];
}

// Back()
template <typename T>
T queueArr<T>::Back() {
    if (Empty()) {
        std::cout << "Queue is empty\n";
        return T();
    }
    return q_array[q_back];
}

// Clear()
template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

// Enqueue() - Completed based on handout instructions
template <typename T>
void queueArr<T>::Enqueue(T value) {
    // 1. Check if the queue is FULL
    if (Full()) {
        std::cout << "Queue Overflow! Cannot enqueue " << value << "\n";
        return;
    }
    // 2. Move q_back circularly
    q_back = (q_back + 1) % q_capacity;
    // 3. Store the value at the back
    q_array[q_back] = value;
    // 4. Increment the q_size
    q_size++;
}

// Dequeue() - Completed based on handout instructions
template <typename T>
T queueArr<T>::Dequeue() {
    // 1. Check if empty
    if (Empty()) {
        std::cout << "Queue Underflow! Cannot dequeue\n";
        return T();
    }
    // 2. Create a temporary variable to store the current front
    T tempVar = q_array[q_front];
    
    // 3. Move q_front circularly
    q_front = (q_front + 1) % q_capacity;
    
    // 4. Decrement the q_size
    q_size--;
    
    // 5. Reset the indexes if the queue becomes empty
    if (Empty()) Clear();
    
    // 6. Return the temporary variable
    return tempVar;
}

#endif