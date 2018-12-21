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

template <typename T, typename...A>
T create_instance(const A&...args)
{
      cout << "creating instance\n";
      return T{args...};
}

int main()
{
      auto x = create_instance<A>(10, 18);
      auto y = create_instance<P>("hola");

      cout << x.x + x.y << "\n";

      y.show();
}