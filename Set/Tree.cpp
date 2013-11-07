#include "Tree.h"

Tree& Tree::operator=(Tree &original) {
    this->clear();

    void *current = original.beginImpl();
    void *end = original.endImpl();
    while(current != end) {
        this->insertImpl(current);
        original.nextImpl(current);
    }
    return *this;
}



bool Tree::find(T key) {
    return findImpl(key);
}

void Tree::insert(T data) {
    insertImpl(data);
}


void Tree::remove(T key) {
    removeImpl(key);
}
void Tree::clear() {
    clearImpl();
}

TreeIterator::TreeIterator():
    owner(0),
    current(0)
{}

TreeIterator::~TreeIterator() {
    owner = 0;
    current = 0;
}

T &TreeIterator::operator*() const {
    if(owner && current)
        return owner->asterisc(current);
    else
        throw "Fatal error in TreeIteraror operation*";
}

TreeIterator TreeIterator::operator++() {
    if(owner)
        owner->next(current);

    return *this;
}

TreeIterator TreeIterator::operator++(int) {
    TreeIterator result(*this);
    ++(*this);
    return result;
}

bool TreeIterator::operator==(const TreeIterator &right) const {
    return owner == right.owner && current == right.current;
}

TreeIterator::TreeIterator(const Tree *owner, void *current):
    owner(owner),
    current(current)
{}


Tree::~Tree() {
    clear();
}

TreeIterator Tree::begin() const {
    return TreeIterator(this, beginImpl());
}

TreeIterator Tree::end() const {
    return TreeIterator(this, 0);
}

T &Tree::asterisc(void *pointer) const {
    return asteriscImpl(pointer);
}

void Tree::next(void *&pointer) const {
    nextImpl(pointer);
}

