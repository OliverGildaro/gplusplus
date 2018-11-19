#include <iostream>

using namespace std;
//referencias
//*son como punteros con restriccciones
//*tienen sintaxis simplificado
//*sirven para hacer paso de parametros por referencia

//Restricciones
//*se inicializan al crearse
//*son inmutables (la referencia siempre se va a referir al mismo elemento)
//*no existe aritmetica de referencias
//*no hay referencias nulas

void factorial(int n, int* r)
{
      int s =1;

      for(size_t i = 2; i <= n; i++)
      {
            s *= i;
      }
      *r = s;
}

void factorial2(int n, int& r)
{
      r = 1;
      
      for(size_t i = 2; i <= n; i++)
      {
            r *= i;
      }
}

int main()
{
      int f;
      factorial(6, &f);

      cout << f << "\n";

      int g;
      factorial2(5, g);

      cout << g << "\n";

      int p = 25;
      int q = 40;

      int& rp = p;//creando una referencia de p
      rp = q;
      rp++;

      cout << p << "\n";
      cout << q << "\n";

      auto rq = q;
      auto rs = rp;//rs no es una referencia
      auto& rr = rq;//con auto se debe especificar la referencia
}