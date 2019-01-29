#include <iostream>

using namespace std;

class Person
{
private:
    string name;
public:
    Person(string&& name)
    :name{move(name)} 
    { 
        cout << "moved string\n";
    }
    ~Person() { }

    Person(Person&& p)
    :name{move(p.name)}
    {
        cout << "moved object\n";
    }

    Person(const Person& p)
    :name{p.name} 
    { 
        cout << "const copia\n";
    }

    void show() const
    {
        cout << name <<" \n";
    }
};

class Couple
{
private:
    Person p1;
    Person p2;
public:
    // Couple(Person&& p1, Person&& p2)
    // :p1{move(p1)}, p2{move(p2)} { }
    // ~Couple() 
    // { 
    //     cout << "move semantics\n";
    // }

    template<typename T1, typename T2>
    Couple(T1&& p1, T2&& p2)
    :p1{forward<T1>(p1)}, p2{forward<T2>(p2)} 
    { 
        cout <<"perfect forwarding\n";
    }


    void show() const
    {
        p1.show();
        p2.show();
    }
};

int main()
{
    Person p{"Kim Tae Ri"};//hacemos una movida "string&&""
    p.show();
    puts("");

    Person q{move(p)};//hacemos una copia
    q.show();
    puts("");

    Person r{move(Person{"Park Shin Hye"})};//hacemos movida string y hacemos una movida object&&
    r.show();

    puts("******************");

    Person a1 {"Bae Su Ji"};//hacemos una movida "string&&""
    Person a2 {"Kim Woo Bin"};//hacemos una movida "string&&""

    Couple a{move(a1), move(a2)};// con move en lugar de mandar un lvalue
    //mando un rvalue reference, movida object&&
    a.show();

    Person a3 {"park shin hye"};//hacemos una movida "string&&""

    Couple c{Person{"lee min ho"}, a3};//esto solo es masntenible con templates
    c.show();
}