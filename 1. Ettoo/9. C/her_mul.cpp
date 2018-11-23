//HERENCIA MULTIPLE
//*Las clases pueden basarce en mas de una clase
//*Ninguna clase es mas importante que otra
//*ningun limite en el numero de clases base
#include <iostream>

using namespace std;

class Animal
{
private:
    
public:
    Animal() { }
    ~Animal() { }

    void comer()
    {
        cout << "como\n";
    }
};

class Vehicle
{
private:
    
public:
    Vehicle() { }
    ~Vehicle() { }

    void acelerar()
    {
        cout << "voy mas rapido\n";
    }
};

class Volador
{
private:
    
public:
    Volador() { }
    ~Volador() { }

    void volar()
    {
        cout << "vuelo alto\n";
    }
};

class Murcielago : public Animal, public Volador
{
private:
    
public:
    Murcielago() { }
    ~Murcielago() { }

    void chuparSangre()
    {
        cout <<"Yumiiieee\n";
    }
};


class Avion : public Volador, public Vehicle
{
private:
    
public:
    Avion() { }
    ~Avion() { }

};

int main()
{
    Avion a;
    a.volar();
    a.acelerar();

    Murcielago m;
    m.volar();
    m.comer();
    m.chuparSangre();
}