#include "document.h"

document::document(const string_view& name)
:name{name}
{
}

document::~document()
{
}

shared_ptr<element> document::create_element(const string_view& name)
{
    return make_shared<element>(name);
}

shared_ptr<comment> document::create_comment(const string_view& name)
{
    return make_shared<comment>(name);
}

shared_ptr<text> document::create_text(const string_view& name)
{
    return make_shared<text>(name);
}

string document::serialize() const
{
    string txt;
    real_serialize(txt, name, children);
    return txt;
}