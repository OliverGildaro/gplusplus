//Clases Abstractas.... Interfaz en este caso
//*Es una clase que tiene uno o mas metodos abstractos "puros"
//*Obliga a implementar los metodos abstractos en clases hijas
//*Es una clase que no se puede instanciar
#include <iostream>

using namespace std;

class IAnimal
{
public:
      IAnimal() { }
      virtual ~IAnimal() { }
      virtual void comunicarse() const = 0;
};

class Vaca : public IAnimal
{
public:
      Vaca() { }
      ~Vaca() { }
      void comunicarse() const override
      {
            cout << "MUUUUUU\n";
      }
};

class Perro : public IAnimal
{
public:
      Perro() { }
      ~Perro() { }

      void comunicarse() const override
      {
            cout << "GUAUUU\n";
      }
};

int main()
{
    IAnimal* e = new Vaca(); //polimorfismo abstracto, funciona con punteros y debe instanciar el padre
    //nose puede instanciar animales es por eso que debe ser puntero
    e->comunicarse();
    
    delete e;

    e = new Perro();//el puntero ya ha sido creado, puedo reutilizarlo para instanciar un perro
    e->comunicarse();
    delete e;
}