#include <iostream>
#include <string_view>
#include <variant>
#include <vector>
using namespace std;

const string OPEN = "<";
const string CLOSE = ">";
const string SLASH = "/";
const string SPACE = " ";
const string ENDL = "\n";
const string TAB = "  ";
const string EQUAL = "=";
const string COMILLA = "\"";


class text
{
private:
    string name;
public:
    text(const string_view& name)
    :name{name} { }
    ~text() { }

    void serialize(string& s) const
    {
        cout << "hola\n";
        s += name;
    }
};

class comment
{
private:
    string name;
public:
    comment(const string_view& name)
    :name{name} { }
    ~comment() { }

    void serialize(string& s) const
    {
        s += ENDL;
        s += TAB;
        s += "<-- ";
        s += name;
        s += " -->";
    }
};


struct my_pair
{
    string key;
    string value;
    my_pair(const string_view& key, const string_view& value)
    :key{key}, value{value} { }
};

using node2 = variant<text, comment>;

class element
{
private:
    string name;
    vector<my_pair> attributes;
    vector<node2> children;
public:
    element(const string_view& name)
    :name{name} { }
    ~element() { }

    void set_attribute(const string_view& key, const string_view& value)
    {
        attributes.push_back(my_pair{key, value});
    }

    template <typename T>
    void append_child(const T& xml_obj)
    {
        children.push_back(xml_obj);
    }


    void serialize(string& s) const
    {
        s += ENDL;
        s += TAB;
        s += OPEN;
        s += name;
        for(auto& e : attributes)
        {
            s += SPACE;
            s +=e.key;
            s +=EQUAL;
            s +=COMILLA;
            s +=e.value;
            s +=COMILLA;
        }
        s += SPACE;
        s += CLOSE;
        if(children.empty())
        {
            serialize_children(s);
        }
    }
private:
    void serialize_children(string& s) const
    {
        for(auto& x : children)
        {
            visit([&s](auto& e){
                e.serialize(s);
            }, x);
        }
    }
};

using node = variant<element, text, comment>;

class document
{
private:
    string name;
    vector<node> children;
public:
    document(const string_view& name)
    :name{name} { }
    ~document() { }

    element create_element(const string_view& name)
    {
        return element{name};
    }

    comment create_comment(const string_view& name)
    {
        return comment{name};
    }

    text create_text(const string_view& name)
    {
        return text{name};
    }

    template <typename T>
    void append_child(const T& xml_obj)
    {
        children.push_back(xml_obj);
    }

    string serialize() const
    {
        string s;
        s += OPEN;
        s += name;
        s += CLOSE;
        if(children.size() > 0)
        {
            serialize_children(s);
        }
        else
        {

        }
        return s;
    }
private:
    void serialize_children(string& s) const
    {
        for(auto& x : children)
        {
            visit([&s](auto& e){
                e.serialize(s);
            }, x);
        }
    }
};

class xml_writer
{
private:
    
public:
    xml_writer() { }
    ~xml_writer() { }

    document create_document(const string_view& doc_name)
    {
        return document{doc_name};
    }
};

ostream& operator<<(ostream& os, const document& doc)
{
    return os << doc.serialize();
}

auto main() -> int
{
    xml_writer ws;

    auto doc = ws.create_document("students");

    auto e1 = doc.create_element("student");
    e1.set_attribute("name", "Juan Perez");
    e1.set_attribute("age", "22");
    e1.set_attribute("id", "2193281");

    auto e2 = doc.create_element("student");
    e2.set_attribute("name", "Jorge Lopez");
    e2.set_attribute("age", "25");
    e2.set_attribute("id", "12312312");

    doc.append_child(e1);
    doc.append_child(e2);

    auto c = doc.create_comment("This is a comment");
    doc.append_child(c);

    auto e3 = doc.create_element("info");
    doc.append_child(e3);

    auto text = doc.create_text("This is a text");
    e3.append_child(text);

    cout << doc << "\n";

    /*

  //Sin herencia, sin polimorfismo, sin raw pointers

  <? xml version="1.0" ?>
  <students>
    <student name="Juan Perez" age="22" id="2193281" />
    <student name="Jorge Lopez" age="25" id="12312312" />
    <!-- This is a comment -->
    <info>
      This is a text
    </info>
  </students>

  */
}