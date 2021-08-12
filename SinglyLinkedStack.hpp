//
// Created by Administrator on 2021/8/12.
//
#pragma once

#include <iostream>

#include "AbLinkedStruct.hpp"
#include "Node.hpp"

template<typename T>
class SinglyLinkedStack : AbLinkedStruct<T>{
public:
    SinglyLinkedStack();
    SinglyLinkedStack(T* pData, int number);
    T* toArray();
    int indexOf(T&);
    T getByIndex(int);
    int getLength();
    void insert(T&, int);
    T del(int);
    bool isEmpty();
    template<typename DT>
    friend std::ostream& operator<<(std::ostream& os, SinglyLinkedStack<DT>& stack);
private:
    SNode<T>* pStart;
    int length;
};

template<typename T>
SinglyLinkedStack<T>::SinglyLinkedStack(): pStart(new SNode<T>),length(0) {
    pStart->data = nullptr;
    pStart->next = nullptr;
}

template<typename T>
SinglyLinkedStack<T>::SinglyLinkedStack(T* pData, int number): pStart(new SNode<T>),length(number) {
    SNode<T>* p = pStart;
    for(int i = 0; i<number; i++){
        p->next = new SNode<T>(pData[i]);
        p = p->next;
    }
}

template<typename T>
void SinglyLinkedStack<T>::insert(T& rData, int index) {
    SNode<T>* p = pStart,* pNew = new SNode<T>(rData);
    if(index > length) throw "Invalid index.(SinglyLinkedStack<T>::insert(T& rData, int index))";
    for(int i = 0; i < index; i++){
        p = static_cast<SNode<int> *>(p->next);
    }
    pNew = p->next;
    p->next = pNew;
    length++;
}

template<typename DT>
std::ostream &operator<<(std::ostream &os, SinglyLinkedStack<DT> &stack) {
    SNode<DT>* p = stack.pStart;
    os<<"Length:\t"<<stack.length;
    for(int i = 0; i<stack.length; i++){
        os<<p;
        p = p->next;
    }
    return os;
}
