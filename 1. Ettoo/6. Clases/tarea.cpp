#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
      size_t len;
      char* str;
public:
      String(const char* p_str)
      :len{strlen(p_str)}, str {(char*) malloc(len+1)}
      { 
            cout << "Const parametrizado\n";
            memcpy(str, p_str, len+1);
      }

      String()
      :String{""} 
      {
            cout << "Const default\n";
      }

      String(const String& src)
      :len{src.len}, str{(char*) malloc(src.len+1)}
      {
            cout << "Const copia\n";
            memcpy(str, src.str, len+1);
      }

      String& operator=(const String& src)
      {
            cout << "operator igual\n";
            if(this == &src)
                  return *this;
            this->~String();
            len = src.len;
            str = (char*) malloc(len+1);
            memcpy(str, src.str, len+1);
            return *this;
      }

      String operator+(const String& src)//aca llega el objeto de la derecha
      {
            cout << "operator suma\n";
            String aux;//llama al constructor default
            aux.len = len + src.len;//len es el tamanio del objeto de la izquierda
            aux.str = (char*) realloc(aux.str, aux.len);
            memcpy(aux.str, str, len);
            memcpy(aux.str + len, src.str, src.len+1);
            return aux;
      }

      String& operator+=(const String& src)
      {
            size_t nlen = len + src.len;
            str = (char*) realloc(str, nlen+1);
            memcpy(str + len, src.str, src.len+1);
            return *this;
      }

      bool operator==(const String& s) const
      {
            if(strcmp(str, s.str)==0)
                  return true;
            else
                  return false;
      }

      bool operator!=(const String& s) const
      {
            if(strcmp(str, s.str)!=0)
                  return true;
            else
                  return false;
      }

      // void find(const char* str)
      // {
      //       const char* 3;
      //       const char* orig = str;

      //       while(*str++ != )

      // }

      void trim()
      {
            // find(str);
            // cout << *str <<"\n";
            // str++;
      }

      ~String() 
      { 
            free(str);
      }

      const char* c_str()
      {
            return str;
      }

      
};

class Person
{
private:
      String first_name;
      String last_name;
      size_t id;
public:
      Person(const String& fn, const String& ln, size_t id)
      :first_name{fn}, last_name{ln}, id{id} { }

      Person(const Person& src)
      :first_name{src.first_name}, last_name{src.last_name}, id{src.id}
      {
            cout << " Constructor copia\n";
      }
      ~Person() { }

      void print()
      {
            cout << first_name.c_str() << " " << last_name.c_str() <<  " " << id << "\n";
      }
};

int main()
{
      String s;
      String s2{"hola"};
      String s3 = {"mundo"};
      String s4 = s2;//constructor copia
      s = s3;//asignacion

      cout << s4.c_str() << "\n";
      cout << s.c_str() << "\n";

      String hm = s4 + " " + s;//" " es un const char* pero es procesado como un objeto String y es destruido 
      //en esta linea de codigo.... busca un constructor que recibe un const char* y construye un objeto sobre el pucho
      cout << hm.c_str() << "\n";

      hm += "nativo";

      cout << hm.c_str() << "\n"; //no crea un nuevo objeto, se modifica el this*

      Person p1{"Elon", "Musk", 123445};     
      Person p2{"Ma", "Cums", 127655};     
      Person p3 = p1;
      p1 = Person{"Rick", "Grames", 454};   

      p1.print(); 
      p2.print();  
      p3.print();

      if(s2 == s3)
            cout << "Son iguales\n";
      else
            cout << "Son diferentes\n";

      if(s2 != s3)
            cout << "Son diferentes\n";
      else
            cout << "Son iguales\n";
      
      String s5 {"Roger       Waters    "};
      s5.trim();

      //cout << String("zanahoria".substring(1,3).c_str() << "\n";
}