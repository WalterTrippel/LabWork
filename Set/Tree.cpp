#include "Tree.h"

bool Tree::find(T key){
    return findNode(key);
}

void Tree::insert(T data){
    insertNode(data);
}
void Tree::remove(T key){
    deleteNode(key);
}
void Tree::destroy(){
    clear();
}

