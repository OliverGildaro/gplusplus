#include <iostream>

using namespace std;

struct Exception
{
    int err;
    void print() const//todos los metodos de las excepciones deberian ser const
    {
        cerr << "error doed:" << err << "\n";
    }
    ~Exception() {
        cout << "bye ex\n";
    }
};

void x()
{
    cout << "hola\n";
    // throw new Exception{125};
    throw Exception{125};
}

int main()
{
    try{
        x();
    }
    catch(const Exception& e)//debe ser referencia porque destruye el objeto dos veces
    {
        // e->print();
        // delete e;
        e.print();
    }
}