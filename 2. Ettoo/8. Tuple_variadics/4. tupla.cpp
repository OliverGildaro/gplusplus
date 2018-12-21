#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>//incluye algoritmos de ordenamiento, busqueda, etc
//se encuentra sort, permite ordenar contenedores
using namespace std;

void show(const tuple<string, string, int>& s)
{
      cout << get<0>(s) << "\n";
      cout << get<1>(s) << "\n";
      cout << get<2>(s) << "\n";
}


struct Person
{
      string nombre;
      string apellido;
};


int main()
{
      tuple<string, string, int> p{"ozzy", "osbourn", 1948};

      auto p2 = make_tuple("jim"s, "morrison"s, 1942);

      show(p);
      show(p2);

      Person g[] ={
            Person{"juan", "perez"},
            Person{"omar", "rios"},
            Person{"alavro", "perez"},
            Person{"diego", "alvarez"},
            };

      sort(g, g+4, [](auto& a, auto& b){
            return tie(a.apellido, a.nombre) < tie(b.apellido, b.nombre);
      });

      
      for(auto& i : g)
      {
            cout << i.apellido << " " << i.nombre << "\n";
      }
      
}