#pragma once
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
    template<typename DT>
    friend std::ostream& operator<<(std::ostream& os, LinkedQueue<DT>& queue);
private:
    Node<T>* head,* rear;
};

template<typename T>
LinkedQueue<T>::LinkedQueue() {
    auto* p = new Node<T>();
    head = rear = p;
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
    Node<T>* p = head->pNext;
    T rtn = p->data;
    head->pNext = p->pNext;
    delete p;
    return rtn;
}

template<typename T>
T LinkedQueue<T>::GetHead() {
    return head->pNext->data;
}

template<typename T>
bool LinkedQueue<T>::isEmpty() {
    if(head == rear) return true;
    else return false;
}

template<typename DT>
std::ostream &operator<<(std::ostream &os, LinkedQueue<DT> &queue) {
    Node<DT>* p = queue.head;
    os<<"\nHead:\t"<<(void*)p<<std::endl;
    os<<*p;
    for(;p->pNext != nullptr;){
        p = p->pNext;
        os<<*p;
    }
    os<<"\nRear:\t"<<(void*)p<<std::endl;
    return os;
}
