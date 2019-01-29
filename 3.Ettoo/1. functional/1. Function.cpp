#include <iostream>
#include <functional>
#include <vector>
//FUNCTION
//*me permite encapsular funciones
using namespace std;

int sum(int a, int b)
{
    return a+b;
}

void v1(const string& value)
{
    cout << value <<"\n";
}

int main()
{
    function<int(int, int)> q =sum;//recibe dos enteros y devuelve un entero

    cout << q(10, 15) <<"\n";//soporta tb functors y lambdas, es mejor que punetos a funciones

    vector<function<void (const string&)>> visitors;//declaro un vector en el que cada objeto que se guarde sera de tipo "function" el cual recibira un const string&
    visitors.push_back(v1);//le mando un puntero a una funcion
    visitors.push_back([](const string& s)//le mando un lambda
    {
        cout << "***" << s<<"\n";
    });

    string h = "hello world";
    visitors.push_back([&h](const string& s){//le mando un lambda y tb absorbe un string
        cout << h << " " << s << "\n";
    });

    for(auto& e : visitors)//itero en mi vector, cada uno es una funcion que recibe algo, en este caso "something ocurred"
    {
        e("something ocurred");
    }
}