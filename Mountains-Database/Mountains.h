#ifndef MOUNTAINS_H_INCLUDED
#define MOUNTAINS_H_INCLUDED
#include <string>

class Mountain
{
public:
    Mountain();
    Mountain(std::string new_name, std::string new_location, int new_hight);
    Mountain(const Mountain &original);
    ~Mountain();
    Mountain &operator=(const Mountain &right);
    std::string get_name() const;
    std::string get_location() const;
    int get_hight() const;
private:
    std::string name;
    std::string location;
    int hight;
};

#endif // MOUNTAINS_H_INCLUDED
