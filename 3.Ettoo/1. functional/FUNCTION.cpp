#include <iostream>
#include <functional>
#include <vector>
using namespace std;
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
}