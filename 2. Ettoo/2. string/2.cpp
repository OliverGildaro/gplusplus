#include <iostream>
#include <string>
#include <cstring>
// #include <string_view>
// using namespace std::string_literals;
// #include <stdexcept>
//Strings
using namespace std;

int main()
{
    auto dm = "depeche mode"s;

    for(string::iterator i = dm.begin(); i!= dm.end(); ++i)
    //.begin()devuelve un iterator que apunta al inicio de la cadena
    {
        cout <<*i <<"\n";//implementa el operador* para acceder a la cadena
    }
    
    // for(string::reverse_iterator i = dm.rbegin(); i!= dm.rend(); ++i)
    for(auto i = dm.rbegin(); i!= dm.rend(); ++i)
    {
        cout <<*i <<"\n";//implementa el operador* para acceder a la cadena
    }
    
    for(char k:dm)//esto solo es sintaxis, por abajo implementa el iterator
    {
        cout << k <<"\n";
    }

    char aux[100];
    char aux2[100];
    strcpy(aux, dm.c_str());
    strcpy(aux2, dm.data());

    cout << aux << "\n";
    cout << aux2 << "\n";
    strcat(aux, " rocks");
    cout << aux << "\n";
}