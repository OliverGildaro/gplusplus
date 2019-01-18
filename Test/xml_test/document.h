#pragma once

#include "element.h"

class document
{
private:
    string name;
    vector<node> children;
public:
    document(const string_view&);
    ~document();

    shared_ptr<element> create_element(const string_view&);
    shared_ptr<comment> create_comment(const string_view&);
    shared_ptr<text> create_text(const string_view&);

    template<typename T>
    void append_child(T child)
    {
        children.push_back(child);
    }

    string serialize() const;
};