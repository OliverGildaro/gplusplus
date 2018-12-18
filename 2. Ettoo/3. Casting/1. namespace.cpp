#include <iostream>
#include <string>
//NAMESPACES
//*Una agrupacion logica de identificadores
//*sirven para evitar namecrashes
using namespace std;

namespace funcs
{
      void f()
      {
            cout << "hello\n";
      }

      void g()
      {
            cout <<"2018\n";
      }
}

namespace a
{
      namespace b
      {
            namespace c
            {
                  void d()
                  {
                        cout << "nested\n";
                  }
                  void e()
                  {
                        cout <<"eeee\n";
                  }
            }
      }
}

namespace x::y::z
{
      void w()
      {
            cout <<"yeah\n";
      }
}

void g()
{
      cout <<"2018\n";
}
using namespace funcs;

int main()
{
      funcs::f();
      funcs::g();
      ::g();

      a::b::c::d();
      a::b::c::e();
      x::y::z::w();
}