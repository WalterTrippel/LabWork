#include "RedBlackTree.h"
#include <iostream>
#include <queue>

#define NIL &sentinel           /* all leafs are sentinels */
Node sentinel = { NIL, NIL, 0, BLACK, 0};

RedBlackTree::RedBlackTree():
    root(NIL)
{
}

RedBlackTree::~RedBlackTree()
{
    clear();
}

void DFS(Node *node, std::queue<T> &q)  /*DFS = Depth-first search, DFS returns to us a queue with all data of tree*/
{
    if (node->left != NIL)
        DFS(node->left, q);

    q.push(node->data);

    if (node->right != NIL)
        DFS(node->right, q);
}


void DFS4(Node *&node, void (*toDo)(Node *&current) )
{
    toDo(node);

    if (node->left != NIL)
        DFS4(node->left, toDo);

    if (node->right != NIL)
        DFS4(node->right, toDo);
}

/*
*
*
*
*/
void DFS2(Node *node, void (*toDo)(Node *current) )
{
    if (node->left != NIL)
        DFS2(node->left, toDo);

    toDo(node);

    if (node->right != NIL)
        DFS2(node->right, toDo);
}

void DFS3(Node *&node, void (*toDo)(Node *&current) )
{
    if (node->left != NIL)
        DFS3(node->left, toDo);

    if (node->right != NIL)
        DFS3(node->right, toDo);

    toDo(node);
}

void clining(Node *&current)
{
    delete current;
      current = NIL;
}


void RedBlackTree::clear()
{
    if(root != NIL)
    DFS3(root, clining);
}


void cout(Node *current)
{
    std::cout<<current->data;
}


/*
*
*
*
*/
/*
void RedBlackTree::clear()
{
    std::queue<T> q;
    DFS(root, q);

    while(!q.empty())
    {
        this->deleteNode(findNode(q.front()));
        q.pop();
    }
}
*/
/*
RedBlackTree::RedBlackTree(const RedBlackTree &original)
{
    std::queue<T> q;

    DFS(original.root, q);
    while(!q.empty())
    {
        this->insertNode(q.front());
        q.pop();
    }
}
*/

void copy()
{

}

RedBlackTree::RedBlackTree(const RedBlackTree &original)
{
    DFS4(root,copy(original));
}

/*
RedBlackTree &RedBlackTree::operator=(const RedBlackTree &right)
{
    this->clear();
    std::queue<T> q;

    DFS(right.root, q);
    while(!q.empty())
    {
        this->insertNode(q.front());
        q.pop();
    }
    return *this;
}
*/
RedBlackTree &RedBlackTree::operator=(const RedBlackTree &right)
{
    this->clear();
    std::queue<T> q;

    DFS(right.root, q);
    while(!q.empty())
    {
        this->insertNode(q.front());
        q.pop();
    }
    return *this;
}

RedBlackTree RedBlackTree::operator+(const RedBlackTree &right) const
{
    RedBlackTree temp;
    temp = *this;
    std::queue<T> q;
    DFS(right.root, q);
    while(!q.empty())
    {
        temp.insertNode(q.front());
        q.pop();
    }
    return temp;
}

RedBlackTree RedBlackTree::operator-(const RedBlackTree &right) const
{
    RedBlackTree temp;
    temp = *this;

    std::queue<T> q;
    DFS(right.root, q);

    Node *x;

    while(!q.empty())
    {
        if( temp.findNode(q.front()) )
        {
            x=temp.findNode(q.front());
            temp.deleteNode(x);
        }
        q.pop();
    }
    return temp;
}


RedBlackTree RedBlackTree::operator^(const RedBlackTree &right)
{
    RedBlackTree temp;

    std::queue<T> q;
    DFS(right.root, q);

    while(!q.empty())
    {
        if(this->findNode(q.front()))
            temp.insertNode(q.front());

        q.pop();
    }
    return temp;
}

/*
void RedBlackTree::show()
{
    std::queue<T> q;
    DFS(root, q);
    while(!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout<<"\n";
}
*/
void RedBlackTree::show()
{
 DFS2(root,cout);
}

Node *RedBlackTree::findNode(T data)
{
    Node *current = root;
    while(current != NIL)
        if(data == current->data)
            return (current);
        else
            current = data < current->data ?
                      current->left : current->right;
    return 0;
}

void RedBlackTree::insertNode(T data)
{
    Node *current, *parent, *x;

    /* find where node belongs */
    current = root;
    parent = 0;
    while (current != NIL)
    {
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
    if(parent)
    {
        if(data < parent->data)
            parent->left = x;
        else
            parent->right = x;
    }
    else
    {
        root = x;
    }

    insertFixup(x);
}


void RedBlackTree::insertFixup(Node *x)
{
    /* check Red-Black properties */
    while (x != root && x->parent->color == RED)
    {
        /* we have a violation */
        if (x->parent == x->parent->parent->left)
        {
            Node *y = x->parent->parent->right;
            if (y->color == RED)
            {
                /* uncle is RED */
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            }
            else
            {
                /* uncle is BLACK */
                if (x == x->parent->right)
                {
                    /* make x a left child */
                    x = x->parent;
                    rotateLeft(x);
                }

                /* recolor and rotate */
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateRight(x->parent->parent);
            }
        }
        else
        {
            /* mirror image of above code */
            Node *y = x->parent->parent->left;
            if (y->color == RED)
            {
                /* uncle is RED */
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            }
            else
            {
                /* uncle is BLACK */
                if (x == x->parent->left)
                {
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


void RedBlackTree::deleteNode(Node *z)
{
    Node *x, *y;

    if (!z || z == NIL) return;

    if (z->left == NIL || z->right == NIL)
    {
        /* y has a NIL node as a child */
        y = z;
    }
    else
    {
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


void RedBlackTree::deleteFixup(Node *x)
{
    while (x != root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            Node *w = x->parent->right;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft (x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->right->color == BLACK)
                {
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
        }
        else
        {
            Node *w = x->parent->left;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight (x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
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


void RedBlackTree::rotateLeft(Node *x)
{
    Node *y = x->right;

    /* establish x->right link */
    x->right = y->left;
    if (y->left != NIL) y->left->parent = x;

    /* establish y->parent link */
    if (y != NIL) y->parent = x->parent;
    if (x->parent)
    {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    else
    {
        root = y;
    }

    /* link x and y */
    y->left = x;
    if (x != NIL) x->parent = y;
}

void RedBlackTree::rotateRight(Node *x)
{
    Node *y = x->left;

    /* establish x->left link */
    x->left = y->right;
    if (y->right != NIL) y->right->parent = x;

    /* establish y->parent link */
    if (y != NIL) y->parent = x->parent;
    if (x->parent)
    {
        if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
    }
    else
    {
        root = y;
    }

    /* link x and y */
    y->right = x;
    if (x != NIL) x->parent = y;
}
