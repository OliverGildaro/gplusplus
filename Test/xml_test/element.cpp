#include "element.h"

void serialize_children(string& txt, const vector<node>& children)
{
    for(auto& e : children)
    {
        visit([&txt](auto& c){
            c->serialize(txt);
        }, e);
    }
}

void real_serialize(string& txt, const string& name, const vector<node>&            children)
{
    txt += OPEN;
    txt += name;
    if(!children.empty())
    {
        txt += CLOSE;
        serialize_children(txt, children);
        txt += ENDL;
        txt += OPEN;
        txt += SLASH;
        txt += name;
        txt += CLOSE;
    }
    else
    {
        txt += SPACE;
        txt += SLASH;
        txt += CLOSE;
    }
}


element::element(const string_view& name)
:name{name}
{
}

element::~element()
{
}

void element::set_attribute(const string_view& key, const string_view& value)
{
    attributes.push_back(my_pair{key, value});
}

void element::serialize(string& txt) const
{
    txt += ENDL;
    real_serialize(txt, name, children);

    for(auto& e : attributes)
    {
        txt += SPACE;
        txt += e.get_key();
        txt += EQUAL;
        txt += QUOTE;
        txt += e.get_value();
        txt += QUOTE;
    }
}