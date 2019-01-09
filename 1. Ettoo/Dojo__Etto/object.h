#pragma once
#include <iostream>
using namespace std;

class object
{
    public:
        virtual void mostrar() const = 0;
        virtual bool equals_to(const object&) const;
};