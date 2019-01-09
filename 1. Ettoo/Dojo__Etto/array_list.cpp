#include "array_list.h"

array_list::array_list()
:objects{(object**)malloc(0)}, len{0}
{

}

array_list::~array_list(){}


size_t array_list::size() const
{

    return len;

}

void array_list::add(object* obj)
{
    objects = (object**)realloc(objects,(len + 1)*sizeof(object*));
    objects[len] = obj;
    len++;
}

object& array_list::operator[](size_t index)
{
    return *(objects[index]);
}

const object& array_list::operator[](size_t index) const
{
    return *(objects[index]);
}

void array_list::mostrar() const 
{
    for(size_t i = 0; i < len; i++)
    {
        (*this)[i].mostrar();
    }
}

const object& array_list::get_object(const object& obj)const
{
    for(size_t i = 0; i < len; i++)
    {
        if((*this)[i].equals_to(obj)) return (*this)[i];
    }
    throw 0;
}

