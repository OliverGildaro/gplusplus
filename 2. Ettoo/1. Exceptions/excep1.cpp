#include <iostream>

using namespace std;

void b()
{
    cout <<"b\n";
    // throw true;

    int* c = nullptr;
    *c = 40;//en este punto el programa muere

    try{
        int d = 14, b = 0;
        int e = d/b;//el programa muere, no captura excepciones
        //es un error del programador

    }
    catch(...){
        cerr << "sdsdsd\n";
    }

}

void c()
{
    // throw "hello";
    throw 1UL;
}

void a()
{
    // b();
    c();
    cout << "jejej\n";
}

int main()
{
    try{
        a();
    }
    //para recuperar el valor
    catch(const char* s)
    {
        cerr << s << "\n";
    }
    //puedo aumentar cualquier cantidad de manejadores de escepciones
    catch(size_t n)//el tipo debe coincidir con el tipo que maneja las excepciones
    {
        cerr << n << "\n";
    }
    catch(...)//la idea es manejar esta excepcion con un mensaje
    {
        cerr << "dsasds\n";
    }
}