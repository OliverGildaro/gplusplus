// 1. Implement everything needed to let these tests pass.
// 2. You cannot use any standard container (vector, etc.), you need to create your own data structs.
// 3. You can use the std::string class.
// 4. Code that does not compile will render your exam into useless.
// 5. Code with crashes will cut your score in 50%.
// 6. Code with memory leaks will have 10 points less.

#include <iostream>

using namespace std;

const string KEYOP = "{";
const string KEYCL = "}";
const string BRACKOP = "[";
const string BRACKCL = "]";
const string SPACE = " ";
const string DOSP = ":";
const string COMA = ",";
const string COMILLAS = "\"";
const string ENDL = "\n";

class object
{
private:
      
public:
      object() { }
      ~object() { }
};

class object_pair_string : public object
{
private:
      string key;
      string name;
public:
      object_pair_string(const string& key, const string& name)
      :key{key}, name{name} { }
      ~object_pair_string() { }

      const string get_key() const
      {
            return key;
      }

      const string get_name() const
      {
            return name;
      }
};

class object_string : public object
{
private:
      string name;
public:
      object_string(const string& name)
      :name{name} { }
      ~object_string() { }

      const string get_name() const
      {
            return name;
      }
};

class array_object
{
protected:
      object** objects;
      size_t len;
public:
      array_object()
      :objects{static_cast<object**>(malloc(0))}, len{0} { }
      ~array_object() { }

      void add(object* obj)
      {
            objects = static_cast<object**>(realloc(objects, (len+1)*sizeof(object*)));
            objects[len++] = obj;
      }

      object* operator[](size_t position)
      {
            return objects[position];
      }

      bool exist()
      {
            return  len > 0 ? true : false;
      }

      size_t size()
      {
            return len;
      }
};

class array_pair_string : public array_object
{
private:
      
public:
      array_pair_string() { }
      ~array_pair_string() { }

     
};

class array_string : public array_object
{
private:
      
public:
      array_string() { }
      ~array_string() { }
};

class JsonArray
{
private:
      array_string array_str;
public:
      JsonArray() { }
      ~JsonArray() { }

      void add(const string& name)
      {
            object_string* new_obj = new object_string{name};
            array_str.add(new_obj);
      }

      object* operator[](size_t position)
      {
            return array_str[position];
      }

      size_t size()
      {
            return array_str.size();
      }
};

class JsonObject
{
private:
      array_pair_string array_str_pair;
      array_string array_str;
public:
      JsonObject() { }
      ~JsonObject() { }

      void child(string& aux, bool flag)
      {
            // cout << "hola\n";
            aux += SPACE;
            aux += COMILLAS;
            aux += static_cast<const object_string*>(array_str[0])->get_name();
            aux += COMILLAS;
            aux += DOSP;
            aux += SPACE;
            aux += BRACKOP;
            if(flag == true) aux += ENDL;
            if(array_str.exist())
            {
                  for(size_t i = 1; i < array_str.size(); i++)
                  {
                        aux += SPACE;
                        // if(flag == true) aux += ENDL;
                        aux += COMILLAS;
                        aux += static_cast<const object_string*>(array_str[i])->get_name();
                        aux += COMILLAS;
                        if(i ==  array_str.size() - 1 )
                              break;
                        aux += COMA;
                  }
            }
            aux += SPACE;
            aux += BRACKCL;
            aux += SPACE;
      }
// "ingredientes\": [ \"leche\", \"frutilla\", \"manzana\", \"azucar\" ] }" <<"\n"

      string to_string(bool flag = false, size_t num = 0)
      {
            string aux;
            aux += KEYOP;
            if(flag == true) aux += ENDL;
            if(array_str_pair.exist())
            {
                  for(size_t i = 0; i < array_str_pair.size(); i++)
                  {
                        aux += SPACE;
                        aux += COMILLAS;
                        aux += static_cast<const object_pair_string*>(array_str_pair[i])->get_key();
                        aux += COMILLAS;
                        aux += DOSP;
                        aux += SPACE;
                        // if(i == array_str_pair.size() - 1 && array_str_pair.size() > 1)
                        {
                              // aux += SPACE;
                              // cout << aux <<"\n";
                              aux += static_cast<const object_pair_string*>(array_str_pair[i])->get_name();
                              aux += SPACE;
                              break;
                        }
                        aux += COMILLAS;
                        aux += static_cast<const object_pair_string*>(array_str_pair[i])->get_name();
                        aux += COMILLAS;
                        aux += COMA;
                        aux += ENDL;
                        cout << array_str.size() << "\n";
                        if(array_str.exist())
                        {
                              cout << "hola\n";
                              child(aux, flag);
                        }
                  }
            }
            aux += KEYCL;
            return aux;
      }
// "{ \"nombre\": \"jugo de frutas\", 

      void add(const string& name, const string& last_name)
      {
            object_pair_string* new_obj = new object_pair_string{name, last_name};
            array_str_pair.add(new_obj);
      }

      void add(const string& name, size_t year)
      {
            string aux;
            aux = std::to_string(year);
            object_pair_string* new_obj = new object_pair_string{name, aux};
            array_str_pair.add(new_obj);
      }

      void add(const string& name_JsonArray, JsonArray& obj)
      {
            object_string* new_obj = new object_string{name_JsonArray};
            array_str.add(new_obj);
            for(size_t i = 0; i < obj.size(); i++)
            {
                  static_cast<obje>obj[i]
                  array_str.add(obj[i]);
            }
      }
};



// bool test0()
// {
//     JsonNumber jn { 3141 };
//     return jn.to_string() == "3141";
// }

bool test1()
{
    JsonObject jo;
    return jo.to_string() == "{}";
}

// bool test2()
// {
//     JsonString js { "hello" };
//     return js.to_string() == "\"hello\"";
// }

// bool test3()
// {
//     JsonArray ja;
//     return ja.to_string() == "[]";
// }

// bool test4()
// {
//     JsonArray ja;
//     ja.add(125);
//     ja.add("hello");
//     ja.add("friends");
//     return ja.to_string() == "[125, \"hello\", \"friends\"]";
// }

bool test5()
{
    JsonObject jo;
    jo.add("firstName", "John");
    jo.add("lastName", "Smith");
    jo.add("birthYear", 1977);
//     cout << jo.to_string() << "\n";
//     cout << "{ \"firstName\": \"John\", \"lastName\": \"Smith\", \"birthYear\": 1977 }" << "\n";
    return jo.to_string() == "{ \"firstName\": \"John\", \"lastName\": \"Smith\", \"birthYear\": 1977 }";
}

// bool test6()
// {
//     JsonArray ja;
//     ja.add("hello");

//     JsonObject jo;
//     jo.add("firstName", "John");
//     jo.add("lastName", "Smith");
//     jo.add("birthYear", 1977);

//     ja.add(jo);

//     ja.add(1492);

//     return ja.to_string() == "[\"hello\", { \"firstName\": \"John\", \"lastName\": \"Smith\", \"birthYear\": 1977 }, 1492]";
// }

bool test7()
{
    JsonObject jo;

    jo.add("nombre", "jugo de frutas");

    JsonArray ingredients;
    ingredients.add("leche");
    ingredients.add("frutilla");
    ingredients.add("manzana");
    ingredients.add("azucar");

    jo.add("ingredientes", ingredients);
//     cout << jo.to_string() << "\n";
//     cout << "{ \"nombre\": \"jugo de frutas\", \"ingredientes\": [ \"leche\", \"frutilla\", \"manzana\", \"azucar\" ] }" <<"\n";
    return jo.to_string() == "{ \"nombre\": \"jugo de frutas\", \"ingredientes\": [ \"leche\", \"frutilla\", \"manzana\", \"azucar\" ] }";
}

// bool test8()
// {
//     JsonArray ja;
//     ja.add("hello");

//     JsonObject jo;
//     jo.add("firstName", "John");
//     jo.add("lastName", "Smith");
//     jo.add("birthYear", 1977);

//     ja.add(jo);

//     ja.add(1492);

//     return ja.to_string(true) ==
//     "[\n"
//     "    \"hello\",\n"
//     "    {\n"
//     "        \"firstName\": \"John\",\n"
//     "        \"lastName\": \"Smith\",\n"
//     "        \"birthYear\": 1977\n"
//     "    },\n"
//     "    1492\n"
//     "]";
// }

bool test9()
{
    JsonObject jo;

    jo.add("nombre", "jugo de frutas");

    JsonArray ingredients;
    ingredients.add("leche");
    ingredients.add("frutilla");
    ingredients.add("manzana");
    ingredients.add("azucar");

    jo.add("ingredientes", ingredients);
    cout << jo.to_string(true, 2) << "\n";
//     cout << "{\n"
//     "  \"nombre\": \"jugo de frutas\",\n"
//     "  \"ingredientes\": [\n"
//     "    \"leche\",\n"
//     "    \"frutilla\",\n"
//     "    \"manzana\",\n"
//     "    \"azucar\"\n"
//     "  ]\n"
//     "}";
    return jo.to_string(true, 2) ==
    "{\n"
    "  \"nombre\": \"jugo de frutas\",\n"
    "  \"ingredientes\": [\n"
    "    \"leche\",\n"
    "    \"frutilla\",\n"
    "    \"manzana\",\n"
    "    \"azucar\"\n"
    "  ]\n"
    "}";
}

int main()
{
    size_t score = 0;
    score += test1();
//     score += test2();
//     score += test0();
//     score += test3();
//     score += test4();
    score += test5();
//     score += test6();
    score += test7();
//     score += test8();
    score += test9();

    cout << "Score: " << score << " / 10\n";
}