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
//para ordenar string usar sort

int cmp(const void* a, const void* b)
{
      auto aa = static_cast<const int*>(a);
      auto bb = static_cast<const int*>(b);

      return *aa - *bb;
}

int cmps(const void* a, const void* b)
{
      auto aa = (const char**)(a);
      auto bb = (const char**)(b);

      return strcmp(*aa, *bb);
}

int main()
{
      int m[] = {6,2,7,3,0,6};
      qsort(m, 6, sizeof(int), cmp);

      for(int n : m)
      {
            cout << n <<"\n";
      }

      const char* ss[] = {"marzo", "abril", "enero"};

      qsort(ss, 3, sizeof(const char*), cmps);
      
      for(auto i : ss)
      {
            cout << i <<"\n";
      }
}