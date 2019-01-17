#include <iostream>
#include <string_view>
#include <vector>
#include <variant>
#include <string>


using namespace std;

constexpr string_view OPEN = "<";
constexpr string_view CLOSE = ">";
constexpr string_view SLASH = "/";


class text
{
private:
  string name;
public:
  text(const string_view& name)
  :name{name}
  {}
  ~text() { }
};
class comment
{
private:
  string name;
public:
  comment(const string_view& name)
  :name{name}
  {}
  ~comment() { }
};
class element
{
  string name;
  // vector<node> children;
  public:
  element(const string_view& name):name{name}
  {}
  void set_attribute (const string_view& key, const string_view& value)
  {

  }
  template<typename T>
  void append_child(const T& value)
  {

  }
};

using node = variant<element, text, comment>;

class document
{
  string name;
  vector<node> children;
  
  public:
  document(const string_view& name)
  :name{name}
  {

  }
  element create_element (const string_view& name) const
  {
    return element{name};
  }
  template<typename T>
  void append_child(const T& ele)
  {
    children.push_back(ele);
    
  }
  comment create_comment(const string_view& com) const
  {
    return comment{com};
  }

  text create_text(const string_view& tex) const
  {
    return text{tex};
  }

  

  string serialize() const
  {
    string str;
    str += OPEN;
    str += name;
    if(children.size())
    {
      str += CLOSE;
      serialize_children(str);
      str+=OPEN;
      str+=SLASH;
      str+=name;
      str+=CLOSE;
    }
    else{
      str+=" ";
      str+=SLASH;
      str+=CLOSE;
    }
  
    return str;
  }
  private:
  void serialize_children(string& str)
  {
    for(auto& x: children)
    {
      visit([&str](auto& e){
        e.serialize(str);
      }, x);
    }
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




ostream& operator<<(ostream& os, const document& ws)
{
  return os << ws.serialize();
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

  // doc.append_child(e1);
  // doc.append_child(e2);

  auto c = doc.create_comment("This is a comment");
  // doc.append_child(c);

  auto e3 = doc.create_element("info");
  // doc.append_child(e3);

  auto text = doc.create_text("This is a text");
  // e3.append_child(text);

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