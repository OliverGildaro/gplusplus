#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;

void z()
{
    throw 655;
}

void y() noexcept(false)//estpy avisando que este metodo no vota excepciones
//se puede variar entre true y false
{
    cout << "hello" << "\n";
    z();
}

int main()
{
    try{
        y();
    }
    catch(int n)
    {
        cerr << n <<"\n";
    }
}