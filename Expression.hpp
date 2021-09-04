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
    explicit Expression(String);
    void testWrite();
    double calculate();
protected:
    virtual int getPrior(const String&);
    bool compareOp(const String& a, const String& b);
    void slice();
    void convert();
    String rawExpr;
    Queue<String> calQueue;
    Stack<String> opStack;
    Queue<String> slicedExpr;
    Stack<String> calStack;
};