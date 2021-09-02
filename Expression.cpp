//
// Created by hikaze on 2021/9/2.
//

#include "Expression.hpp"

bool Expression::compareOp(char a, char b) {
    if(getPrior(a)> getPrior(b))return true;
    else return false;
}

int Expression::getPrior(char ch) {
    switch (ch) {
        case'#':
            return 0;
        case'+':case'-':
            return 10;
        case'*':case'/':
            return 15;
        default:
            throw "Unspecified character. (int Expression::getPrior(char ch) )";
    }
}

Expression::~Expression() {

}

Expression::Expression() {

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
            if(ch == '('){
                str.push_back(ch);
                slicedExpr.Enqueue(str);
                str = "";
                flag = 0;
                continue;
            }
            if(flag == 1){
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
    slicedExpr<<std::endl;
}

Expression::Expression(String str) : rawExpr(str) {
    slice();
}
