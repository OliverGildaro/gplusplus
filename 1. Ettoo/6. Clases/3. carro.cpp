#include <iostream>
#include <cstring>

using namespace std;

class carro
{
private:
      char* desc;
      char id[10];
public:
      carro(const char* des, const char* id)
      { 
            cout << "CONSTRUCTOR PARAMETRIZADO\n";
            auto len = strlen(des);
            desc = new char[len+1];
            memcpy(desc, des, len+1);
            strcpy(this->id, id);
      }

      carro(const carro& c)//cuando es una copia
      { 
            cout << "CONSTRUCTOR COPIA\n";
            strcpy(id, c.id);
            auto len = strlen(c.desc);
            desc = new char[len+1];
            memcpy(desc, c.desc, len+1);
      }

      ~carro() 
      { 
            cout << "bye\n";
            delete[] desc;
      }

      const char* get_desc() const
      {
            return desc;
      }

      const char* get_id() const
      {
            return id; 
      }

      carro& operator=(const carro& c)//cuando es una asignacion
      {
            cout << "operator=\n";
            if(this == &c)
                  return *this;
            this->~carro();
            auto len = strlen(c.desc);
            desc = new char[len+1];
            memcpy(desc, c.desc, len+1);
            return *this;
      }
};

int main()
{
      carro c1 = carro{"peta1997", "044h"};
      // cout << c1.get_desc() << "\n";
      // cout << c1.get_id() << "\n";

      // {
      //       carro c2{"toyota corolla", "544jed"};
      //       cout << c2.get_desc() << "\n";
      //       cout << c2.get_id() << "\n";
      // }//los objetos viden dentro del bloque declarado, en este punto c2 ya llama a su destructor

      // cout << "Hoy es lunes\n";

      carro c3 = carro{"labrorgin huracan 1956", "345te"};
      carro c4 = c1;//segmentation fault... c4 intenta liberar memoria que no existe
      //se debe implementar el constructor copia para un nuevo objeto(esta es una copia)
      c1 = c3 = c4; //esta es una asignacion..... segmentation fault (operator=)
}