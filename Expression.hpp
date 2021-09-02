//
// Created by hikaze on 2021/9/2.
//

#pragma ocne
#include <string>
#include "SinglyLinkedStack.hpp"
#include "LinkedQueue.hpp"
#define String std::string
#define Queue LinkedQueue
#define Stack SinglyLinkedStack

class Expression {
public:
    Expression();
    Expression(String);
    virtual ~Expression();
    void testWrite();
protected:
    virtual int getPrior(char);
    bool compareOp(char a, char b);
    void slice();
    String rawExpr;
    Stack<char> numStack;
    Stack<char> opStack;
    Queue<String> slicedExpr;
};