#include "Mountains.h"
#include <iostream>
Mountain::Mountain():
    name("\0"), location("\0"), hight(0.0)
{
}

Mountain::Mountain(std::string new_name, std::string new_location, int new_hight)
{
    name=new_name;
    location=new_location;
    hight=new_hight;
}

Mountain::Mountain(const Mountain &original)
{
    name=original.name;
    location=original.location;
    hight=original.hight;
}

Mountain& Mountain::operator=(const Mountain &right)
{
    if(this!=&right)
    {
        name=right.name;
        location=right.location;
        hight=right.hight;
    }
    return *this;
}

Mountain::~Mountain()
{
    name='\0';
    location='\0';
    hight=0.0;
}

std::string Mountain::get_name() const
{

    return name;
}
std::string Mountain::get_location() const
{
    return location;
}

int Mountain::get_hight() const
{
    return hight;
}
