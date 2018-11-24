//Iterfaz Greeter and static method
#include <iostream>

using namespace std;

enum class language
{
      ESPANISH = 1,
      ENGLISH =2     
};

class Greeter
{
public:
      virtual ~Greeter() { }
      virtual const char* hi() const = 0;
      virtual const char* bye() const = 0;
};

class SpanishGreeter : public Greeter
{
public:
      SpanishGreeter() { }
      ~SpanishGreeter() { }

      const char* hi() const
      {
            return "Hola amigo";
      }
      const char* bye() const
      {
            return "adios amigo";
      }
};

class EnglishGreeter : public Greeter
{
public:
      EnglishGreeter() { }
      ~EnglishGreeter() { }

      const char* hi() const
      {
            return "hello my friend";
      }
      const char* bye() const
      {
            return "Bye my friend";
      }
};

class GreeterFactory
{
public:
      GreeterFactory() { }
      ~GreeterFactory() { }

      static Greeter* create(const language& enum_obj)
      {
            switch (enum_obj)
            {
                  case language::ESPANISH:
                        return new SpanishGreeter;
            
                  case language::ENGLISH:
                        return new EnglishGreeter;
            }
            return nullptr;
      }
};

int main()
{
    int n;
    cout << "Ingre 1 espaniol, 2. ingles: ";
    cin >> n;

    language lng = (language)n;
    Greeter* g = GreeterFactory::create(lng);//se puede llamar sin un objeto porque el metodo es estatico

    cout << g->hi() << "\n";
    cout << g->bye() << "\n";

    delete g;
}
//en herencia si algo es struct, todo debe ser struct
//en herencia  si algo es class, todo debe ser class
//examen 3 de diciembre