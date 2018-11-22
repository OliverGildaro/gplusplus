//HERENCIA
//*crear clases a partir de otras ya existentes
//*en c++ pueden heredar de una o mas clases
//*es la base de la reutilizacion de codigo
//*Es la piedra fundamental del polimorfismo
//*en c++ no hay una jerarquia de clases  predefinida
//*la herencia puede ser public, protected o private
// herencia      base           derivada
//public         public         public
//               protected      protected
//protected     public          protected
//              protected       protected
//private       public          private
//              protected       private
#include <iostream>
using namespace std;
//Polimorfismo
//*cuando dos instancias de una misma clase base reaccionan de manera diferente ante un mismo mensaje
//*se implementa con sobreescritura

class Vehicle
{
private:
      size_t max_speed;
public:
      Vehicle(size_t ms)
      :max_speed{ms} { }
      virtual ~Vehicle() 
      { 
            cout <<"Bye vehicle\n";
      }

      virtual void print() const//virtual a;ade un puntero al final del objeto que apunta a un vtable
      //en el vtable hay una tabla que tiene un mapeo de los metodos marcados como virtuales
      //de esa forma llama a su metodo correspondiente
      {
            cout << "Max speed: " << max_speed << "\n";
      }
};

class Airplane : public Vehicle
{
private:
      size_t max_height;
public:
      Airplane(size_t ms, size_t mh)
      :Vehicle{ms}, max_height{mh} { }
      ~Airplane() 
      { 
            cout <<"Bye airplane\n";
      }

      void print() const override
      {
            Vehicle::print();
            cout << "Max heght: " << max_height << "\n";
      }
};

void show(const Vehicle a)//se debe pasar por referencia, por que llama al constructor de la clase base
//para hacer una copia y el airplane se construye solo la mitad
{
      a.print();
}

int main()
{
      Vehicle x{150};

      Airplane y{500, 3000};

      // cada objeto llama a su metodo print
      x.print();
      y.print();//hiding oculta los metodos de la clase padre ya que se llaman igual (print())

      show(x);
      show(y);

      Vehicle* z1 = new Vehicle{25};
      z1->print();

      Airplane* z2 = new Airplane{10, 100};
      z2->print();

      Vehicle* z3 = new Airplane{80, 20};
      z3->print();

      delete z1;//llama al destructor del vehiculo
      delete z2;//llama al destructor del aereoplano
      delete z3;//llama al destructor del vehiculo es por eso que el destructor debe ser virtual
      //para de esta forma llamar al destructor del airplane
}