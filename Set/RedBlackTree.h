#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include "Tree.h"

typedef int T;                  /* type of item to be stored */
typedef enum { BLACK, RED } nodeColor; /* Red-Black tree description */


struct Node {
    struct Node *left;         /* left child */
    struct Node *right;        /* right child */
    struct Node *parent;       /* parent */
    nodeColor color;            /* node color (BLACK, RED) */
    T data;                     /* data stored in node */
};

class RedBlackTree: public Tree {
public:

    class Iterator;
    //typedef Iterator iterator;

    RedBlackTree();
    ~RedBlackTree();
    // RedBlackTree(const RedBlackTree &original);
    bool findNode(T key);
    void insertNode(T data);
    void deleteNode(T key);
    void clear();
    void show();

    Iterator begin();
    Iterator end();

private:

    Node *root;                 /* root of Red-Black tree */

    void insertFixup(Node *x);
    void deleteFixup(Node *x);
    void rotateLeft(Node *x);
    void rotateRight(Node *x);

    static void consoleOutput(Node *node, int level);
    static void remove(Node *node);
    static void inOrder(Node *node, void (*function)(Node *node, int level), int &level);
    static void postOrder(Node *node, void (*function)(Node *node));

};

class RedBlackTree::Iterator {
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

private:
    Node *current;
};



#endif // REDBLACKTREE_H_INCLUDED
