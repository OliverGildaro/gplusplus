#include <iostream>
using namespace std;
// dangling pointers
    // punteros a direcciones de memoria invalidas
    // punteros a direcciones de memoria liberada
    // punteros sin inicializar

// para que sirven los punteros
    // para modificar parametros de salida de funciones

void q()
{
    int* s;
    int p;
    int m = 25;
    int* pm = &m;
    cout << s << "\n";
    cout << *s << "  *s\n";
    cout << p << "  p\n";
    cout << pm << "  pm\n";
    cout << *pm << "  *pm\n";
    *pm = 450;
    cout << m << "\n";
}

void sum(int a, int b, int* c)
{
    *c = a + b;
}

int main()
{
    cout << "esto es un fraude\n";
    cout << "hello friday" << endl;
    q();

    int a = 5, b = 8;
    int r;
    sum(a, b, &r);
    cout << r << "\n";
}
