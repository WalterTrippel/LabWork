#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <exception>

class Stack_exceptin: std::exception
{
     const char* what() const throw ()
     {
         return "Read from empty stack!\n";
     };
};

template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(const T &new_data);
    void pop();
    T on_top() const;
    bool is_empty() const;
    void clear();
private:
    struct List
    {
        List(T new_data);
        ~List();
        T data;
        List *next;

    }*top;
};

template<typename T>
Stack<T>::Stack():
    top(0)
{
}

template<typename T>
Stack<T>::~Stack()
{
    clear();
}

template<typename T>
Stack<T>::List::List(T new_data):
    data(new_data), next(0)
{
}

template<typename T>
Stack<T>::List::~List()
{
    data=0;
    next=0;
}

template<typename T>
void Stack<T>::push(const T &new_data)
{
    List *p=0;
    p=new List(new_data);
    p->next=top;
    top=p;
    p=0;
}

template<typename T>
void Stack<T>::pop()
{
    if(!is_empty())
    {
        List *p=0;
        p=top;
        top=top->next;
        delete p;
        p=0;
    }
    else throw Stack_exceptin();
}

template<typename T>
T Stack<T>::on_top() const
{
    if(is_empty())
        throw Stack_exceptin();
    return top->data;
}

template<typename T>
bool Stack<T>::is_empty() const
{
    return top==0;
}

template<typename T>
void Stack<T>::clear()
{
    while(top)
    {
        List *p;
        p=top;
        top=top->next;
        delete p;
        p=0;
    }
}

#endif // STACK_H_INCLUDED
