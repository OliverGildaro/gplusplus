#include <iostream>
#include "xml_writer.h"

using namespace std;

ostream& operator<<(ostream& os, const document& doc)
{
    return os << doc.serialize();
}

auto main() -> int
{
    xml_writer ws;

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

    auto c = doc.create_comment("This is a comment");
    doc.append_child(c);

    auto e3 = doc.create_element("info");
    doc.append_child(e3);

    auto text = doc.create_text("This is a text");
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

    // &lt; represents "<";
    // &gt; represents ">";
    // &amp; represents "&";
    // &apos; represents "'";
    // &quot; represents '"'.
}