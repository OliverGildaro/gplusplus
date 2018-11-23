//Clases Abstractas
//*Es una clase que tiene uno o mas metodos abstractos "puros"
//*Obliga a implementar los metodos abstractos en clases hijas
//*Es una clase que no se puede instanciar
#include <iostream>

using namespace std;

class Animal
{
public:
    Animal() { }
    virtual ~Animal() { }
    virtual void comunicarse() const = 0;//metodo virtual puro
};

class Vaca : public Animal
{
private:
    
public:
    Vaca() { }
    ~Vaca() { }
    void comunicarse() const override
    {
        cout << "Muuuu\n";
    }
};

class Perro : public Animal
{
private:
    
public:
    Perro() { }
    ~Perro() { }

    void comunicarse() const override
    {
        cout << "Guaaauu\n";
    }
};

int main()
{
    Animal* e = new Vaca(); //polimorfismo abstracto generalmente funciona con punteros y debe instanciar el padre
    //nose puede instanciar animales es por eso que debe ser puntero
    e->comunicarse();
    
    delete e;

    e = new Perro();//el puntero ya ha sido creado, puedo reutilizarlo para instanciar un perro
    e->comunicarse();
    delete e;
}