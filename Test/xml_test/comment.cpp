#include "comment.h"

comment::comment(const string_view& name)
:name{name}
{
}

comment::~comment()
{
}

void comment::serialize(string& txt) const
{
    txt += ENDL;
    txt += name;
}
