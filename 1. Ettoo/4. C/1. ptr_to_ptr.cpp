#include <iostream>

using namespace std;


void es_par(const char** s, int n)
{
      if(n%2 == 0)
            *s = "es par";
      else
            *s = "es impar";
}

int main()
{
      const char* s = NULL;//NULL es la direccion de memoria cero que nadie utiliza
      //exclusivo para estas caracteristicas

      const char* p = nullptr;//c++11

      es_par(&p, 63);//puntero a puntero

      cout << p << "\n";
}