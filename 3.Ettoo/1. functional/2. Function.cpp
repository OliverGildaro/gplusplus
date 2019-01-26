#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::placeholders;
//FUNCTION
//*me permite encapsular funciones
int sum(int x, int y)
{
    return x+y;
}

void v1(const string& s)
{
    cout << s <<"\n";
}

void v2(const string& s1, const string& s2)
{
    cout << s1 << " " << s2 << "\n";
}

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
    function<int(int, int)> q =sum;//recibe dos enteros y devuelve un entero

    cout << q(10, 15) <<"\n";//soporta tb functors y lambdas, es mejor que punetos a funciones

    vector<function<void (const string&)>> visitors;
    visitors.push_back(v1);
    visitors.push_back([](auto& s)
    {
        cout << "***" << s<<"\n";
    });

    string h = "hello world\n";
    visitors.push_back([&h](auto& s){
        cout << h << " " << s << "\n";
    });

    for(auto& e : visitors)
    {
        e("something ocurred");
    }

    auto x = bind(v2, "HHHHH", _1);//-1 dice que el segundo parametro de v2 va a ser el primer parametro que va a recibir es HHHH, es un placeholder... au,emtar el using............
    visitors.push_back(x);
    //bind, logra hacer match con los dos parametros de la funcion
    auto y = bind(v2, _1, "MMMMMM");
    visitors.push_back(y);


    for(auto& e : visitors)
    {
        e("something ocurred");
    }

    p(2, "lunes", 8);

    auto qq = bind(p, _1, _3, _2);//hay que lograr que haga macht con el metodo p()
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