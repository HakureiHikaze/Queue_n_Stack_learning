#define SNODE
#include <iostream>
#include "Node.hpp"

template <typename T>
class SinglyLinkedStack{
public:
    SinglyLinkedStack();
    ~SinglyLinkedStack();
    void Push(T data);
    T Pop();
    T GetPop();
    bool isEmpty();
    friend std::ostream & operator<<(const std::ostream&os, const SinglyLinkedStack<T>& stack);
private:
    Node<T>* pTop;
};

template<typename T>
SinglyLinkedStack<T>::SinglyLinkedStack() {
    pTop = new Node<T>();
    pTop->pNext = nullptr;
}

template<typename T>
SinglyLinkedStack<T>::~SinglyLinkedStack() {
    Node<T>* p = pTop;
    while(pTop != nullptr){
        p = pTop->pNext;
        delete pTop;
        pTop = p;
    }
}
