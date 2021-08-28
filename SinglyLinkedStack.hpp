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
    T GetTop();
    bool isEmpty();
    template <typename DT>
    friend std::ostream& operator<<(std::ostream& os, SinglyLinkedStack<DT>& stack);
private:
    Node<T>* pTop;
};

template<typename T>
SinglyLinkedStack<T>::SinglyLinkedStack() {
    pTop = nullptr;
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

template<typename T>
void SinglyLinkedStack<T>::Push(T data) {
    auto* p = new Node<T>();
    p->pNext = pTop;
    p->data = data;
    pTop = p;
}

template<typename T>
T SinglyLinkedStack<T>::Pop() {
    if(pTop == nullptr) throw "Stack underflow. T SinglyLinkedStack<T>::Pop();";
    Node<T>* p = pTop;
    T rtn = p->data;
    pTop = p->pNext;
    delete p;
    return rtn;

}

template<typename T>
T SinglyLinkedStack<T>::GetTop() {
    if(pTop == nullptr) throw "Stack underflow. T SinglyLinkedStack<T>::GetTop();";
    return pTop->data;
}

template<typename T>
bool SinglyLinkedStack<T>::isEmpty() {
    if(pTop == nullptr) return true;
    else return false;
}

template <typename DT>
std::ostream& operator<<(std::ostream& os, SinglyLinkedStack<DT> &stack) {
    if(stack.isEmpty()) {
        os<<"Empty stack."<<std::endl;
        return os;
    }
    else {
        Node<DT>* p = stack.pTop;
        while(p != nullptr){
            os<<*p;
            p = p->pNext;
        }
        return os;
    }
}
