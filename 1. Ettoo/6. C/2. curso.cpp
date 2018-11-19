//CLASES
//*son structr con todo privado por defecto
#include <iostream>
#include <cstring>
using namespace std;

class Curso
{
private:
      char nombre[16];
      size_t alumnos;
public:
      Curso(const char* n, size_t al)
      { 
            strcpy(nombre, n);
            alumnos = al;
      }
      ~Curso() 
      { 
            cout << "bye\n";
      }

      void mostrar() const//es un metodo constante que no va a modificar los atributos de la clase
      //un metodo constante solo puede llamar a otro metodo que es marcado como const
      {
            cout << nombre << " " << alumnos << "\n";
      }
};

//RAII
//*resource adquisition is initialization.... los objetos son propietraios de la memoria que utilizan
// y son ellos los que liberan la memoria que adquirieron, esto solo con variables de stack

int main()
{
      Curso c{"dev27", 17};
      c.mostrar();

      // Curso c2 = c;
      // c2.mostrar();

      Curso* d = new Curso{"dev27h",18};
      d->mostrar();

      delete d;//el operador delete hace la llamada al destructor del objeto 
      //y despues libera la memoria utilizada por este objeto
}