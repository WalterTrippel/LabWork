#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include "Tree.h"

typedef int T;

class Set {
public:
    Set(Tree *container);

    void addElement(T newElement);
    bool findElement(T value);
    void deleteElemenet(T value);

    Set &operator=(const Set &right);
    Set operator+(Set &right);
    Set operator-(Set &right);
    Set operator^(Set &right);

    void clear();
    void show();
private:
    Set();
    Tree *container;
};

#endif // SET_H_INCLUDED
