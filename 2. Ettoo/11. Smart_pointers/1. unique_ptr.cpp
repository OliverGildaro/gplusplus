#include <iostream>
#include <memory>
#include <vector>
//SMART POINTERS
//*una clase que implementa el operador -> y *
//*se comporta como un puntero sin serlo porque se crea en el stack
//*c++ 98 auto_ptr is deprecated, cambiar a unique en caso de encontrarlo
//c++ 11
//*unique
//*shared
using namespace std;

struct N
{
    int n;

    N(int n)
    :n{n} { }
    ~N()
    {
        cout << "bye\n";
    }
};


struct Animal
{
    virtual ~Animal() 
    { 
        cout << "chau\n";
    }
};

struct Vaca : Animal
{
};

struct Oveja : Animal
{
    
};

struct Zoo
{
    // Animal* a1;
    // Animal* a2;
    // Animal* a3;

    unique_ptr<Animal> a1;
    unique_ptr<Animal> a2;
    unique_ptr<Animal> a3;

    Zoo(Animal* a1, Animal* a2, Animal* a3)
    :a1{a1}, a2{a2}, a3{a3} 
    { 
        throw 4;//esto da un comporatamiento indeterminada a pesar que qeu z sea una variable de stack
        //solucion.... smart pointer
    }

    ~Zoo()
    {
        // delete a1;
        // delete a2;
        // delete a3;
    }
};


int main()
{
    unique_ptr<N> p{new N{16}};
    cout << p->n <<"\n";
    cout << (*p).n << "\n";

    N* pp = p.get();//me devuelve el puntero al objeto creado en el heap
    cout << pp->n << "\n";

    unique_ptr<N> q = make_unique<N>(25);// este es equivalente a unique_ptr<N> p{new N{16}};
    //no funciona sin constructores
    cout << q->n << "\n";
    
    auto r = move(q);//como es un unique podemos hacer una movida, no una copia
    cout << r->n << "\n";
    cout << q.get() << "\n";

    try
    {
        Zoo z{new Vaca{}, new Oveja, new Oveja{}};
    }
    catch(...)
    {
        cout << "error\n";
    }

    vector<unique_ptr<Animal>> animals;//debe ser puntero por que sino solo recibe animales
    animals.emplace_back(new Oveja());//crea el objeto dentro del vector
    animals.push_back(make_unique<Vaca>());//hace una copia o una movida

    for(auto& a : animals)
    {
        cout << typeid(*a).name() << "\n";//devuelve el nombre que tiene la clase
    }
}