//
// Created by Administrator on 2021/8/12.
//
#pragma once
#include "Node.hpp"
template<typename T>
class AbLinkedStruct{
public:
    virtual ~AbLinkedStruct<T>() = 0;
    virtual T* toArray() = 0;
    virtual int indexOf(T&) = 0;
    virtual T getByIndex(int) = 0;
    virtual int getLength() = 0;
    virtual void insert(T&, int) = 0;
    virtual T del(int) = 0;
    virtual bool isEmpty() = 0;
};