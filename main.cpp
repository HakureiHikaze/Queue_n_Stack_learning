#include <iostream>
#include "SeqStack.hpp"
#include "SeqQueue.hpp"
#include "SinglyLinkedStack.hpp"

int main() {
    //int a[10] = {0,1,2,3,4,5,6,7,8,9};
    SeqQueue<std::string> test3 = SeqQueue<std::string>();
    std::string s[10] = {"易","赵信","卡尔萨斯","卡兹克","霞","艾翁","格雷福斯","提莫","瑟庄妮","安妮"};
    for(const std::string& i : s){
        test3.Enqueue(i);
    }
    std::cout<<test3.Dequeue()<<std::endl;
    std::cout<<test3.Dequeue()<<std::endl;
    test3.Enqueue((std::string)"马尔扎哈");
    std::cout<<test3<<std::endl;
    return 0;
}
