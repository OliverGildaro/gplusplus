#include <iostream>
#include <map>
#include <memory>
using namespace std;

class vehiculo
{
private:
    
public:
    vehiculo() { }
    virtual ~vehiculo() { }
    virtual void mover() = 0;
};

class Auto : public vehiculo
{
private:
    /* data */
public:
    Auto(/* args */) { }
    ~Auto() { }

    void mover() override
    {
        cout << "se esta moviendo\n";
    }
};

int main()
{
    map<string, unique_ptr<vehiculo>> vs;

    vs["3453454"] = make_unique<Auto>();
    vs["454656"] = make_unique<Auto>();


    for(auto& e : vs)
    {
        cout << e.first << " ";
        e.second->mover();
    }

    //existe doble indireccion no es muy eficiente
    //y hace el mapeo en vtable
}