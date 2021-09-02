#include <iostream>
//#include "SeqStack.hpp"
//#include "SeqQueue.hpp"
//#include "SinglyLinkedStack.hpp"
//#include "LinkedQueue.hpp"
#include "Expression.hpp"

int main() {
    Expression a = Expression("2^1023");
    a.testWrite();
    std::cout<<"\nResault:\t"<<a.calculate()<<std::endl;
    return 0;
}
