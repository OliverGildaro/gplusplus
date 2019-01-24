#include <iostream>
#include <map>
#include <variant>
using namespace std;


struct avion
{
    void mover()
    {
        cout << "esta volando\n";
    }
};


struct automovil
{
    void mover()
    {
        cout << "esta moviendose\n";
    }
};


struct barco
{
    void mover()
    {
        cout << "esta navegando\n";
    }
};
    
using vehicle = variant<avion, automovil, barco>;

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