// arrays
    // conjunto de elementos del mismo tipo
    // en c tienen tamano fijo
    // lo selementos se acceden por un indice

#include <iostream>
using namespace std;

int main()
{
    int q[5];  // compile time constant, tienen que ser conocida en tiempo de compilacion, no una variable
    q[0] = 10;
    q[1] = 5;
    q[2] = 8;
    q[3] = 4;
    q[4] = 9;
    for(int n : q)  // solo funciona con array declarados como arriba
    {
        cout << n << "\n";
    }

    int* r = q;
    for(int i = 0; i < 5; i++)
    {
        cout << r[i] << "\n"; // se puede acceder con un puntero escribiendolo como si fuera un arreglo
    }

    q[5] = 29;
    cout << q[5] << "\n";

    
    for(int i = 0; i < 1000000; i++)
    {
        cout << q[i] << "\n";
    }
    
}



