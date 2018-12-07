#include <iostream>

using namespace std;

struct Animal
{
    virtual ~Animal(){}
    virtual void hablar() const = 0;
};

struct perro : public Animal
{
    void hablar() const
    {
        cout << "guauu\n";
    }
};

struct wrapper
{
    Animal* a;
    ~wrapper()
    {
        delete a;
    }
};

Animal* get_animal()
{
    return new perro{};
}

void a()
{
    cout << "hola\n";
    throw 3;
}

int main()
{
  //otro caso
    try{
        // Animal* a = get_animal();//solucion, crear wrapper
        wrapper w{get_animal()};//unique_ptr
        w.a->hablar();
        // a->hablar();
        a();
        // delete a;
    }
    catch(int n)
    {
        cerr << "error" << n << "\n";
    }
}