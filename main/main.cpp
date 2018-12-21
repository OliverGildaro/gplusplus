// 1. Implement everything needed to let these tests pass.
// 2. You cannot use any standard container (vector, etc.), you need to create your own data structs.
// 3. You can use the std::string class.
// 4. Code that does not compile will render your exam into useless.
// 5. Code with crashes will cut your score in 50%.
// 6. Code with memory leaks will have 10 points less.

// Enjoy!!
#include <iostream>
#include <string>


using namespace std;

const string OPENBRACK = "[";
const string CLOSEBRACK = "]";
const string COMA = ",";
const string SPACE = " ";
const string COMILLA = "\"";

class object
{
private:
      string str;
public:
      object(const string & str)
      :str{str} { }
      ~object() { }

      const string get_str() const
      {
            return str;
      }
};

class f_array
{
private:
      object** objects;
      size_t len;
public:
      f_array()
      :objects{static_cast<object**>(malloc(0))}, len{0} { }
      ~f_array() { }

      void add(const string& str)
      {
            object* obj = new object{str};
            objects = static_cast<object**>(realloc(objects, (len+1)*sizeof(object*)));
            objects[len++] = obj;
      }

      size_t size() const
      {
            return len;
      }

      const object* operator[](size_t position) const
      {
            return objects[position];
      }
      object* operator[](size_t position)
      {
            return objects[position];
      }
};

class JsonObject
{
private:
      
public:
      JsonObject() { }
      ~JsonObject() { }

      void add(const string& key, const string& value)
      {

      }
      void add(const string& key, int value)
      {

      }
};

class JsonArray
{
private:
      f_array array_json;
public:
      JsonArray() { }
      ~JsonArray() { }

      const string to_string(bool band = false)
      {
            string aux;
            aux += OPENBRACK;
            if(band == true)
            {

            }
            
            for(size_t i = 0; i < array_json.size(); i++)
            {
                  if(i == 0)
                  {
                        aux += array_json[i]->get_str();
                        aux += COMA;
                        continue;
                  }
                  aux += SPACE;
                  aux += COMILLA;
                  aux += array_json[i]->get_str();
                  aux += COMILLA;
                  if(i == array_json.size() -1)
                        break;
                  aux += COMA;
            }
            aux += CLOSEBRACK;
            cout << aux <<"\n";
            return aux;
      }

      void add(int number)
      {
            array_json.add(std::to_string(number));
      }
      void add(const string& name)
      {
            array_json.add(name);
      }

      void add(const JsonObject& obj)
      {

      }
};

// bool test0()
// {
//     JsonNumber jn { 3141 };
//     return jn.to_string() == "3141";
// }

// bool test1()
// {
//     JsonObject jo;
//     return jo.to_string() == "{}";
// }

// bool test2()
// {
//     JsonString js { "hello" };
//     return js.to_string() == "\"hello\"";
// }

bool test3()
{
    JsonArray ja;
    return ja.to_string() == "[]";
}

bool test4()
{
    JsonArray ja;
    ja.add(125);
    ja.add("hello");
    ja.add("friends");
    cout << "[125, \"hello\", \"friends\"]" <<"\n";
    return ja.to_string() == "[125, \"hello\", \"friends\"]";
}

// bool test5()
// {
//     JsonObject jo;
//     jo.add("firstName", "John");
//     jo.add("lastName", "Smith");
//     jo.add("birthYear", 1977);
//     return jo.to_string() == "{ \"firstName\": \"John\", \"lastName\": \"Smith\", \"birthYear\": 1977 }";
// }

bool test6()
{
    JsonArray ja;
    ja.add("hello");

    JsonObject jo;
    jo.add("firstName", "John");
    jo.add("lastName", "Smith");
    jo.add("birthYear", 1977);

    ja.add(jo);

    ja.add(1492);

    return ja.to_string() == "[\"hello\", { \"firstName\": \"John\", \"lastName\": \"Smith\", \"birthYear\": 1977 }, 1492]";
}

// bool test7()
// {
//     JsonObject jo;

//     jo.add("nombre", "jugo de frutas");

//     JsonArray ingredients;
//     ingredients.add("leche");
//     ingredients.add("frutilla");
//     ingredients.add("manzana");
//     ingredients.add("azucar");

//     jo.add("ingredientes", ingredients);
//     return jo.to_string() == "{ \"nombre\": \"jugo de frutas\", \"ingredientes\": [ \"leche\", \"frutilla\", \"manzana\", \"azucar\" ] }";
// }

bool test8()
{
    JsonArray ja;
    ja.add("hello");

    JsonObject jo;
    jo.add("firstName", "John");
    jo.add("lastName", "Smith");
    jo.add("birthYear", 1977);

    ja.add(jo);

    ja.add(1492);

    return ja.to_string(true) ==
    "[\n"
    "    \"hello\",\n"
    "    {\n"
    "        \"firstName\": \"John\",\n"
    "        \"lastName\": \"Smith\",\n"
    "        \"birthYear\": 1977\n"
    "    },\n"
    "    1492\n"
    "]";
}

// bool test9()
// {
//     JsonObject jo;

//     jo.add("nombre", "jugo de frutas");

//     JsonArray ingredients;
//     ingredients.add("leche");
//     ingredients.add("frutilla");
//     ingredients.add("manzana");
//     ingredients.add("azucar");

//     jo.add("ingredientes", ingredients);
//     return jo.to_string(true, 2) ==
//     "{\n"
//     "  \"nombre\": \"jugo de frutas\",\n"
//     "  \"ingredientes\": [\n"
//     "    \"leche\",\n"
//     "    \"frutilla\",\n"
//     "    \"manzana\",\n"
//     "    \"azucar\"\n"
//     "  ]\n"
//     "}";
// }

int main()
{
    size_t score = 0;
//     score += test1();
//     score += test2();
//     score += test0();
    score += test3();
    score += test4();
//     score += test5();
    score += test6();
//     score += test7();
    score += test8();
//     score += test9();

    cout << "Score: " << score << " / 10\n";
}