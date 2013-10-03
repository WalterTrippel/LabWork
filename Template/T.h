#ifndef T_H_INCLUDED
#define T_H_INCLUDED
#include <exception>

class Stack_exception: public std::exception
{
    const char *what() const throw()
    {
        return "Read from empty stack!\n";
    }
};


template<typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack<T> &original);
    //Stack &operator=(const Stack &right);
    ~Stack();
    void push(T new_data);
    void pop();
    T on_top() const;
    bool is_empty() const;
    void clear();
private:
    class Stack_implementation;
    Stack_implementation *pimpl;
};

template<typename T>
class Stack<T>::Stack_implementation
{
public:
    Stack_implementation();
    Stack_implementation(const Stack_implementation &original);
    //Stack &operator=(const Stack &right);
    ~Stack_implementation();
    void push(T new_data);
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
    pimpl(0)
{
    pimpl = new Stack_implementation;
}

template<typename T>
Stack<T>::~Stack()
{
    pimpl->clear();
    delete pimpl;
    pimpl=0;
}

template<typename T>
void Stack<T>::push(T new_data)
{
    pimpl->push(new_data);
}

template<typename T>
void Stack<T>::pop()
{
    pimpl->pop();
}

template<typename T>
T Stack<T>::on_top() const
{
    return pimpl->on_top();
}

template<typename T>
bool Stack<T>::is_empty() const
{
    return pimpl->is_empty();
}

template<typename T>
void Stack<T>::clear()
{
    pimpl->clear();
}

template<typename T>
Stack<T>::Stack_implementation::Stack_implementation():
    top(0)
{
}

template<typename T>
Stack<T>::Stack_implementation::~Stack_implementation()
{
    clear();
}


template<typename T>
Stack<T>::Stack_implementation::List::List(T new_data):
    data(new_data), next(0)
{
}

template<typename T>
Stack<T>::Stack_implementation::List::~List()
{
    data=0;
    next=0;
}

template<typename T>
void Stack<T>::Stack_implementation::push(T new_data)
{
    List *p=0;
    p=new List(new_data);
    p->next=top;
    top=p;
    p=0;
}

template<typename T>
void Stack<T>::Stack_implementation::pop()
{
    if(!is_empty())
    {
        List *p=0;
        p=top;
        top=top->next;
        delete p;
        p=0;
    }
}

template<typename T>
T Stack<T>::Stack_implementation::on_top() const
{
    if(is_empty())
        throw Stack_exception();
    return top->data;
}

template<typename T>
bool Stack<T>::Stack_implementation::is_empty() const
{
    return top==0;
}

template<typename T>
void Stack<T>::Stack_implementation::clear()
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



#endif // <T>_H_INCLUDED
