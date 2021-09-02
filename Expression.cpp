//
// Created by hikaze on 2021/9/2.
//

#include "Expression.hpp"

#include <cmath>

#include <utility>

bool Expression::compareOp(const String& a, const String& b) {
    if(getPrior(a)> getPrior(b))return true;
    else return false;
}

int Expression::getPrior(const String& str) {
    if(str == "+" || str == "-")return 10;
    else if(str == "*"|| str == "/") return 15;
    else if(str == "^") return 20;
    else if(std::isalpha(str[0])) return 100;
    else if(str == "(") return 1;
    else if(str == "#") return 0;
    else throw "Unspecified character. (int Expression::getPrior(String str) )";
}

void Expression::slice() {
    if(rawExpr.empty()) throw "Empty Expression. (void Expression::slice())";
    String str;
    int flag = 0;
    for(char ch : rawExpr){
        if(std::isdigit(ch) || ch == '.') {
            if (flag != 0 && flag != 1) {
                slicedExpr.Enqueue(str);
                str = "";
            }
            str.push_back(ch);
            flag = 1;
        }
        else if(std::isalpha(ch) || ch == '('){
            if(flag == 2 && ch == '('){
                slicedExpr.Enqueue(str);
                str = "";
                str.push_back(ch);
                slicedExpr.Enqueue(str);
                str = "";
                flag = 0;
                continue;
            }
            else if(flag != 2 && ch == '('){
                if(flag != 0){
                    slicedExpr.Enqueue(str);
                    str = "";
                }
                str.push_back(ch);
                flag = 3;
                continue;
            }
            else if(flag == 1){
                slicedExpr.Enqueue(str);
                slicedExpr.Enqueue("*");
                str = "";
            }
            else if(flag == 3){
                slicedExpr.Enqueue(str);
                str="";
            }
            str.push_back(ch);
            flag = 2;
        }
        else{
            slicedExpr.Enqueue(str);
            str = "";
            str.push_back(ch);
            flag = 3;
        }
    }
    slicedExpr.Enqueue(str);
}

void Expression::testWrite() {
    std::cout<<std::endl<<
    rawExpr<<std::endl<<
    slicedExpr<<std::endl<<
    opStack<<std::endl<<
    calQueue<<std::endl;
}

Expression::Expression(String str) : rawExpr(std::move(str)) {
    slice();
    convert();
}

void Expression::convert() {
    opStack.Push("#");
    for(;!slicedExpr.isEmpty();){
        if(std::isdigit(slicedExpr.GetHead()[0]) ||slicedExpr.GetHead()[0] == '.'){
            calQueue.Enqueue(slicedExpr.Dequeue());
        }
        else if(slicedExpr.GetHead() == "("){
            opStack.Push(slicedExpr.Dequeue());
        }
        else if(slicedExpr.GetHead() == ")"){
            for(;opStack.GetTop()!= "(";){
                calQueue.Enqueue(opStack.Pop());
            }
            opStack.Pop();
            slicedExpr.Dequeue();
        }
        else{
            for(;!compareOp(slicedExpr.GetHead(), opStack.GetTop());){
                calQueue.Enqueue(opStack.Pop());
            }
            opStack.Push(slicedExpr.Dequeue());
        }
    }
    for(;opStack.GetTop() != "#";){
        calQueue.Enqueue(opStack.Pop());
        if(opStack.isEmpty())break;
    }
}

double Expression::calculate() {
    for(;!calQueue.isEmpty();){
        if(std::isdigit(calQueue.GetHead()[0]) || calQueue.GetHead()[0] == '.'){
            calStack.Push(calQueue.Dequeue());
        }
        else if(std::isalpha(calQueue.GetHead()[0])){
            double a = std::stod(calStack.Pop());
            if(calQueue.GetHead() == "cos"){
                calStack.Push(std::to_string(std::cos(a)));
                calQueue.Dequeue();
            }
            else if(calQueue.GetHead() == "sin"){
                calStack.Push(std::to_string(std::sin(a)));
                calQueue.Dequeue();
            }
            else if(calQueue.GetHead() == "tan"){
                calStack.Push(std::to_string(std::tan(a)));
                calQueue.Dequeue();
            }
        }
        else{
            double a = std::stod(calStack.Pop());
            double b = std::stod(calStack.Pop());
            if(calQueue.GetHead() == "+") { calStack.Push(std::to_string(b + a));calQueue.Dequeue(); }
            else if(calQueue.GetHead() == "-") { calStack.Push(std::to_string(b - a));calQueue.Dequeue(); }
            else if(calQueue.GetHead() == "*") { calStack.Push(std::to_string(b * a));calQueue.Dequeue(); }
            else if(calQueue.GetHead() == "/") { calStack.Push(std::to_string(b / a));calQueue.Dequeue(); }
            else if(calQueue.GetHead() == "^") { calStack.Push(std::to_string(std::pow(b, a)));calQueue.Dequeue(); }
        }
    }
    return std::stod(calStack.Pop());
}
