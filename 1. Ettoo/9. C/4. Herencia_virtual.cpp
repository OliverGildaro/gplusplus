//DRead diamond problem
//este problema se debe solucionar con herencia virtual
#include <iostream>
using namespace std;

class Object
{
public:
    Object() { }
    virtual ~Object() { }
    virtual bool equals(const Object& obj) const = 0;
    virtual void show() const =0;
};

class Icomparable : public virtual Object //en herencia virtual se debe marcar como virtual 
{
public:
    Icomparable() { }
    virtual ~Icomparable() { }
    //aca ya estan declarados los metodos abstractos del padre
    virtual int compareTo(const Object& obj) const = 0;
};

class Integer : public virtual Object, public virtual Icomparable
//se debe utilizar herencia virtual debido a que existe ambiguedad en los metodos que va a sobreescribir
//las clase integer, no sabe si sobre escribir en object o icomparable
//de esta forma se sobreescribe solo de la clase padre "object"
{
private:
    int n;
public:
    Integer(int n)
    :n{n} { }

    bool equals(const Object& obj) const override
    {
        //la herencia virtual obliga a castear con dynamic_cast
        const Integer& i = dynamic_cast<const Integer&>(obj);
        return n == i.n;
    }

    void show() const override
    {
        cout << n <<" \n";
    }

    int compareTo(const Object& obj) const
    {
        const Integer& i = dynamic_cast<const Integer&>(obj);
        return n-i.n;
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
