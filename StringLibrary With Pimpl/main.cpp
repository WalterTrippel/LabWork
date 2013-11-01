#include <iostream>
#include "newstring.h"

using namespace std;

class MyString: public String
{
public:
    MyString();
    MyString(int n);
    explicit MyString(const char *str);
    MyString(const MyString &original);
    MyString &operator=(const MyString &right);
    ~MyString();

    friend std::ostream &operator<<(std::ostream &output, const MyString &x);
    friend std::istream &operator>>(std::istream &input, const MyString &x);

//private:
    MyString(const String &original);
};

int main()
{
    MyString a("Hello ");
    cout<<"String class 'a': \""<<a<<"\" with length: "<<a.length()<<endl;

    MyString b("World!");
    cout<<"String class 'b': \""<<b<<"\" with length: "<<b.length()<<endl;

    MyString c;
    c=a+b;
    cout<<"String class 'c=a+b': \""<<c<<"\" with length: "<<c.length()<<endl<<endl;

    MyString g;
    g=c.substr(0,6);
    cout<<"Substring 'g' of String 'c' with position 0 & 6 elements after: "<<endl<<"\""<<g<<"\" with length: "<<g.length()<<endl;
    g=c.substr(6,15);
    cout<<"Substring 'g' of String 'c' with position 6 & 15 elements after: "<<endl<<"\""<<g<<"\" with length: "<<g.length()<<endl<<endl;


    cout<<"Some comparisons: "<<endl;
    if(a>=b)
        cout<<a<<" >= "<<b<<endl;
    else
        cout<<a<<" not >= "<<b<<endl;

    if(a<=b)
        cout<<a<<" <= "<<b<<endl;
    else
        cout<<a<<" not <= "<<b<<endl;

    if(a>b)
        cout<<a<<" > "<<b<<endl;
    else
        cout<<a<<" not > "<<b<<endl;

    if(a<b)
        cout<<a<<" < "<<b<<endl;
    else
        cout<<a<<" not < "<<b<<endl;

    if(a==b)
        cout<<a<<" == "<<b<<endl;
    else
        cout<<a<<" not == "<<b<<endl;
    cout<<endl;

    MyString l("lalka");
    cout<<"String class 'l': "<<l<<endl;;
    char *p;
    p=l.c_str();
    cout<<"Result of 'l.c_str' function: ";
    cout<<p<<endl<<endl;

    MyString f(5); // length include \0 symbol
    cout<<"Finaly actin: input strung with 4 symbols: ";
    cin>>f;
    cout<<"Your sting: "<<f<<endl;

    return 0;
}

MyString::MyString():
  String()
{
}

MyString::MyString(int n):
  String(n)
{
}


MyString::MyString(const char *str):
    String(str)
{
}


MyString::MyString(const MyString &original):
    String(original)
{
}

MyString::MyString(const String &original):
    String(original)
{
}

MyString &MyString::operator=(const MyString &right)
{
   String::operator=(right);
   return *this;
}


MyString::~MyString()
{
}


std::ostream &operator<<(std::ostream &output, const MyString &x)
{
    char *array=x.get_array();

    for (int i=0; array[i]; ++i)
        output<<array[i];
    return output;
}

std::istream  &operator>>(std::istream &input, const MyString &x)
{
    int size=x.get_size();
    char *array=x.get_array();

    for(int i=0; i<size-1; ++i)
        input>>array[i];
    return input;
}
