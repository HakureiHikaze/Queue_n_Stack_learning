#include <iostream>
//#include "SeqStack.hpp"
//#include "SeqQueue.hpp"
//#include "SinglyLinkedStack.hpp"
//#include "LinkedQueue.hpp"
#include "Expression.hpp"

int main() {
    Expression a = Expression("768+sin(7)+tg(22.5)*keng(hsh(2)^hh(8))-0.35sin(22)");
    a.testWrite();
    return 0;
}
