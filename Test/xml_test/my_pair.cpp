#include "my_pair.h"

my_pair::my_pair(const string_view& key, const string_view& value)
:key{key}, value{value}
{
}

my_pair::~my_pair()
{
}

string my_pair::get_key() const
{
    return key;
}
string my_pair::get_value() const
{
    return value;
}