#include <iostream>
#include <cstdlib>//algorit qsort
#include <cstring>
//FUNCTION POINTERS
//*variables que almacenan una direccion de memoria
//*en lugar de apuntar a un dato apuntan a una funcion
//*la sintaxis de punteros a funciones especifican la signatura de la funcion apuntada
using namespace std;
//USOS
//*Polimorfismo "ad hoc"

//CALLBACKS

//tb se puede tener un alias
typedef void(*PROGRESSFPtr)(int, int);

void print_progress(int p, int c)
{
      cout << p << "de" << c << "elementos" << "\n";
}

void f(void(*PP)(int pos, int cant))//reeemplazar aca el alias
{
      for(size_t i = 0; i < 1'000'000'000; i++)
      {
            if(i%20'000'000)
                  PP(i, 20'000'000);
      }
}

int main()
{
      f(print_progress);
}