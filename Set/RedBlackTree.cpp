#include "RedBlackTree.h"
#include <cstdlib>
#include <iostream>

#define NIL &sentinel           /* all leafs are sentinels */
Node sentinel = {NIL, NIL, 0, BLACK, 0};

RedBlackTree::RedBlackTree():
    root(NIL) {
}

RedBlackTree::~RedBlackTree() {
    clearImpl();
}


bool RedBlackTree::findImpl(T key) {
    Node *current = root;
    while(current != NIL)
        if(key == current->data)
            return (current);
        else
            current = key < current->data ?
                      current->left : current->right;
    return 0;
}

void RedBlackTree::insertImpl(void *pointer) {
    if(pointer) {
        Node *unpacked = (Node*)pointer;
        this->insertImpl(unpacked->data);
    }
}


void RedBlackTree::insertImpl(T data) {
    Node *current, *parent, *x;

    /* find where node belongs */
    current = root;
    parent = 0;
    while (current != NIL) {
        if (data == current->data) return;
        parent = current;
        current = data < current->data ?
                  current->left : current->right;
    }

    x = new Node;
    x->data = data;
    x->parent = parent;
    x->left = NIL;
    x->right = NIL;
    x->color = RED;

    /* insert node in tree */
    if(parent) {
        if(data < parent->data)
            parent->left = x;
        else
            parent->right = x;
    } else {
        root = x;
    }

    insertFixup(x);
}

void RedBlackTree::insertFixup(Node *x) {
    /* check Red-Black properties */
    while (x != root && x->parent->color == RED) {
        /* we have a violation */
        if (x->parent == x->parent->parent->left) {
            Node *y = x->parent->parent->right;
            if (y->color == RED) {
                /* uncle is RED */
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {
                /* uncle is BLACK */
                if (x == x->parent->right) {
                    /* make x a left child */
                    x = x->parent;
                    rotateLeft(x);
                }

                /* recolor and rotate */
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateRight(x->parent->parent);
            }
        } else {
            /* mirror image of above code */
            Node *y = x->parent->parent->left;
            if (y->color == RED) {
                /* uncle is RED */
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {
                /* uncle is BLACK */
                if (x == x->parent->left) {
                    x = x->parent;
                    rotateRight(x);
                }
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateLeft(x->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::removeImpl(T key) {

    Node *z = root;
    while(z != NIL)
        if(key == z->data)
            break;
        else
            z = key < z->data ?
                z->left : z->right;

    Node *x, *y;

    if (!z || z == NIL) return;

    if (z->left == NIL || z->right == NIL) {
        /* y has a NIL node as a child */
        y = z;
    } else {
        /* find tree successor with a NIL node as a child */
        y = z->right;
        while (y->left != NIL) y = y->left;
    }

    /* x is y's only child */
    if (y->left != NIL)
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


    if (y->color == BLACK)
        deleteFixup (x);

    delete y;
}

void RedBlackTree::deleteFixup(Node *x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node *w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft (x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight (w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft (x->parent);
                x = root;
            }
        } else {
            Node *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight (x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft (w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight (x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RedBlackTree::rotateLeft(Node *x) {
    Node *y = x->right;

    /* establish x->right link */
    x->right = y->left;
    if (y->left != NIL) y->left->parent = x;

    /* establish y->parent link */
    if (y != NIL) y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    } else {
        root = y;
    }

    /* link x and y */
    y->left = x;
    if (x != NIL) x->parent = y;
}

void RedBlackTree::rotateRight(Node *x) {
    Node *y = x->left;

    /* establish x->left link */
    x->left = y->right;
    if (y->right != NIL) y->right->parent = x;

    /* establish y->parent link */
    if (y != NIL) y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
    } else {
        root = y;
    }

    /* link x and y */
    y->right = x;
    if (x != NIL) x->parent = y;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
/*
RedBlackTree::Iterator::Iterator():
    current(0) {
}

RedBlackTree::Iterator::Iterator(Node *node):
    current(node) {
}

RedBlackTree::Iterator::~Iterator() {
    current = 0;
}

Iterator::Iterator(const Iterator &original) {
    *current = *(original.current);
}

Iterator &Iterator::operator=(const Iterator &right) {
    *current = *(right.current);
    return *this;
}

T &RedBlackTree::Iterator::operator *() const {
    return this->current->data;
}

RedBlackTree::Iterator RedBlackTree::begin() {
    Node *current = root;

    if(current)
        while(current->left != NIL)
            current = current->left;

    return Iterator(current);
}

RedBlackTree::Iterator RedBlackTree::end() {
    //Node *current = root;

   // if(current)
     //   while(current->right != NIL)
    //        current = current->right;
    //
   // return Iterator(current);
   return Iterator(0);
}

RedBlackTree::Iterator RedBlackTree::Iterator::operator++() {
    if(current) {
        if(current->right != NIL){
            current = current->right;

        while(current->left != NIL)
            current = current->left;
        }
        else {

            if(current->parent != 0) {
                if(current->parent->left == current)
                    current = current->parent;
                else{
                    while(current->parent && current->parent->left != current) {
                        current =  current->parent;
                        if(current->parent == 0)
                            {
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

bool RedBlackTree::Iterator::operator==(const Iterator &right) const {
    return current == right.current;
}

bool RedBlackTree::Iterator::operator!=(const Iterator &right) const {
    return current != right.current;
}
*/
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


void * RedBlackTree::beginImpl() const {
    Node *current = root;

    if(current)
        while(current->left != NIL)
            current = current->left;

    return (void*)current;
}

void * RedBlackTree::endImpl() const {

    return (void*)0;
}

T & RedBlackTree::asteriscImpl(void *pointer) const {
    if(pointer)
        return ((Node *)pointer)->data;
    else
        throw "Fatal Error in astercsImpl";
}

void RedBlackTree::nextImpl(void *&pointer) const {
    Node *current = (Node*)pointer;

    if(current) {
        if(current->right != NIL) {
            current = current->right;

            while(current->left != NIL)
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
                            pointer = (void*)current;
                            return;
                        }
                    }
                    if(current != 0)
                        current =  current->parent;
                }
            } else current = 0;
        }
        pointer = (void*)current;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void RedBlackTree::show() {
    system("clear");
    int level = 0;
    if(root != NIL)
        inOrder(root, consoleOutput,level);
    else
        std::cout<<"EMPTY o_O\n";
}

void RedBlackTree::clearImpl() {
    if(root != NIL) {
        postOrder(root,remove);
        root = NIL;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


void RedBlackTree::inOrder(Node *node, void (*function)(Node *node, int level), int &level) {
    if (node->right != NIL) {
        ++level;
        inOrder(node->right, function, level);
    }
    function(node,level);
    level--;
    if (node->left != NIL) {
        level+=2;
        inOrder(node->left, function, level);
        level--;
    }
}

void RedBlackTree::postOrder(Node *node, void (*function)(Node *node)) {

    if (node->left != NIL)
        postOrder(node->left, function);

    if (node->right!= NIL)
        postOrder(node->right, function);

    function(node);

}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void RedBlackTree::consoleOutput(Node *node, int level) {
    for(int i=0; i<level; ++i )
        std::cout<<"   ";
    std::cout<<node->data<<"\n";
}

void RedBlackTree::remove(Node *node) {
    delete node;
    node =0;
}
