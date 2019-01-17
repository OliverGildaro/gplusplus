#include <iostream>
#include <string>
//TEMPLATE ESPECIALIZATION
using namespace std;

template<typename T>
void sucesor(const T& n)
{
      cout << n+1 << "\n";
}

template<>
void sucesor<int>(const int& n)
{
    
    cout << "esta es una especializacion " << n+1 << "\n";
}

template <>
void sucesor<string>(const string& s)
{
      cout << s << " no tiene sucesor\n";
}
//siempre poner las especializaciones por debajo

template<int N>//esta recursividad nunca termina
int factorial()
{
      return N*factorial<N-1>();
}
//con especializacion podemos poner un tope
template<>
int factorial<1>()
{
      return 1;
}

template <int N>
struct fact
{
      static const int value = N *fact<N-1>::value;
};

template <>

struct fact<1>
{
      static const int value = 1;
};

int main()
{
      sucesor(12);//siempre busca su especializacion, si no la encuentra usa una generica
      sucesor("hola"s);//tiene que ser convertida a string en este punto

    //   cout << factorial<5>() << "\n";
    //   cout << fact<6>::value <<"\n";//este metodo es mucho mas rapido dado que se come las llamadas a las funciones intermedias y devuelve directamente 720 el 6 debe ser conocido en tiempo de compilacion
}

//nm -C main | grep factorial... muestra las funciones que genera
//main.cpp -o main -O2... para vender mi programa, debo realizar la compilacion
//de esta manera pues es mas optima, esto en caso de la llamada a factorial()
//;la llamada a fact ya se come todas las llamadas intermedias