#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
public:
    Person(string&& name)
    :name{move(name)} { cout << "moved string\n"; }

    Person(Person&& src)
    :name{move(src.name)} { cout << "moved object\n"; }

    Person(const Person& src)
    :name{src.name} { cout << "const copia\n";}

    ~Person() { }

    void show() const
    {
        cout << name << "\n";
    }
};

class Couple
{
private:
    Person p1;
    Person p2;
public:
    template <typename T1, typename T2>
    Couple(T1&& a, T2&& b)
    :p1{forward<T1>(a)}, p2{forward<T2>(b)} { }

    void show() const
    {
        p1.show();
        p2.show();
    }
};

int main()
{
    // Person p{"juan perez"};//hacemos una movida "string&&""
    // p.show();
    // puts("");

    // Person q{p};//hacemos una copia
    // q.show();
    // puts("");

    // Person r{move(Person{"ronald dante"})};//hacemos movida string y hacemos una movida object&&
    // r.show();

    // puts("******************");

    Person a1 {"oliver"};//hacemos una movida "string&&""
    Person a2 {"kang mina"};//hacemos una movida "string&&""

    Couple a{move(a1), move(a2)};// con move en lugar de mandar un lvalue
    //mando un rvalue reference, movida object&&
    a.show();

    Person a3 {"park shin hye"};//hacemos una movida "string&&""

    Couple c{Person{"lee min ho"}, a3};//esto solo es masntenible con templates
    c.show();
}