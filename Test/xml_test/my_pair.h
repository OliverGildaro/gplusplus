#pragma once

#include <string>
#include <string_view>

using namespace std;

class my_pair
{
private:
    string key;
    string value;
public:
    my_pair(const string_view&, const string_view&);
    ~my_pair();

    string get_key() const;
    string get_value() const;
};