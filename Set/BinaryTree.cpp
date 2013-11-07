#include "SBT.h"
#include <cstdlib>
#include <iostream>

SBT::Node::Node(T data):
    left(0),
    right(0),
    parent(0),
    data(data) {
}

SBT::Node::~Node() {
    parent =0;
    left = 0;
    right = 0;
    data = 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

SBT::SBT():
    root(0) {
}


SBT::~SBT() {
    clear();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

bool SBT::findNode(T key) {
    Node *current = root;
    while(current != 0)
        if(key == current->data)
            return true;
        else
            current = key < current->data ?
                      current->left : current->right;
    return false;
}

void SBT::insertNode(T data) {
    Node *current, *parent, *x;

    /* find where node belongs */
    current = root;
    parent = 0;
    while (current != 0) {
        if (data == current->data) return;
        parent = current;
        current = data < current->data ?
                  current->left : current->right;
    }

    x = new Node;
    x->data = data;
    x->parent = parent;
    x->left = 0;
    x->right = 0;

    /* insert node in tree */
    if(parent) {
        if(data < parent->data)
            parent->left = x;
        else
            parent->right = x;
    } else {
        root = x;
    }
}

void SBT::deleteNode(T key) {

    Node *z = root;
    while(z != 0)
        if(key == z->data)
            break;
        else
            z = key < z->data ?
                z->left : z->right;

    Node *x, *y;

    if (!z) return;

    if (z->left == 0 || z->right == 0) {
        /* y has a NIL node as a child */
        y = z;
    } else {
        /* find tree successor with a NIL node as a child */
        y = z->right;
        while (y->left != 0) y = y->left;
    }

    /* x is y's only child */
    if (y->left != 0)
        x = y->left;
    else
        x = y->right;

    /* remove y from the parent chain */
    x->parent = y->parent;
    if (y->parent)
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    else
        root = x;

    if (y != z) z->data = y->data;



    delete y;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void SBT::show() {
    system("clear");
    int level = 0;
    if(root)
        inOrder(root, consoleOutput,level);
    else
        std::cout<<"EMPTY o_O\n";
}


void SBT::clear() {
    postOrder(root,remove);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void SBT::inOrder(Node *node, void (*function)(Node *node, int level), int &level) {
    if (node->right != 0) {
        ++level;
        inOrder(node->right, function, level);
    }
    function(node,level);
    level--;
    if (node->left != 0) {
        level+=2;
        inOrder(node->left, function, level);
        level--;
    }
}

void SBT::postOrder(Node *node, void (*function)(Node *node)) {

    if (node->left != 0)
        postOrder(node->left, function);

    if (node->right!= 0)
        postOrder(node->right, function);

    function(node);

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void SBT::consoleOutput(Node *node, int level) {
    for(int i=0; i<level; ++i )
        std::cout<<"   ";
    std::cout<<node->data<<"\n";
}

void SBT::remove(Node *node) {
    delete node;
    node = 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

SBT::Iterator SBT::begin() {
    Node *current = root;

    if(current)
        while(current->left != 0)
            current = current->left;

    return Iterator(current);
}

SBT::Iterator SBT::end() {
    return Iterator(0);
}

SBT::iterator it;

T SBT::getFirstNodeData(){
    it = this->begin();

    if(it.current)
        return *it;
    else
        return 0;
}

T SBT::getNextNodeData(){
    ++it;
    return *it;
}

T SBT::getLastNodeData(){

    iterator preIt;

    while(it != 0)
    {
        preIt = it;
        ++it;
    }
    return *preIt;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


SBT::Iterator::Iterator():
    current(0) {
}

SBT::Iterator::Iterator(Node *node):
    current(node) {
}

SBT::Iterator::~Iterator() {
    current = 0;
}

T SBT::Iterator::operator *() const {
    return this->current->data;
}

SBT::Iterator SBT::Iterator::operator++() {
    if(current) {
        if(current->right != 0) {
            current = current->right;

            while(current->left != 0)
                current = current->left;
        } else {

            if(current->parent != 0) {
                if(current->parent->left == current)
                    current = current->parent;
                else {
                    while(current->parent && current->parent->left != current) {
                        current =  current->parent;
                        if(current->parent == 0) {
                            current = 0;
                            return *this;
                        }
                    }
                    if(current != 0)
                        current =  current->parent;
                }
            } else current = 0;
        }
    }
    return *this;
}

bool SBT::Iterator::operator==(const Iterator &right) const {
    return current == right.current;
}

bool SBT::Iterator::operator!=(const Iterator &right) const {
    return !(current == right.current);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
