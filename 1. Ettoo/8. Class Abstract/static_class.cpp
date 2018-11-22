#include <iostream>

using namespace std;

enum class language
{
    Spanish = 1,
    English = 2
};

struct Greeter//ABC  Abstract base class
{
    virtual ~Greeter() { }
    virtual const char* hi() const = 0;
    virtual const char* bye() const = 0;
};

struct spanishGreeter : public Greeter
{
    const char* hi() const override
    {
        return "buenso dias";
    }
    const char* bye() const override
    {
        return "hasta luego";
    }
};

struct englishGreeter : public Greeter
{
    const char* hi() const override
    {
        return "Good mornig";
    }
    const char* bye() const override
    {
        return "Bye";
    }
};

struct GreeterFatory
{
    static Greeter* create(language x)//todo lo estatico de la clase se puede acceder sin crear 
    //objetos de la clase.... lo static es de la clase, no de los objetos
    {
        switch(x)
        {
            case language::Spanish:
                return new spanishGreeter();
            case language::English:
                return new englishGreeter();
        }
    }
};

int main()
{
    int n;
    cout << "Ingre 1 espaniol, 2. ingles: ";
    cin >> n;

    language lng = (language)n;
    Greeter* g = GreeterFatory::create(lng);//se puede llamar sin un objeto porque el metodo es estatico

    cout << g->hi() << "\n";
    cout << g->bye() << "\n";

    delete g;
}
//en herencia si si algo es struct, todo debe ser struct
//en herencia si si algo es class, todo debe ser class
//examen 3 de diciembre