#pragma once

#include <string>
#include "definitions.h"

class comment
{
private:
    string name;
public:
    comment(const string_view&);
    ~comment();

    void serialize(string& txt) const;
};