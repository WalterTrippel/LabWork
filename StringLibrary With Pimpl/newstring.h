#ifndef NEWSTRING_H_INCLUDED
#define NEWSTRING_H_INCLUDED

class String
{

public:
    String();
    String(int n);
    explicit String(const char *str);
    String(const String &original);
    String &operator=(const String &right);
    ~String();

    String operator+(const String &x) const;

    bool operator==(const String &x) const;
    bool operator>=(const String &x) const;
    bool operator<=(const String &x) const;
    bool operator>(const String &x) const;
    bool operator<(const String &x) const;

    int length() const;
    String substr(int first, int n) const;
    char *c_str() const;

protected:
    int get_size() const;
    char* get_array() const;


private:
    class ImString;
    ImString *pimpl;
    String(const ImString &original);
};

#endif // NEWSTRING_H_INCLUDED
