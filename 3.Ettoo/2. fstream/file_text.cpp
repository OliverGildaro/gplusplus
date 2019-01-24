#include <string>
#include <iostream>
#include <fstream>//archivo de escritura
#include <vector>
#include <string>
//STREAMS
using namespace std;

//cout es una instancia de ostream
//cout la salida standar de la terminal

struct person
{
    int id;
    string name;
};

ostream& operator<<(ostream& os, const person& p)
{
    return os << p.id << "," << p.name;
}

istream& operator>>(istream& is, person& p)
{
    string line;
    getline(is, line);//accede al archivo
    if(is.fail()) return is;
    auto pos = line.find(",");
    if(pos == string::npos)//npos es de la clase fstream, busca las comas sino la encuentra bota una excepcion
        throw 143;

    auto sid =line.substr(0, pos);
    auto name = line.substr(pos+1);
    p.id = stoi(sid);//transforma string a entero (stoi)
    p.name = name;

    return is;
}

int main()
{
    // ofstream f{"archivo.txt"};
    // if(!f.good())
    // {
    //     cerr << "error\n";
    //     return -4;
    // }

    // vector<string> ss = {"omar", "boris", "etto"};

    // for(auto& e : ss)
    // {
    //     f << e << "\n";
    // }

    // vector<person> pp;

    // pp.push_back({34, "juan lopez"});
    // pp.push_back({12, "jon snow"});
    // pp.push_back({18, "aria stark"});

    // ofstream g {"people.txt"};
    // for(auto& e : pp)
    // {
    //     g << e << "\n";
    // }

    //cargar desde un archivo un vector de personas

    ifstream h{"people.txt"};
    if(h.fail()) return -1;

    vector<person> ps2;

    while(true)
    {
        person aux;
        h >> aux;

        if(h.fail()) break;

        ps2.push_back(aux);
    }
    for(auto& p : ps2)
    {
        cout << p <<"\n";
    }
}   
