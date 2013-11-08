#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef int T;

class TreeIterator;

class Tree {
public:
    friend TreeIterator;
    typedef TreeIterator iterator;

    Tree() {};
    ~Tree();
    Tree &operator=(Tree &original);

    bool find(T key) ;
    void insert(T data);
    void remove(T key);
    void clear();

    iterator begin() const;
    iterator end() const;
    void showLikeTree() {
        show();
    };
private:
    virtual bool findImpl(T key) = 0;
    virtual void insertImpl(void *pointer) = 0;
    virtual void insertImpl(T data) = 0;
    virtual void removeImpl(T key) = 0;
    virtual void clearImpl() = 0;

    virtual void *beginImpl() const = 0;
    virtual void *endImpl() const = 0;

    virtual void show() = 0;
    //Interface for Iterator
    T &asterisc(void *pointer) const;
    void next(void *&pointer) const;

    //Implementation
    virtual T &asteriscImpl(void *pointer) const = 0;
    virtual void nextImpl(void *&pointer) const = 0;

};

class TreeIterator {
public:
    friend Tree;
    TreeIterator();
    //default copy constructor
    //default assign operator
    ~TreeIterator();

    T &operator*() const;
    TreeIterator operator++();
    TreeIterator operator++(int);
    bool operator==(const TreeIterator &right) const;
    bool operator!=(const TreeIterator &right) const {
        return !(*this == right);
    }
private:
    const Tree *owner;
    void *current;

    TreeIterator(const Tree *owner, void *current);
};


#endif // TREE_H_INCLUDED
