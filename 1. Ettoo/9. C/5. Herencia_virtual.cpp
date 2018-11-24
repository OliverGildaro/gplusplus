
#include <iostream>
using namespace std;

struct BF
{
    int n;
    BF(int n)
    :n{n} {}
};

struct A : virtual BF
{
    A():BF{100} {}
};


struct B: virtual BF
{
    B():BF(888) { }//si este constructor recibiria parametros recien entonces recibiria la llamada 
};


struct C: A, B
{
    C()//se debe especificar la llamada al constructor de la clase base
    //no sabe si llamar al constructor de B o A
    :BF{456} {}
};

int main()
{
    C c;
    cout << c.n << "\n";
}