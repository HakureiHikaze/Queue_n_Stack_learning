#include <iostream>
//#include "SeqStack.hpp"
//#include "SeqQueue.hpp"
//#include "SinglyLinkedStack.hpp"
//#include "LinkedQueue.hpp"
#include "Expression.hpp"

int main() {
    Expression* a;
    std::string str;
    for(;;){
        std::cout<<"Type expression:\n";
        std::cin>>str;
        if (str == " ") break;
        a = new Expression(str);
        std::cout<<std::endl<<str<<"="<<a->calculate()<<std::endl;
        delete a;
    }
    return 0;
}
