#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;

//exception.... bad_alloc...vota una excepcion cuando no se puede crear un objeto con el new
//exception..... bad_cast/.... vota una excepcion cuando no se puede realizar el casteo
//out_of_rabge//// vota las excepciones en tiempo de ejecucion

//siempre que se herede de la clase stdexcept se debe sobreeescribir el metodo what
//mutable... puede cambiar variables const a no const
class ex : public exception
{
private:
    int error_code;
    char msg[100];
public:
    ex(int ec)
    :error_code{ec} 
    {
        strcpy(msg, "error: ");
        char aux[10];
        sprintf(aux, "%d", error_code);
        strcat(msg, aux);
    }
    ~ex() { }

    const char* what() const noexcept override//noexcept le dice al comiplador que este metodo no 
    //va a votar excepciones
    {
        return msg;
    }

};

int main()
{
    try{
        throw ex{58};
    }
    catch(const exception& e)
    {
        cerr << e.what();
    }
}