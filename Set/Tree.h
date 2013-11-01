#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

//#include "SBT.h"
//#include "RedBlackTree.h"

typedef int T;

class Tree{
public:
    bool find(T key);
    void insert(T data);
    void remove(T key);
    void destroy();
    T getFirst();
    T getNext();
    T getLast();
private:
    virtual bool findNode(T key) = 0;
    virtual void insertNode(T data) = 0;
    virtual void deleteNode(T key) = 0;
    virtual void clear() = 0;

};


#endif // TREE_H_INCLUDED
