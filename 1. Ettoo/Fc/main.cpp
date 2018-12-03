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
      ~String() 
      { 
            free(str);
      }
      const char* c_str() const
      {
            return str;
      }
};

class sistema_facturacion;

class object
{
private:
      
public:
      object() { }
      ~object() { }
      virtual void mostrar() const = 0;
      bool equals_to(const object& ) const
      {
            return false;
      }
};

class array_list
{
private:
      object** objects;
      size_t len;
public:
      array_list()
      :objects{(object**)malloc(0)}, len{0} { }
      ~array_list() { }
      void add(object* obj)
      {
            objects = (object**) realloc(objects, (len+1)*sizeof(object*));
            objects[len++] = obj;
      }
      size_t size() const
      {
            return len;
      }
      object& operator[](size_t position)
      {
            return *(objects[position]);
      }
      const object& operator[](size_t position) const
      {
            return *(objects[position]);
      }
      void mostrar() const
      {
            for(size_t i = 0; i < len; i++)
            {
                  (*this)[i].mostrar();
            }
      }
      const object& get_object(const object& obj)const
      {
            for(size_t i = 0; i < len; i++)
            {
                  if((*this)[i].equals_to(obj))
                        return (*this)[i];
            }
            throw 0;
      }
};

class producto : public object
{
private:
      String name;
      String brand;
      String code;
      size_t quanty;
      double price;
public:
      producto(const String& name, const String& brand, const String& code,
                              size_t quanty, double price)
      :name{name}, brand{brand}, code{code}, quanty{quanty}, price{price} { }
      ~producto() { }
      void mostrar() const override { }
      bool equals_to(const object &obj) const
      {
            const producto &p = static_cast<const producto &>(obj);
            return p.code == this->code;
      }
      const String &get_name() const
      {
            return name;
      }
      const String &get_marca() const
      {
            return brand;
      }
      const size_t get_cantidad() const
      {
            return quanty;
      }
      const double get_precio() const
      {
            return price;
      }
};

class item : public object
{
private:
      size_t quanty;
      String code;
      sistema_facturacion& sis;
public:
      item(size_t quanty, const String& code, sistema_facturacion& sis)
      :quanty{quanty}, code{code}, sis{sis} { }
      ~item() { }
      void mostrar() const override
      {
            const producto& p = sis.get_producto_por_codigo(code);
            cout << quanty << "\t" << code.c_str() << "\n";
            cout << p.get_name().c_str() << "\n";
            cout << p.get_marca().c_str() << "\n";
            cout << p.get_precio() << "\n";
            cout << quanty << "\n";
            cout << code.c_str() << "\n";

      }
};

class factura : public object
{
private:
      String name;
      String nit;
      array_list list_items;
      size_t descuento;
      sistema_facturacion& sis;
public:
      factura(const String& name, const String& nit, sistema_facturacion& sis)
      :name{name}, nit{nit}, descuento{0}, sis{sis} { }
      ~factura() { }
      void agregar_item(size_t quanty, const String& code)
      {
            item* new_item = new item{quanty, code, sis};
            list_items.add(new_item);
      }
      void agregar_descuento(size_t desc)
      {
            descuento += desc;
      }
      void mostrar() const
      {
            cout << "Cliente: \n";
            cout << "Name: " << name.c_str() << "\n";
            cout << "Nit: " << nit.c_str() << "\n";
            cout<<"ITEMS:\n\n";
            list_items.mostrar();
      }
};

class sistema_facturacion
{
private:
      array_list list_products;
      array_list list_fact;      
public:
      sistema_facturacion() { }
      ~sistema_facturacion() { }
      void agregar_producto(const String& name, const String& brand, const String& code,
                              size_t quanty, double price)
      {
            producto* prod = new producto{name, brand, code, quanty, price};
            list_products.add(prod);
      }
      factura& crear_factura(const String& name, const String& nit)
      {
            factura* fact = new factura{name, nit, *this};
            list_fact.add(fact);
            return *fact;
      }
      factura& crear_factura(const String& name)
      {
            factura* fact = new factura{name,"sin factura", *this};
            list_fact.add(fact);
            return *fact;
      }
      array_list obtener_facturas_de_hoy() const
      {
            array_list aux;
            for(size_t i = 0; i < list_fact.size(); i++)
            {
                  aux.add((object*)&(list_fact[i]));
            }
            return aux;
      }

      const producto& get_producto_por_codigo(const String& code) const
      {
            producto aux("", "", code , 0, 0);
            return static_cast<const producto&>(list_products.get_object(aux));
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
