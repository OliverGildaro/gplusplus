#include "text.h"

text::text(const string_view& name)
:name{name}
{
}

text::~text()
{
}

void text::serialize(string& txt) const
{
    txt += ENDL;
    txt += name;
}