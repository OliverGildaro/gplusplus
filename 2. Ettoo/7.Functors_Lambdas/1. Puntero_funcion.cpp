#include <iostream>
//FUNCTION POINTERS
//*variables que almacenan una direccion de memoria
//*en lugar de apuntar a un dato apuntan a una funcion
//*la sintaxis de punteros a funciones especifican la signatura de la funcion apuntada
using namespace std;
//USOS
//*Polimorfismo "ad hoc"
int sum(int a, int b)
{
      return a+b;
}

int res(int a, int b)
{
      return a-b;
}

int main()
{
      int (*q)(int, int);
      q = sum;

      cout << q(18,17) << "\n";

      q = res;
      cout << q(25,4) << "\n";
}