
#include <iostream>
//POLICIES
//*comportamiento que se "INYECTA" a una clase template
//*Se especifica al momento de instanciar una clase template
//*se pasan a travez de un tipo parametrizado
//*tiene un gran rendimiento, reeemplaza el polimorfismo
//desventaja, todo es en tiempo de compilacion, no se puede aumentar nada en tiempo de ejecucion
using namespace std;

template <typename H> //H es mi politica
struct Animal
{
    H h;

    void hablar() const
    {
        h.hablar();
    }
};

struct PerroPolicy
{
    void hablar() const
    {
        cout << "guau\n";
    }
};

struct VacaPolicy
{
    void hablar() const
    {
        cout << "muu\n";
    }
};

using PERRO = Animal<PerroPolicy>; //un PERRO es un animal que usa la politica de perro "PerroPolicy"
using VACA = Animal<VacaPolicy>;

template <typename P>
void hablar(const Animal<P> &p)
{
    p.hablar();
}

int main()
{
    PERRO p;
    VACA v;
    hablar(p);
    hablar(v);
}
