#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::placeholders;//agregar para usar bind

void v1(const string& s) 
{ 
    cout << s <<"\n"; 
}

void v2(const string& s1, const string& s2) 
{ 
    cout << s1 << " " << s2 << "\n"; 
}

void v3(const string& s1, const string& s2, const string& s3)
{ 
    cout << s1 << " " << s2 << " " << s3 << "\n"; 
}

int main()
{
    vector<function<void (const string&)> > visitors;

    auto x = bind(v2, "HHHHH", _1);//bind recibe un puntero a una funcion, un string y un placeholder, y devuelve una funcion binded...
    visitors.push_back(x);
    auto y = bind(v2, _1, "MMMMMM");//...en la cual solo existe una variable a ser asignada, esa es determinada por el placeholder, el segundo objeto que recibe ya ha sido construido a partir del string "MMMMMM" recibido
    visitors.push_back(y);

    auto z = bind(v3, "AAAA", "BBBB", _1);
    visitors.push_back(z);

    for(auto& e : visitors)
    {
        e("something ocurred");
    }
}