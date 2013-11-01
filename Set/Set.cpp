#include "Set.h"
#include <iostream>

Set::Set(Tree *container):
    container(container){

}

void Set::addElement(T newElement){
    container->insert(newElement);
}
bool Set::findElement(T value){
    return container->find(value);
}

void Set::deleteElemenet(T value){
    container->remove(value);
}

void Set::show(){

}
