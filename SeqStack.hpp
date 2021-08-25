#include<iostream>

#ifndef STACK_SIZE
#define STACK_SIZE 10
#endif

template <typename T>
class SeqStack{
public:
    SeqStack();
    ~SeqStack(){}
    void Push(T x);
    T Pop();
    T GetTop();
    bool isEmpty();
    template <typename DT>
    friend std::ostream& operator<<(std::ostream& os, const SeqStack<DT>& stack);
private:
    T data[STACK_SIZE];
    int indexTop;
};

template <typename T>
SeqStack<T>::SeqStack(){
    indexTop = -1;
}

template <typename T>
void SeqStack<T>::Push(T x){
    if(indexTop == STACK_SIZE - 1) throw "Stack overflow.(SeqStack<T>::Push(T x))";
    data[++indexTop] = x;
}

template <typename DT>
std::ostream& operator<<(std::ostream& os, const SeqStack<DT>& stack){
    if(stack.indexTop == -1) {
        os<<"Empty stack."<<std::endl;
        return os;
    }
    for(int i = stack.indexTop; i>=0; i--){
        os<<"\nIndex:  "<<i<<"\tData:  "<<stack.data[i];
    }
    return os;
}