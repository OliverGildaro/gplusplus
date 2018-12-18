#include <iostream>
#include <string>
//CASTING::OPERATORS
using namespace std;
#include <typeinfo>

struct A { virtual ~A(){ } };

struct B : A
{
      void m() const {cout << "hello\n";}
};

//static_cast es un casteo en tiempo de compilacion, el comiplador verifica si se puede realizar el casteo

void invoke(long long a)
{
      B* b = reinterpret_cast<B*>(a);//castea de punteros a tipos, de tipos a punteros
      //cuando hay que operar con lenguajes que no soportan punteros, hay que realizar este casteo
      //ejemplo: c++ se comunica con java
      b->m();
}

struct X { virtual ~X() { } };

struct Y : X
{
      int* n;
      Y(int p)
      :n{new int{p}} { }

      ~Y() { cout << "bye\n"; }

      void show() const
      {
            cout << *n << "\n";
      }
};

void print(const X& x)
{
      try
      {
            auto& y = dynamic_cast<const Y&>(x);
            y.show();
      }
      catch(const bad_cast& e)//si no puede hacer el casteo con & vota una excepcion
      {
            cout << "is not\n";
      }
}

int main()
{
      A* a = new B{};
      ((B*)a)->m();
      const B* ca = (const B*)a;
      auto nca = (B*)a;
      nca->m();

      puts("***********");//es mejor usar estos casteos

      // auto p = static_cast<int>(12.45);
      // A* af = new B();
      // static_cast<B*>(af)->m();
      // const B* cao = static_cast<B*>(af);//de no cosnt se castea a const de forma directa
      // static_cast<B*>->m();//para quitarle el const se debe usar const_cast
      // const_cast<B*>(cao)->m();
      // invoke((long long)cao);
      ////

      // X* x = new X{};//esto crashea
      // X* x = new Y{213};

      // static_cast<Y*>(x)->show();
      // auto y = dynamic_cast<Y*>(x);//verifica que x sea una instancia de Y
      //si es el caso, hace el casteo sino devuelve null
      //debe tener al menos un destructor virtual
      // if(y)
      //       y->show();

      // print(*x);
      
      // delete x;
}