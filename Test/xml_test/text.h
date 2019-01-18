#pragma once

#include <string>
#include "definitions.h"

class text
{
private:
    string name;
public:
    text(const string_view&);
    ~text();

    void serialize(string& txt) const;
};