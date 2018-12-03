#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
      size_t len;
      char* str;
public:
      String(const char* s)//constructor parametrizado
      :len{strlen(s)}
      {
            str = (char*)malloc(len+1);
            memcpy(str, s, len+1);
      }
      String()//default constructor
      :String("")
      {
      }
      String(const String& s)//constructor copia
      :len{s.len}, str{(char*)malloc(s.len+1)}
      {
            memcpy(str, s.str, len+1);
      }
      String& operator=(const String& s)//operator= overload
      {
            if(this == &s)
                  return *this;
            this->~String();
            len = s.len;
            str = (char*)malloc(len+1);
            memcpy(str, s.str, len+1);

            return *this;
      }
      String operator+(const String& s) const //devuelve un nuevo string
      {
            String aux;//instanciando un objeto vacio

            auto nlen = len + s.len;
            aux.str = (char*) realloc(aux.str, nlen+1);

            memcpy(aux.str, str, len);
            memcpy(aux.str + len, s.str, s.len+1);

            aux.len = nlen;

            return aux;
      }
      String& operator+=(const String& s)//si el *this se modifica no puede ser const
      {
            auto nlen = len + s.len;

            str = (char*) realloc(str, nlen+1);

            memcpy(str+len, s.str, s.len+1);
            len = nlen;

            return *this;
      }
      bool operator==(const String& src) const
      {
            if(this == &src)
                  return true;
            if(len != src.len)
                  return false;
            return memcmp(str, src.str, len) == 0;
      }

      bool operator!=(const String& src) const
      {
            if(strcmp(str, src.str)!=0)
                  return true;
            else
                  return false;
      }

      ~String() 
      { 
            free(str);
      }
      const char* c_str() const
      {
            return str;
      }
};



int main()
{
      sistema_facturacion sf;

      sf.agregar_producto("Leche", "PIL", "1245235423451", 50, 5);
      sf.agregar_producto("Yogurt", "PIL", "4245845254", 20, 15);
      sf.agregar_producto("Paneton", "IC Norte", "2390482394283", 500, 22.50);

      auto &f = sf.crear_factura("Omar Vera", "1029382015");
      f.agregar_item(1, "1245235423451");
      f.agregar_item(2, "2390482394283");

      auto &g = sf.crear_factura("Juan Pedro");
      g.agregar_item(2, "1245235423451");
      g.agregar_item(1, "4245845254");
      g.agregar_descuento(5);

      auto fc = sf.obtener_facturas_de_hoy();
      for (auto i = 0U; i < fc.size(); i++)
            ((factura&)fc[i]).mostrar();
}
