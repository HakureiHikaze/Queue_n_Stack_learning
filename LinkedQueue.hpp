#pragma once
#define SNODE
#include "Node.hpp"

template <typename T>
class LinkedQueue{
public:
    LinkedQueue();
    ~LinkedQueue();
    void Enqueue(T data);
    T Dequeue();
    T GetHead();
    bool isEmpty();
private:
    Node<T>* head,* rear;
};

template<typename T>
LinkedQueue<T>::LinkedQueue(): head(nullptr), rear(nullptr) {

}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    Node<T>* p = head->pNext;
    do {
        delete head;
        head = p;
        p = p->pNext;
    } while (rear != head);
}

template<typename T>
void LinkedQueue<T>::Enqueue(T data) {
    auto* p = new Node<T>();
    p->data = data;
    rear->pNext = p;
    rear = p;
}

template<typename T>
T LinkedQueue<T>::Dequeue() {
    Node<T>* p = head;
    T rtn = p->data;
    head = p->pNext;
    delete p;
    return rtn;
}

template<typename T>
T LinkedQueue<T>::GetHead() {
    return head->data;
}

template<typename T>
bool LinkedQueue<T>::isEmpty() {
    if(head == rear) return true;
    else return false;
}
