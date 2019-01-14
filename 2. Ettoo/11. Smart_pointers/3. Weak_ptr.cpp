#include <iostream>
#include <memory>
#include <vector>
//WEAK PTR
//*es un objeto que contiene a un shared_ptr
//*si el weak apunta a un objeto cuyo contador de referencia es cero no evita que se destruya
//el weak no hace que el contador de referencia se incremente
using namespace std;
//los shared pointers no funcionan con referencias circulares
//para esto usamos weak pointers

struct Hijo;

struct Padre
{
    shared_ptr<Hijo> hijo;//la relacion de composicion se da con el shared
    ~Padre()
    {
        cout << "adios hijo\n";
    }

    void cocinar()
    {
        cout << "yo cocino\n";
    }
};

struct Hijo
{
    weak_ptr<Padre> padre;//la agregacion se da con weak, Hijo agrega a Padre
    
    ~Hijo()
    {
        cout << "adios padre\n";
    }
};

int main()
{
    auto p = make_shared<Padre>();
    auto h = make_shared<Hijo>();

    p->hijo = h;
    h->padre = p;//nunca llama a sus destructores y quedan memory leaks
    h->padre.lock()->cocinar();//lock devuelve un shared_ptr,, weak no implementa operador flechita

    shared_ptr<string> s;

    weak_ptr<string> ws = s;

    {
        s = make_shared<string>("hello");
        ws = s;
        cout << ws.lock()->c_str() << "\n";
        cout << ws.expired() << "\n";
        s.reset();
    }
}