#include <iostream>

using namespace std;

struct A
{
    A() { }
    ~A()
    {
        cout << "bye" << "\n";
    }
};

void p()
{
    cout << "hello\n";
    throw 5;
}

int main()
{
    // A* a = nullptr;
    try{
        // auto a = new A();//en caso de que se haya muchos new el codigo se vuelve feo
        A a;//solucion trabajar con objetos en el stack
        p();
        // delete a;
    }
    catch(int n)
    {
        cerr << "error" << n << "\n";
        // if(a)
        // {
        //     delete a;
        //     cout << "objeto eliminado\n";
        // }
    }
}