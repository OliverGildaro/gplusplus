#include <iostream>
#include <cstring>
using namespace std;

//SSO small string optimization


class String
{
private:
      size_t len;
      char* str;
public:
      String(const char* s)//constructor parametrizado
      :len{strlen(s)}
      {
            cout << "Constructor parametrizado\n";
            str = (char*)malloc(len+1);
            memcpy(str, s, len+1);
      }

      String()//default constructor
      :String("")
      {
            cout << "default constructor\n";
      }

      String(const String& s)//constructor copia
      :len{s.len}, str{(char*)malloc(s.len+1)}
      {
            cout << "Constructor copia\n";
            memcpy(str, s.str, len+1);
      }

      String& operator=(const String& s)//operator= overload
      {
            cout << "Operator equal\n";
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

      ~String() 
      { 
            free(str);
      }
      
      const char* c_str() const
      {
            return str;
      }
};


class Person
{
private:
      String first_name;
      String last_name;
      int id;
public:
      Person(const String& fn, const String& ln, int i)
      :first_name{fn}, last_name{ln}, id{i}//llama a los constructores de first_name y last_name
      { 
            first_name.c_str();
      }
      ~Person() { }

      //implementar
      bool operator==(const String& s) const;
      bool operator!=(const String& s) const;
      void trim();
      int index_of(const String& s) const;
      String substring(size_t init, size_t len) const;
      String substring(size_t init) const;

      // void print() const
      // {
      //       cout << first_name.c_str() << " " << last_name.c_str() << " " << id <<"\n";
      // }

      void print() const
      {
            cout << first_name.c_str() << " " << last_name.c_str() << " " << id <<"\n";
      }
};

int main()
{
      // String s;
      // String s2{"hola"};
      // String s3 = {"mundo"};
      // String s4 = s2;//constructor copia
      // s = s3;//asignacion

      // cout << s4.c_str() << "\n";
      // cout << s.c_str() << "\n";

      // auto hm = s4 + " " + "watafack " + s2  + " " + s;//" " es un const char* pero es procesado como un objeto String y es destruido 
      //en esta linea de codigo.... busca un constructor que recibe un const char* y construye un objeto sobre el pucho
      // cout << hm.c_str() << "\n";

      // hm += "nativo";

      // cout << hm.c_str() << "\n"; //no crea un nuevo objeto, se modifica el this*

      // Person p1{"Elon", "Musk", 123445};     
      // Person p2{"Ma", "Cums", 127655};     
      // Person p3 = p1;
      // p1 = Person{"Rick", "Grames", 454};   

      // p1.print(); 
      // p2.print();  
      // p3.print(); 

      //cout << String("zanahoria".substring(1,3).c_str() << "\n";
}
