#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include "Tree.h"

typedef int T;

class Set{
public:
    Set(Tree *container);
    //~Set();
    //Set(const Set &original);
    void addElement(T newElement);
    bool findElement(T value);
    void deleteElemenet(T value);

    Set &operator=(const Set &right);
    Set operator+(const Set &right) const;
    Set operator-(const Set &right) const;
    Set operator^(const Set &right) const;

    void show();
private:
    int numberOfElements;
    Tree *container;
};

#endif // SET_H_INCLUDED
