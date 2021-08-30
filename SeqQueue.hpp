#pragma once
#include <iostream>
#ifndef QUEUE_SIZE
#define QUEUE_SIZE 10
#endif
template <typename T>
class SeqQueue{
public:
    SeqQueue();
    ~SeqQueue() = default;
    void Enqueue(T data);
    T Dequeue();
    template <typename DT>
    friend std::ostream& operator<<(std::ostream& os, SeqQueue<DT>& queue);
private:
    T data[QUEUE_SIZE];
    T& operator[](int i);
    int head, rear;
};

template<typename T>
T &SeqQueue<T>::operator[](int i) {
    return(data[i % QUEUE_SIZE]);
}

template<typename T>
SeqQueue<T>::SeqQueue(): head(0), rear(0) {

}

template<typename T>
void SeqQueue<T>::Enqueue(T _data) {
    if(rear - head >= QUEUE_SIZE) throw "Queue overflow. (void SeqQueue<T>::Enqueue(T data))";
    (*this)[rear++] = _data;
}

template<typename T>
T SeqQueue<T>::Dequeue() {
    if(rear == head) throw "Queue underflow. (T SeqQueue<T>::Dequeue())";
    T rtn = (*this)[head++];
    return rtn;
}

template<typename DT>
std::ostream &operator<<(std::ostream &os, SeqQueue<DT> &queue) {
    if(queue.rear - queue.head == 0) {
        os<<"Empty queue."<<std::endl;
        return os;
    }
    for(int i = 0; i<QUEUE_SIZE; i++){
        os<<"\nIndex:  "<<i<<
        "\tData:  "<<queue.data[i];
    }
    os<<"\nhead: "<<queue.head<<"\trear: "<<queue.rear;
    for(int i = queue.head; i<queue.rear; i++){
        os<<"\nInnerIndex:  "<<i<<
        "\tData:  "<<queue[i];
    }
    return os;
}
