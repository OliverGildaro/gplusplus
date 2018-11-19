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

      carro(const carro& c)
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
};

int main()
{
      carro c1 = carro{"peta1997", "044h"};
      cout << c1.get_desc() << "\n";
      cout << c1.get_id() << "\n";

      {
            carro c2{"toyota corolla", "544jed"};
            cout << c2.get_desc() << "\n";
            cout << c2.get_id() << "\n";
      }//los objetos viden dentro del bloque declarado, en este punto c2 ya llama a su destructor

      cout << "Hoy es lunes\n";

      auto c3 = carro{"labrorgin huracan 1956", "345te"};

      auto c4 = c3;//segmentation falut... c4 intenta liberar memoria que ya ha sido liberada

}