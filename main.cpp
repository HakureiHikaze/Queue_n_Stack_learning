#include <iostream>
#include "SeqStack.hpp"
#include "SeqQueue.hpp"
#include "SinglyLinkedStack.hpp"

int main() {
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    SeqQueue<int> test3 = SeqQueue<int>();
    for(int i : a){
        test3.Enqueue(i);
    }
    std::cout<<test3.Dequeue()<<std::endl;
    std::cout<<test3.Dequeue()<<std::endl;
    test3.Enqueue(16);
    std::cout<<test3<<std::endl;
    return 0;
}
