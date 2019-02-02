#pragma once
#include <iostream>


struct person
{
    char name[128];
    char last_name[128];
    int birt_year;
};

std::ostream &operator<<(std::ostream& os, const person& p)
{
    os<<p.name<<";"<<p.last_name<<";"<<p.birt_year;
    return os;
};
