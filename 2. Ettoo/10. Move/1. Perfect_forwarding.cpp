#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
using namespace std;


class Person
{
private:
    string s;
public:
    Person(const string& s)
    :s{s} 
    { 
        cout << "const parametrizado\n";
    }

    Person(string&& s)
    :s{s} 
    { 
        cout << "const de movida string\n";
    }

    Person(const Person& src)
    :s{src.s} 
    { 
        cout << "const copia\n";
    }

    Person(Person&& src)
    :s{move(src.s)} 
    { 
        cout << "const de movida object\n";
    }

    ~Person() { }

    void show() const
    {
        cout << s << "\n";
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

    template <typename T1, typename T2>
    Couple(T1&& a, T2&& b)
    :p1{forward<T1>(a)}, p2{forward<T2>(b)} 
    { 
        cout << "perfect forwarding\n";
    }

    void show() const
    {
        p1.show();
        p2.show();
    }
};

int main()
{
    // Person p{"juan perez"};
    // p.show();

    // Person q {move(p)};
    // q.show();//el objeto p ya no existe

    // puts("******************");

    Person a1 {"adan"};
    Person a2 {"Eva"};

    Couple a{move(a1), move(a2)};// con move en lugar de mandar un lvalue
    //mando un rvalue reference
    a.show();

    puts("******************");

    Person a3 {"oliver"};
    Person a4 {"kang mina"};
    Couple e{a3,a4};
    a.show();

    puts("******************");

    Couple c{Person{"lee min ho"}, a4};//hay que tener const para cada caso, no es mantenible....solucion =template
    c.show();

}