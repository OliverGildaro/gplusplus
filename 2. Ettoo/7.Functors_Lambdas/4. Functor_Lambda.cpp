#include <iostream>
#include <cstdlib>//algorit qsort
#include <cstring>
//FUNCTORS (function objects)
//*objectos
//*cuya sintaxis permite llamarlos como si fuera funciones
using namespace std;
//VENTAJAS
//*un functor te permite definir diferentes tipos de comportamiento gracias a la actualizacion de sus estados
//*En punteros a funciones, se debe implementar una nueva funcion para cada comportamiento diferente
class Sumador
{
private:
      int descuento;//este es el estado que esta manejando
public:
      Sumador(int desc)
      :descuento{desc} { }
      ~Sumador() { }

      int operator()(int a, int b)
      {
            return a + b - descuento;
      }
};

struct Range
{
      int min, max;
      bool operator()(int n) const
      {
            return n >= min && n <= max;
      }
};

bool is_impar(int n)
{
      return n%2 != 0;
}

bool is_bet_10_a_30(int n)
{
      return n >= 10 && n <=30;
}

template <typename PRED>
void show(const int* a, size_t n, PRED pred)//en c++ se suele llamar predicado a todas las funciones que se les pasa un valor y devuelven un booleano
{
      
      for(size_t i = 0; i < n; i++)
      {
            int e = a[i];//declarar el tipo como auto permite una mejor funcionalidad
            if(pred(e))
                  cout << e <<"\n";
      }
      
}

int main()
{
      //ejemplo functor
      Sumador s{5};//los functors pueden manejar estados a diferencia de los punteros a funciones
      cout << s(10,15) << "\n";//se debe sobrecargar el operador()
      puts("este es un functor\n");

      //ejemplo puntero a funcion
      int nn[] = {5,12,3,24,8,45,65,14,4,3};
      show(nn, 10, is_impar);
      puts("son impares (puntero a funcion)\n");

      show(nn, 10, is_bet_10_a_30);
      puts("numeros entre 10 y 30 (puntero a funcion)\n");

      //ejemplo functor
      Range r{10,30};
      show(nn, 10, r);
      puts("numeros entre 10 y 30 (este es un functor)\n");//manda un objeto
      //y en show el objeto se comporta como una llamada a una funcion

      show(nn, 10, Range{2,7});
      puts("numeros entre 2 y 7 (este es un functor)\n"); 

      show(nn, 10, [] (int n){
            return n%2 == 0;//devuelve un boleano
      });
      puts("mostrar numeros pares (funcion lambda)\n"); 

      int min = 10;
      int max = 20;

      show(nn, 10, [min, max](int n){
            return n <= min || n >= max;
      });
      puts("numeros menores a 10 y mayores a 20 (funcion lambda)\n"); 

      //[min, max] solo pueden ser modificados si son pasados por referencia
      //[=] todos los parametros son pasados por valor
      //[&] todos los parametros son pasados por referencia
}