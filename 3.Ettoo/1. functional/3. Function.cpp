#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::placeholders;//agregar para usar bind

void p(int a, const string& b, int c)
{ 
    cout << a << " " <<b << " " << c <<"\n"; 
}

void invertir(string& s)
{
    cout <<"V\n";
    reverse(s.begin(), s.end());//funciona con cadenas, vectores y arrays
}

int main()
{
    p(2, "lunes", 8);
    auto qq = bind(p, _1, _3, _2);
    qq(15, 25, "martes");

    auto rr = bind(p, 10, _1, 50);
    rr("miercoles");

    string xxx = "olumor";
    invertir(xxx);

    cout << xxx << "\n";

    string yy = "atinauj";
    auto inv = bind(invertir, ref(yy));

    inv();

    cout << yy << "\n";
}