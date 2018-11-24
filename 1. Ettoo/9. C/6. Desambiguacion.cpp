a
#include <iostream>
using namespace std;

struct M
{
    void cantar()
    {
        cout << "lalal\n";
    }
};


struct N
{
    void cantar()
    {
        cout << "una piedra en mi camino\n";
    }
};


struct O : M, N
{
    void cantar()//hiding
    {
        cout << "los pollitos dicen\n";

    }
};


struct P: M, N
{
    
};


int main()
{
    M m;
    m.cantar();

    N n;
    n.cantar();

    O o;
    o.cantar();

    P p;
    p.M::cantar();//la unica forma de evitar la ambiguedad
    p.N::cantar();//la unica forma de evitar la ambiguedad
}

