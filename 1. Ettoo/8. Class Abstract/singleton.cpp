#include <iostream>
//singleton
//contiene una instancia de una clase, que puede ser accedida desde cualquier lugar
//y no va a cambiar durante todo el programa
//cualquier llamada a ese clase va a devolver la misma instancia
using namespace std;


class Singleton
{
private:
    static Singleton* p;
    Singleton(/* args */) 
    { 
        cout << "create instance\n";
    }//constructor es privado
public:
    ~Singleton() { }
    void hi() const
    {
        cout << "hello\n";
    }
    static Singleton* instance()
    {
        if(p==nullptr)
            p = new Singleton();
        return p;
    }
};

Singleton* Singleton::p =nullptr;//la manera de inicializar atributos estaticos

int main()
{
    Singleton::instance()->hi();
}