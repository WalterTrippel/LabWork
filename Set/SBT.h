#ifndef SBT_H_INCLUDED
#define SBT_H_INCLUDED

#include "Tree.h"

typedef int T;

class Iterator;

class SBT: public Tree {

public:
    class Iterator;
    typedef Iterator iterator;
    SBT();
    ~SBT();
    bool findNode(T key);
    void insertNode(T data);
    void deleteNode(T key);
    void clear();
    void show();

    Iterator begin();
    Iterator end();

protected:
    struct Node {
        Node(T data = 0);
        ~Node();
        Node *left;
        Node *right;
        Node *parent;
        T data;
    }*root;

private:
    static void consoleOutput(Node *node, int level);
    static void remove(Node *node);
    static void inOrder(Node *node, void (*function)(Node *node, int level), int &level);
    static void postOrder(Node *node, void (*function)(Node *node));
};

class SBT::Iterator {
public:
    Iterator();
    Iterator(Node *node);
    ~Iterator();
    //Iterator(const Iterator &original);
    // Iterator &operator=(const Iterator &right);

    T  &operator *() const;
    Iterator operator++();

    bool operator==(const Iterator &right) const;
    bool operator!=(const Iterator &right) const;

//private:
    Node *current;
};


#endif // SBT_H_INCLUDED
