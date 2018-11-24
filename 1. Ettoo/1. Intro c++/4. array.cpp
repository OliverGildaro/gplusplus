#include <iostream>
//Arrays
using namespace std;

//*es un conjunto de elementos del mismo tipo
//*arrays tienen tama;o fijo
//*los elementos se acceden por un indice

int suma(const int* dd, size_t n) // al marcar como const le decimos al compilador que 
//la variable dd es solo de lectura
{
      auto s = 0;
      
      for(size_t i = 0; i < n; i++)
      {
            /* code */
            s = s +dd[i];
      }
      return s;
}

int main()
{
      // int p[5]; //el 5 es una constante que es conocida en tiempo de compilacion "compile time constant"

      // p[0] = 10;
      // p[1] = 4;
      // p[2] = 8;
      // p[3] = 4;
      // p[4] = 9;

      
      // for(int n : p) // este es el for_each
      // {
      //       cout << n << "\n";
      // }

      // int* r = p;

      // for(int i = 0; i < 5; i++)//aritmetica de punteros
      // {
      //       cout << r[i] << "\n";
      // }

      // p[5] = 29;

      // cout << p[5] << "\n";//no se ha recervado esta memoria, pero se la puede manipular

      
      // for(size_t i = 0U; i < 1000000; i++)
      // {
      //       /* code */
      //       cout << p[i] << "\n";
      // }

      int t[] = {4,3,2,5,6};

      int s = suma(t,5);

      cout << s <<"\n";
}