//
// Created by Administrator on 2021/8/12.
//
#pragma once
#include <iostream>
#ifdef TEST
template <typename T>
class AbNode{
public:
    virtual ~AbNode() = 0;
};

template <typename T>
class SNode : public AbNode<T>{
public:
    SNode()= default;
    SNode(T& rData, SNode<T>* _next) :data(new T), next(_next){
        *data = rData;
    }

    explicit SNode(T& rData) :data(new T){
        *data = rData;
    }

    ~SNode(){
        delete data;
    }

    T* data;
    SNode<T>* next;
    friend std::ostream& operator<<(std::ostream& os,const SNode& sNode){
        if(sNode.data == nullptr) throw "De-referencing a nullptr.";
        os<<
        "\nAddr:\t"<<(void*)&sNode<<
        "\nData:\t"<<*sNode.data<<
        "\nNext:\t"<<(void*)sNode.next<<
        std::endl;
        return os;
    }
};

template <typename T>
class DNode : public AbNode<T>{
public:
    DNode()= default;
    DNode(T& rData, DNode<T>* _next, DNode<T>* _prev) :data(new T), next(_next), prev(_prev){
        *data = rData;

    }
    explicit DNode(T& rData) :data(new T){
        *data = rData;
    }
    ~DNode(){
        delete data;
    }
    T* data;
    DNode<T>* next,* prev;
    friend std::ostream& operator<<(std::ostream& os,const DNode& dNode){
        if(dNode.data == nullptr) throw "De-referencing a nullptr.";
        os<<
        "\nPrev:\t"<<(void*)dNode.prior<<
        "\nAddr:\t"<<(void*)&dNode<<
        "\nData:\t"<<*dNode.data<<
        "\nNext:\t"<<(void*)dNode.next<<
        std::endl;
        return os;
    }
};
#endif

#ifdef DOUBLY_PTR_NODE
template <typename T>
class Node{
    T* data;
    Node<T>* next;
    Node<T>* prev;
    friend std::ostream& operator<<(std::ostream& os,const Node& node){
        if(node.data == nullptr) throw "De-referencing a nullptr.";
        os<<
        "\nPrev:\t"<<(void*)node.prev<<
        "\nAddr:\t"<<(void*)&node<<
        "\nData:\t"<<*node.data<<
        "\nNext:\t"<<(void*)node.next<<
        std::endl;
        return os;
};
#endif

#ifdef SINGLY_PTR_NODE
template <typename T>
class Node{
public:
    T* data;
    Node<T>* next;
    friend std::ostream& operator<<(std::ostream& os,const Node& node){
        if(node.data == nullptr) throw "De-referencing a nullptr.";
        os<<
        "\nAddr:\t"<<(void*)&node<<
        "\nData:\t"<<*node.data<<
        "\nNext:\t"<<(void*)node.next<<
        std::endl;
        return os;
    }
};
#endif