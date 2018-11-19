// almacenana una direccion de memoria 
// contiene informacion del tipo de dato en esa direccion de memoria

#include <iostream>
using namespace std;
int main()
{
    int* p = (int*) 0x20181109;
    cout << *p << "\n";
}
