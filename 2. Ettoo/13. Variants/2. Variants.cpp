#include <iostream>
#include <map>
#include <memory>
#include <variant>
//VARIANTS
using namespace std;

struct automovil
{
    void mover()
    {
        cout << "se esta moviendo\n";
    }
};

struct avion
{
    void mover()
    {
        cout << "esta volando\n";
    }
};

struct barco
{
    void mover()
    {
        cout << "remar\n";
    }
};

using vehicle = variant<automovil, avion, barco>;
//no agrega objetos en tiempo de ejecucion
int main()
{
    map<string, vehicle> vs;

    vs["1224abc"] = avion{};
    vs["1224xcv"] = automovil{};
    vs["1224rty"] = barco{};

    get<avion>(vs["1224abc"]).mover();
    //get<avion>(vs["1224rty"]).mover(); es un barco no avion

    for(auto& e : vs)
    {
        cout << e.first << "\n";
        visit([](auto& p){
            p.mover();
        }, e.second);
    }
}