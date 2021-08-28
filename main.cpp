#include <iostream>
#include "SeqStack.hpp"

int main() {
    SeqStack<int> test = SeqStack<int>();
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    for(int i : a){
        test.Push(i);
    }
    test.Push(5);
    std::cout<<test.Pop()<<test<<std::endl;
    return 0;
}
