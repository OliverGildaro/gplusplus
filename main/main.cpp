//DRead diamond problem.... este problema se debe solucionar con herencia virtual
#include <iostream>
using namespace std;

class Object
{
public:
      virtual ~Object() { }
      virtual bool equals(const Object&) const = 0;
      virtual void show() const = 0;
};

class Icomparable : public virtual Object
{
public:
      virtual ~Icomparable() { }
      virtual bool compareTo(const Object&) const =0;
};

class Integer : public virtual Object, public virtual Icomparable
{
private:
      int n;
public:
      Integer(int n)
      :n{n} { }
      ~Integer() { }

      bool equals(const Object& obj) const
      {
            const Integer& i = dynamic_cast<const Integer&>(obj);
            return n == i.n;
      }
      bool compareTo(const Object& obj) const
      {
            const Integer& i = dynamic_cast<const Integer&>(obj);
            return n == i.n;
      }
      void show() const
      {
            cout << n << "\n";
      }
};

int main()
{
    Object* p1 = new Integer{10};//equals, show
    Icomparable* p2 = new Integer{45};//compare_to

    cout << p1->equals(*p2) << "\n";
    cout << p2->compareTo(*p1) << "\n";

    p1->show();
    p2->show();

    delete p1;
    delete p2;
}
//Agregacion
//*
