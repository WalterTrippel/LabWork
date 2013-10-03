#include "newstring.h"

class String::ImString{

public:
    ImString();
    ImString(int n);
    explicit ImString(const char *str);
    ImString(const ImString &original);
    ImString &operator=(const ImString &right);
    ~ImString();

    int length() const;
    ImString substr(int first, int n) const;
    char *c_str() const;

    ImString operator+(const ImString &x) const;
    bool operator==(const ImString &x) const;
    bool operator>=(const ImString &x) const;
    bool operator<=(const ImString &x) const;
    bool operator>(const ImString &x) const;
    bool operator<(const ImString &x) const;
    void operator<<(const ImString &x) const;

    int get_size() const;
    char* get_array() const;

private:
    int size;
    char *array;
};

//=======================================


String::String():
    pimpl(0)
{
    pimpl = new ImString();
}

String::String(int n):
    pimpl(0)
{
    pimpl = new ImString(n);
}


String::String(const char *str):
   pimpl(0)
{
    pimpl = new ImString(str);
}


String::String(const ImString &original):
    pimpl(0)
{
    pimpl = new ImString(original);
}

String::String(const String &original):
   pimpl(0)
{
    pimpl = new ImString(*(original.pimpl));
}

String &String::operator=(const String &right)
{
    *(this->pimpl) = *(right.pimpl);
   return *this;
}

String::~String()
{
    delete pimpl;
    pimpl = 0;
}

int length(const char *str);

//=======================================

int String::length() const
{
     return pimpl->length();
}

String String::substr(int first, int n) const
{
    return String(pimpl->substr(first,n));
}

char * String::c_str() const
{
    return pimpl->c_str();
}

String String::operator+(const String &x) const
{
    return String(pimpl->operator+(*(x.pimpl)));
}

bool String::operator==(const String &x) const
{
    return pimpl->operator==(*(x.pimpl));
}

bool String::operator>=(const String &x) const
{
    return pimpl->operator>=(*(x.pimpl));
}

bool String::operator<=(const String &x) const
{
    return pimpl->operator<=(*(x.pimpl));
}

bool String::operator>(const String &x) const
{
    return pimpl->operator>(*(x.pimpl));
}

bool String::operator<(const String &x) const
{
    return pimpl->operator<(*(x.pimpl));
}

//=======================================

String::ImString::ImString():
    size(0), array(0)
{
}

String::ImString::ImString(int n):
    size(n), array(0)
{
    array=new char[size];
    for (int i=0; i<size; ++i)
        array[i]='\0';
}


String::ImString::ImString(const char *str):
    size(::length(str)), array(0)
{
    array=new char[size];
    for(int i=0; i<size; ++i)
        array[i]=str[i];
}


String::ImString::ImString(const ImString &original):
    size(original.size), array(0)
{
    array = new char[size];
    for(int i=0; i<size; ++i)
        array[i]=original.array[i];
}


String::ImString &String::ImString::operator=(const ImString &right)
{
    if(this != &right )
    {
    if(size != right.size)
    {
        delete []array;
        size=right.size;
        array= new char [size];
    }
    for(int i=0; i<size; ++i)
        array[i]=right.array[i];
    }
    return *this;
}

String::ImString::~ImString()
{
    for(int i=0; i<size; ++i)
        array[i]='\0';
    delete []array;
    array=0;
}

int String::get_size() const
{
   return pimpl->get_size();
}

char* String::get_array() const
{
   return pimpl->get_array();
}

int String::ImString::get_size() const
{
   return size;
}

char* String::ImString::get_array() const
{
   return array;
}

////////////////////////////////////////////////////////////

int length(const char *str)
{
    int length=0;
    for(int i=0; str[i]; ++i)
        ++length;
    return ++length;
}

int String::ImString::length() const
{
    int length=size-1;
    return length;
}

String::ImString String::ImString::substr(int pos, int n) const
{
    int length=0;
    if(pos+n<size)
        length=n+1;
    else
        length=size-pos;

    ImString substr(length);

    for(int i=0, j=pos; i<substr.size-1; ++i, ++j)
        substr.array[i]=array[j];
    return substr;
}

char* String::ImString::c_str() const
{
    char *c_str = new char[size];
    for(int i=0; i<size; ++i)
        c_str[i]=array[i];
    return c_str;
}

////////////////////////////////////////////////////////////

String::ImString String::ImString::operator+(const ImString &x) const
{
    ImString y(size+x.size-1);

    if (size>0)
    {
        for(int i=0; i<size; ++i)
            y.array[i]=array[i];
        for(int i=size-1, j=0; i<y.size; ++i, ++j)
            y.array[i]=x.array[j];
    }
    else
        for(int i=size, j=0; i<y.size; ++i, ++j)
            y.array[i]=x.array[j];

    return y;
};

bool String::ImString::operator==(const ImString &x) const
{
    if (size!=x.size)
        return false;
    else
    {
        for(int i=0; i<size; )
            if(array[i]==x.array[i])
                ++i;
            else return false;
        return true;
    }
};

////////////////////////////////

bool String::ImString::operator>=(const ImString &x) const
{
    int total=size>x.size?size:x.size;
    for(int i=0; i<total; )
    {
        if(array[i]>x.array[i])
            return true;
        if(array[i]==x.array[i])
            ++i;
        else if(array[i]<x.array[i])
            return false;
        else ++i;
    }
    return true;
};

bool String::ImString::operator<=(const ImString &x) const
{
    int total=size>x.size?size:x.size;
    for(int i=0; i<total; )
    {
        if(array[i]<x.array[i])
            return true;
        if(array[i]==x.array[i])
            ++i;
        else if(array[i]>x.array[i])
            return false;
    }
    return true;
};

bool String::ImString::operator>(const ImString &x) const
{
    int total=size>x.size?size:x.size;
    for(int i=0; i<total-1; )
    {
        if(array[i]>x.array[i])
            return true;
        if(array[i]==x.array[i])
            ++i;
        else if(array[i]<x.array[i])
            return false;
    }
    return !array[total]==x.array[total];
};

bool String::ImString::operator<(const ImString &x) const
{
    int total=size>x.size?size:x.size;
    for(int i=0; i<total; )
    {
        if(array[i]<x.array[i])
            return true;
        if(array[i]==x.array[i])
            ++i;
        else if(array[i]>x.array[i])
            return false;
    }
    return !array[total]==x.array[total];
};
