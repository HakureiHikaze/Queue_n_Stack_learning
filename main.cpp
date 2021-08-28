#include <iostream>
#include "SeqStack.hpp"
#include "SinglyLinkedStack.hpp"

int main() {
    SeqStack<int> test = SeqStack<int>();
    SinglyLinkedStack<int> test1 = SinglyLinkedStack<int>();
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    for(int i : a){
        test1.Push(i);
    }
    test1.Push(5);
    std::cout<<test1<<std::endl;
    return 0;
}
