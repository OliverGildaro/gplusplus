#include <iostream>
#include <string>

using namespace std;

template <class A, class B, class C>
struct X
{
      A a;
      B b;
      C c;
      void print() const
      {
            cout << a <<"\n";
            cout << b <<"\n";
            cout << c <<"\n";
      }
};

template<class P>

struct X<int, int, P>
{
      int a;
      int b;
      P c;

      void print()
      {
            cout << a+b << "\n";
            cout << c << "\n";
      }
};

template<>//especializacion total

struct X<string, string, string>
{
      string a,b,c;

      void show()
      {
            cout << a << b << c<<"\n";
      }
};


int main()
{
      X<int, string, double> x{10, "hola", 2.15};
      x.print();

      X<int, int, string> y{1,4,"hola"};
      y.print();

      X<int,int,int> z{4,5,6};
      z.print();

      X<string,string,string> a{"pet", "shop", "boys"};
      a.show();
}