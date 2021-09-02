#pragma once
#include <iostream>
template <typename T>
class Node{
public:
    Node();
    Node<T>* pNext;
    T data;
    template <typename DT>
    friend std::ostream& operator<<(std::ostream& os, Node<DT>& node);
};
template <typename T>
Node<T>::Node(){
    pNext = nullptr;
}

template <typename DT>
std::ostream & operator<<(std::ostream& os, Node<DT>& node){
    os<<
    //"\nAddr:\t"<<(void*) &node<<
    //"\nNext:\t"<<(void*) node.pNext<<
    /*"\nData:*/"\t"<<node.data;//<<std::endl;
    return os;
}