#include <iostream>
#include <string>
//TEMPLATES
//*PRogramacion generica
//--consiste en tener tipos de datos y valores parametrizables
//--TURING COMPLETE
//--C++ esta evolucionando por este lado

//VENTAJAS
//*codigo reutilizable
//*No polimorfismo->mejor rendimiento
//*Mejor rendimientos con tipos abstractos
//CONTRAS
//*mensajes de error "terribles"(conceptos)
//*Tiempo de compilacion lento
//*No hay separacion .h y .cpp
//*los binarios son mas grandes
using namespace std;

template<typename T>
T sum(T a, T b)
{
      return a+b;
}

struct MyInt
{
      int n;
      MyInt operator+(const MyInt& p) const
      {
            return MyInt{n+p.n};
      }
};

int main()
{
    cout << sum(6, 8) << "\n";
    cout << sum(7.6, 8.5) << "\n";
    cout << sum<string>("hello", "world") <<"\n";//no compila por que no puede sumar const char*
    //en los casos que no puede deducir al tipo tenemos que ayudarle
    cout << sum(MyInt{8}, MyInt{4}).n << "\n";//devuelve un objeto del tipo MyInt, este llama a su atributo n
    //nm -C "ejecutable" | grep sum... con esto vemos en la terminal los metodos que ya se
    //han escrito en el binario "RAM"
    //son cuatro llamadas a cuatro funciones diferentes
}