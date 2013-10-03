#include <iostream>
#include <cstdlib>

using namespace std;

class Paper
{
public:
    Paper();
    // default copy constructor
    // default operator =
    virtual ~Paper();
    virtual void open()  = 0;
    virtual void read() const = 0;
    virtual void close() = 0;
    virtual void destroy() = 0;
protected:
    bool is_open;
    bool is_exist;
};

Paper::Paper():
    is_open(false), is_exist(true)
{
}

Paper::~Paper()
{
    is_open=false;
    is_exist=false;
}

//void Paper::open() {}
//void Paper::read() const {}
//void Paper::close() {}
//void Paper::destroy() {}

class Newspaper: public Paper
{
public:
    Newspaper() {};
    // default copy constructor
    // default operator =
    ~Newspaper() {};
    void open();
    void read() const;
    void close();
    void destroy();
};

void Newspaper::open()
{
    if(is_exist)
        if(is_open)
        {
            cout<<"Газета уже открыта..\n";
            return;
        }
    is_open=true;
    cout<<"Вы раскрыли газету..\n";
}

void Newspaper::read() const
{
    if(is_exist)
        if(is_open)
        {
            cout<<"Вы прочитали интересную статью..\n";
            return;
        }
    cout<<"Вы не можите читать газету - она закрыта..\n";
}

void Newspaper::close()
{
    if(is_exist)
        if(is_open)
        {
            is_open=false;
            cout<<"Вы закрыли газету..\n";
            return;
        }
    cout<<"Газета закрыта..\n";
}

void Newspaper::destroy()
{
    if(is_exist)
    {
        is_exist=false;
        cout<<"Газета уничтожена..\n";
    }
    else
        cout<<"Такой газеты не существует..\n";
}

class Journal: public Paper
{
public:
    Journal() {};
    // default copy constructor
    // default operator =
    ~Journal() {};
    void open();
    void read() const;
    void close();
    void destroy();
};

void Journal::open()
{
    if(is_exist)
        if(is_open)
        {
            cout<<"Журнал уже открыт..\n";
            return;
        }
    is_open=true;
    cout<<"Вы раскрыли журнал..\n";
}

void Journal::read() const
{
    if(is_exist)
        if(is_open)
        {
            cout<<"Вы просмотрели пару интересных картинок..\n";
            return;
        }
    cout<<"Вы не можите читать журнал - он закрыт..\n";
}

void Journal::close()
{
    if(is_exist)
        if(is_open)
        {
            is_open=false;
            cout<<"Вы закрыли журнал..\n";
            return;
        }
    cout<<"Журнал закрыт..\n";
}

void Journal::destroy()
{
    if(is_exist)
    {
        is_exist=false;
        cout<<"Журнал уничтожена..\n";
    }
    else
        cout<<"Такого журнала не существует..\n";
}

class Book: public Paper
{
public:
    Book() {};
    // default copy constructor
    // default operator =
    ~Book() {};
    void open();
    void read() const;
    void close();
    void destroy();
};

void Book::open()
{
    if(is_exist)
        if(is_open)
        {
            cout<<"Ккнига уже открыта..\n";
            return;
        }
    is_open=true;
    cout<<"Вы раскрыли книгу..\n";
}

void Book::read() const
{
    if(is_exist)
        if(is_open)
        {
            cout<<"Вы прочитали пару увлекательных страниц..\n";
            return;
        }
    cout<<"Вы не можите читать книгу - она закрыта..\n";
}

void Book::close()
{
    if(is_exist)
        if(is_open)
        {
            is_open=false;
            cout<<"Вы закрыли книгу..\n";
            return;
        }
    cout<<"Книга закрыта..\n";
}

void Book::destroy()
{
    if(is_exist)
    {
        is_exist=false;
        cout<<"Книга уничтожена..\n";
    }
    else
        cout<<"Такой книги не существует..\n";
}

void destroy(Paper *&x)
{
    if(x)
    {
        x->destroy();
        x=0;
    }
    else
        cout<<"Уже уничтожено..\n";
}

void work(Paper *&x)
{
    int action=0;
    while(action!=5)
    {
        cout<<"1.Открыть..\n";
        cout<<"2.Читать..\n";
        cout<<"3.Закрыть..\n";
        cout<<"4.Уничтожить..\n";
        cout<<"5.Отложить..\n";
        cin>>action;
        system("clear");
        switch(action)
        {
        case 1:
            x->open();
            break;
        case 2:
            x->read();
            break;
        case 3:
            x->close();
            break;
        case 4:
        {
            destroy(x);
            action=5;
        }
        break;
        default:
            cout<<"Нельзя.. :)\n";
        }
    }
}

int main()
{
    Paper *bookshelf[3];

    Newspaper a;
    Journal b;
    Book c;

    bookshelf[0]=&a;
    bookshelf[1]=&b;
    bookshelf[2]=&c;

    int answ=0;

    do
    {
        system("clear");
        if(bookshelf[0] || bookshelf[2] || bookshelf[1])
        {
            cout<<"У вас на полке имееются:\n";
            if(bookshelf[0])
                cout<<"1.Газета\n";
            if(bookshelf[1])
                cout<<"2.Журнал\n";
            if(bookshelf[2])
                cout<<"3.Книга\n";
            cout<<"4.Уйти..\n";
        }
        else
        {
            cout<<"Hа полке пусто.. :(\n";
            cout<<"Уходим.. :)\n";
            return 0;
        }

        cout<<"Что желаете взять?\n";
        cin>>answ;
        system("clear");

        switch(answ)
        {
        case 1:
        {
            cout<<"Выбрана газета, что желаете сделать?..\n";
            work(bookshelf[0]);
        }
        break;
        case 2:
        {
            cout<<"Выбран журнал, что желаете сделать?..\n";
            work(bookshelf[1]);
        }
        break;
        case 3:
        {
            cout<<"Выбрана книга, что желаете сделать?..\n";
            work(bookshelf[2]);
        }
        case 4:
        {
            cout<<"Уходим..\n";
        }
        break;
        default:
            cout<<"Нельзя.. :)\n";
        }
    }
    while(answ!=4);
    return 0;
}
