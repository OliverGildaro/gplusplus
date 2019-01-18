#include <iostream>
#include <vector>
#include <functional>
#include <optional>
#include <map>
#include <any>
using namespace std;


int main()
{
    any p = 1;

    cout << any_cast<int>(p) << "\n";

    p = "hola"s;

    cout << any_cast<string>(p) << "\n";

    vector<any> x;

    x.push_back(1);
    x.push_back("hola");
    x.push_back(true);

    for(auto e : x)
    {
        if(e.type() == typeid(int))
            cout << any_cast<int>(e) << "\n";
    }

}