#include <iostream>
#include <string_view>
#include <vector>
#include <variant>
#include <string>
#include <memory>
#include <map>

using namespace std;


constexpr string_view OPEN = "<";

constexpr string_view CLOSE = ">";

constexpr string_view SLASH = "/";

constexpr string_view QUOTE = "\"";

constexpr string_view EQUAL = "=";

constexpr string_view TAB = "\t";

constexpr string_view END_L = "\n";

constexpr string_view OPEN_COMMENT = "<!-- ";

constexpr string_view CLOSE_COMMENT = " -->";

constexpr string_view XML_HEADER = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";

constexpr string_view SPACE = " ";


void identacion(int current_ident, string& str)

{

for(size_t i = 0; i < current_ident; i++)

{

str += SPACE;

}

}

string escape_special_char(const string& str)

{

string newsrt;

for(auto& e: str)

{

switch(e)

{

case '<': newsrt += "&lt;"; break;

case '>': newsrt += "&gt;"; break;

case '&': newsrt += "&amp;"; break;

case '\"': newsrt += "&quot;"; break;

case '\'': newsrt += "&apos;"; break;

default: newsrt += e;

}

}

return newsrt;

}


class text

{

private:


string name;


public:


text(const string_view& name) : name{name}

{}

void serialize(string& text, int ident,int current_ident) const

{

identacion(current_ident, text);

text += escape_special_char(name);

if(ident != -1)

{

text+= END_L;

}

}


~text() { }

};


class comment

{

private:


string name;


public:


comment(const string_view& name) : name{name}

{}

void serialize(string& comment, int ident,int current_ident) const

{

//<!-- This is a comment -->

identacion(current_ident, comment);

comment += OPEN_COMMENT;

comment += escape_special_char(name);

comment += CLOSE_COMMENT;


if(ident != -1)

{

comment+= END_L;

}

}

~comment() { }

};


class element;

using node = variant<shared_ptr<element>, shared_ptr<text>, shared_ptr<comment>>;


class element

{

private:

string name;

vector<node> children;

map<string, string> atributes;

public:

element(const string_view&);

void set_attribute (const string_view& key, const string_view& value);


template<typename T>

void append_child(const T& value)

{

children.push_back(value);

}


void serialize(string& str, int ident,int current_ident) const;


};



void serialize_children(string& str, const vector<node>& children, int ident,int current_ident)

{

for(auto& x: children)

{

visit(


[&str, ident,current_ident](auto& e){e->serialize(str, ident, current_ident);},

x

);


}

}


void serialize_element(string& str, const string& name, const vector<node>& children,

const map<string, string>& atributes, int ident, int current_ident)

{

identacion(current_ident, str);


str += OPEN;

str += escape_special_char(name);

for(auto& e: atributes){

str += " ";

str += escape_special_char(e.first);

str += EQUAL;

str += QUOTE;

str += escape_special_char(e.second);

str += QUOTE;

}


if(children.size())

{

str += CLOSE;


if(ident != -1)

{

str+= END_L;

}


serialize_children(str, children, ident,ident != -1 ? ident + current_ident : 0);

identacion(current_ident, str);


str+=OPEN;

str+=SLASH;

str+= escape_special_char(name);

str+=CLOSE;

}

else{

str+=" ";

str+=SLASH;

str+=CLOSE;

}


if(ident != -1)

{

str+= END_L;

}

}



element::element(const string_view& name):name{name}

{

}


void element::set_attribute (const string_view& key, const string_view& value)

{

atributes.insert(make_pair(key, value));

}


void element::serialize(string& str, int ident,int current_ident) const


{

serialize_element(str, name, children, atributes, ident,current_ident);



}


class document
{
    string name;
    vector<node> children;
public:
    document(const string_view& name)
    :name{name}
    {
    }
    shared_ptr<element> create_element (const string_view& name) const
    {
        return make_shared<element>(name);
    }
    template<typename T>
    void append_child(const T& ele)
    {
        children.push_back(ele);
    }
    shared_ptr<comment> create_comment(const string_view& com) const
    {
        return make_shared<comment>(com);
    }
    shared_ptr<text> create_text(const string_view& tex) const
    {
        return make_shared<text>(tex);
    }
    string serialize(int ident= -1) const
    {
    string str;
    str+= XML_HEADER;
    if(ident != -1)
    {
    str+= END_L;
    }
    serialize_element(str, name, children, map<string, string>{}, ident,0);
    return str;
    }
};




class xml_writer

{


public:

document create_document(const string_view& document_name)

{

return document{document_name};

}


};


// &lt; represents "<";

// &gt; represents ">";

// &amp; represents "&";

// &apos; represents "'";

// &quot; represents '"'.




ostream& operator<<(ostream& os, const document& ws)

{

return os << ws.serialize(4);

}


template <typename Writer>

void test(Writer ws)

{

auto doc = ws.create_document("students");


auto e1 = doc.create_element("student");

e1->set_attribute("name", "Juan Perez");

e1->set_attribute("age", "22");

e1->set_attribute("id", "2193281");


auto e2 = doc.create_element("student");

e2->set_attribute("name", "Jorge Lopez");

e2->set_attribute("age", "25");

e2->set_attribute("id", "12312312");


doc.append_child(e1);

doc.append_child(e2);


auto c = doc.create_comment("This is a comment ><&&''\"");

doc.append_child(c);


auto e3 = doc.create_element("info");

doc.append_child(e3);


auto text = doc.create_text("This is a text ");

e3->append_child(text);


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


auto main() -> int

{

test(writer<xml> {});


cout << "*****************" << endl;


test(writer<json> {});



}
