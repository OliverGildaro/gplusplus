#include <iostream>
#include <string>
//VARIADIC TEMPLATES (c++11)
using namespace std;
//CREATE instances
struct A
{
      int x;
      int y;
};

class P
{
private:
      string p;
public:
      P(const string& s)
      :p{s} { }
      ~P() { }

      void show()
      {
            cout << p << "\n";
      }
};

template <typename T, typename...ARGS>//el primer argumento es el tipo de instancia que se desea crear, el segundo es un conjunto de argumentos
T create_instance(const ARGS&...args)
{
      cout << "creating instance\n";
      return T{args...};
}

int main()
{
      auto a = create_instance<A>(10, 18);
      cout << a.x + a.y << "\n";

      auto b = create_instance<P>("hola");
      b.show();
}