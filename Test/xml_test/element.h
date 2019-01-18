#pragma once

#include <memory>
#include <variant>
#include <vector>

#include "comment.h"
#include "text.h"
#include "element.h"
#include "my_pair.h"

using namespace std;

class element;

using node = variant<shared_ptr<element>, shared_ptr<comment>, shared_ptr<text>>;

class element
{
private:
    string name;
    vector<my_pair> attributes;
    vector<node> children;
public:
    element(const string_view&);
    ~element();

    void set_attribute(const string_view&, const string_view&);

    template<typename T>
    void append_child(T child)
    {
        children.push_back(child);
    }

    void serialize(string& txt) const;
};

void serialize_children(string& txt, const vector<node>& children);

void real_serialize(string& txt, const string& name, const vector<node>&            children);