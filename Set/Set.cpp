#include "Set.h"
#include <iostream>

void Set::clear() {
    container->clear();
}


Set::Set(Tree *container):
    container(container) {

}


void Set::addElement(T newElement) {
    container->insert(newElement);
}
bool Set::findElement(T value) {
    return container->find(value);
}

void Set::deleteElemenet(T value) {
    container->remove(value);
}

void Set::show() {
    Tree::iterator it, endIt;
    it = container->begin();
    endIt = container->end();

    std::cout<<"{ ";
    while(it  != endIt ) {
        std::cout<<*it<<" ";
        ++it;
    }
    std::cout<<"}\n";

}


Set &Set::operator=(const Set &right) {
    *(this->container) = *(right.container);
    return *this;
}

Set Set::operator+( Set &right) {

    Tree::iterator it, endIt;
    it = right.container->begin();
    endIt = right.container->end();


    while(it  != endIt ) {
        this->addElement(*it);
        ++it;
    }
    return *this;
}

Set Set::operator-( Set &right) {

    Tree::iterator it, endIt;
    it = right.container->begin();
    endIt = right.container->end();


    while(it  != endIt ) {
        this->deleteElemenet(*it);
        ++it;
    }
    return *this;

}

Set Set::operator^(Set &right) {

    Tree::iterator it, endIt;
    it = right.container->begin();
    endIt = right.container->end();


    while(it  != endIt ) {
        this->deleteElemenet(*it);
        ++it;
    }

    return *this;

}




