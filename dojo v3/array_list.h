#pragma once
#include <iostream>
#include "object.h"
using namespace std;

class array_list: public object
{
    object** objects;
    size_t len;
    
    public:

        array_list();
        ~array_list();
        size_t size() const;
        void add(object*);
        object & operator[](size_t index);
        const object & operator[](size_t index) const;
        void mostrar() const override;
        const object& get_object(const object&)const;
};