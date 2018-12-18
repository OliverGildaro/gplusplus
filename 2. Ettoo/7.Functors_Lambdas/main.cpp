#include <iostream>
#include <cstdlib>//algorit qsort
#include <cstring>
//FUNCTORS (function objects)
//*objectos
//*cuya sintaxis permite llamarlos como si fuera funciones
using namespace std;

class Sumador
{
private:
      int descuento;
public:
      Sumador(int desc)
      :descuento{desc} { }
      ~Sumador() { }

      int operator()(int a, int b)
      {
            return a+ b;
      }
};

bool is_impar(int n)
{
      return n%2;
}

struct Range
{
      int min, max;
      bool operator()(int n) const
      {
            return n >= min && n <= max;
      }
};

template <typename PRED>
void show(const int* a, size_t n, PRED pred)//en c++ se suele llamar predicado a todas las funciones que se les pasa un valor y devuelven un booleano
{
      
      for(size_t i = 0; i < n; i++)
      {
            auto& e = a[i];
            if(pred(e))
                  cout << e <<"\n";
      }
      
}

int main()
{
//      Sumador s{5};//los functors pueden manejar estados a diferencia de los punteros a funciones

//      cout << s(10,15) << "\n";

     int nn[] = {5,3,6,7,8,45,65,12,4,3};

//      show(nn, 10, is_impar);
//       puts("*******");

// //      show(nn, 10, is_bet_10_a_30);
//       Range r{10,30};
//       show(nn, 10,r);
//       show(nn, 10,Range{2,8});

//       puts("*******");

      show(nn, 10, [] (int n){
            return n%2 ==0;
      });

      int min = 10;
      int max = 30;

      show(nn, 10, [min, max](int n){//si se pasa por valor min y max no pueden ser modificados
            return n<=min && n>=max;
      });//solo pueden ser modificados si son pasados por referencia
      //[=] todos los parametros son pasados por valor
      //[&] todos los parametros son pasados por referencia
}