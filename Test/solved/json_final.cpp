// bool test0()
// {
//     json_null j;
//     return j.to_string() == "null";
// }

// bool test1()
// {
//     json_number j { 125 };
//     return j.to_string() == "125";
// }

// bool test2()
// {
//     json_bool j { true };
//     json_bool k { false };
//     return j.to_string() == "true" && k.to_string() == "false";
// }

// bool test3()
// {
//     json_string j { "hello world" };
//     return j.to_string() == "\"hello world\""; }

// bool test4()
// {
//     json_string j = "my name is \"Michael\"";
//     return j.to_string() == "\"my name is \\\"Michael\\\"\"";
// }

// bool test5()
// {
//     json_object j;
//     return j.to_string() == "{ }";
// }
#include <iostream>
#include <variant>
#include <vector>
#include <sstream>
using namespace std;

const string OPENBRACK = "[";
const string CLOSEBRACK = "]";
const string COMA = ",";
const string QUOTE = "\"";
const string SPACE = " ";
const string OPENKEY = "{";
const string CLOSEKEY = "}";
const string DOSP = ":";

struct json_number
{
    int num;

    string to_string()
    {
        return std::to_string(num);
    }
};

struct json_bool
{
    bool band;

    string to_string()
    {
        stringstream ss;
        ss << boolalpha << band;
        return ss.str();
    }
};


struct json_string
{
    string s;

    string to_string()
    {
        stringstream ss;
        ss << QUOTE << s << QUOTE;
        return ss.str();
    }
};

using node2 = variant<json_string, json_number>;

class json_object
{
private:
    vector<node2> m_vec;
public:
    json_object() { }
    ~json_object() { }

    void add(const string& key, const string& value)
    {
        m_vec.push_back(json_string{key});
        m_vec.push_back(json_string{value});
    }

    void add(const string& key, int value)
    {
        m_vec.push_back(json_string{key});
        m_vec.push_back(json_number{value});
    }

    string to_string()
    {
        string s;
        s += OPENKEY;
        s += SPACE;
        for(size_t i = 0; i < m_vec.size(); i++)
        {
            visit([&s](auto& x){
                s += x.to_string();
            }, m_vec[i]);
            if(i % 2 == 0)
            {
                s += SPACE;
                s += DOSP;
                s += SPACE;
            }
            if(i % 2 != 0 && i < m_vec.size()-1)
            {
                s += COMA;
                s += SPACE;
            }
        }
        s += SPACE;
        s += CLOSEKEY;
        return s;
    }
};


using node = variant<json_number, json_string, json_bool, json_object>;

class json_array
{
private:
    vector<node> m_vec;
public:
    json_array() { }
    ~json_array() { }

    json_array& add(const string& s)
    {
        m_vec.push_back(json_string{s});
        return *this;
    }
    void add(int num)
    {
        m_vec.push_back(json_number{num});
    }
    void add(bool band)
    {
        m_vec.push_back(json_bool{band});
    }

    json_array& add(const json_object& obj)
    {
        m_vec.push_back(obj);
        return *this;
    }

    string to_string()
    {
        string s;
        s += OPENBRACK;
        for(size_t i =0; i<m_vec.size(); i++)
        {
            visit([&s](auto& x){
                s += x.to_string();
            }, m_vec[i]);
            if(i< m_vec.size()-1)
            {
                s += COMA;
                s += SPACE;
            }
        }
        s += CLOSEBRACK;
        return s;
    }
};

bool test6()
{
    json_array ja;
    ja.add(true);
    ja.add("hello world"s);
    ja.add(237);

    return ja.to_string() == "[true, \"hello world\", 237]";
}

bool test7()
{
    json_object jo;
    jo.add("first_name", "juan");
    jo.add("last_name", "perez");
    jo.add("birth_year", 1970);

    return jo.to_string() == "{ \"first_name\" : \"juan\", \"last_name\" : \"perez\", \"birth_year\" : 1970 }";
}

bool test8()
{
    json_array ja;

    json_object jo1;
    jo1.add("first_name", "juan");
    jo1.add("last_name", "perez");
    jo1.add("birth_year", 1970);

    json_object jo2;
    jo2.add("first_name", "omar");
    jo2.add("last_name", "vera");
    jo2.add("birth_year", 1995);

    ja.add(jo1).add(jo2);

    return ja.to_string() == "[{ \"first_name\" : \"juan\", \"last_name\" : \"perez\", \"birth_year\" : 1970 }, { \"first_name\" : \"omar\", \"last_name\" : \"vera\", \"birth_year\" : 1995 }]";
}

// bool test9()
// {
//     json_object jo;
//     jo.add("marca", "volkswagen");
//     jo.add("modelos", json_array {}.add("jetta").add("new beetle").add("golf"));
//     jo.add("descripcion", json_object {}.add("pais", "alemania").add("produccion_anual", 50000));
//     return jo.to_string() == "{ \"marca\" : \"volkswagen\", \"modelos\" : [\"jetta\", \"new beetle\", \"golf\"], \"descripcion\" : { \"pais\" : \"alemania\", \"produccion_anual\" : 50000 } }";
// }

int main()
{
    auto score = 0.0;

    // score += 0.5 * static_cast<double>(test0());
    // score += 0.5 * static_cast<double>(test1());
    // score += 0.5 * static_cast<double>(test2());
    // score += 0.5 * static_cast<double>(test3());
    // score += 0.5 * static_cast<double>(test4());
    // score += 0.5 * static_cast<double>(test5());
    score += 1.6 * static_cast<double>(test6());
    score += 1.7 * static_cast<double>(test7());
    score += 1.8 * static_cast<double>(test8());
    // score += 1.9 * static_cast<double>(test9());

    cout << score * 10 << " / 100\n";

    return 0;
}