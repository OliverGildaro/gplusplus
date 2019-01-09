#include "m_string.h"
#include<cstring>

m_string::m_string(const char* str)
:len{strlen(str)}, valor{(char*) malloc(len+1) }
{
    memcpy(valor, str, len+1);
}

m_string::m_string(const m_string& src)
:len{src.len}, valor{(char*) malloc(len+1) }{

    memcpy(valor, src.valor, len+1);
}

m_string::~m_string(){

    free(valor);
}

m_string& m_string:: operator=(const m_string& src)
{
    
    if(this == &src)
    {
        return *this;
    }
    this->~m_string();
    len = src.len;
    valor = (char*) malloc(len+1);
    memcpy(valor, src.valor, len+1);
    return *this;
}

const char* m_string::get_str() const
{
    return valor;
}

bool m_string::operator==(const m_string& str) const
{
    if(this == &str)
        return true;
    if(len != str.len)
        return false;
    return memcmp(valor, str.valor, len) == 0;
}

