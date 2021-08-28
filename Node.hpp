#include <iostream>
#ifdef SNODE
template <typename T>
class Node{
public:
    Node<T>* pNext;
    T data;
    friend std::ostream& operator<<(const std::ostream& os, const Node<T>& node);
};

template <typename T>
std::ostream & operator<<(const std::ostream& os, const Node<T>& node){
    os<<
    "\nAddr:\t"<<(void*) &node<<
    "\nNext:\t"<<(void*) node.pNext<<
    "\nData:\t"<<node.data<<std::endl;
    return os;
}
#endif