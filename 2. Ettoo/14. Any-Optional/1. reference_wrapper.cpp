#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct nombre_apellido
{
    string nombre;
    string apellido;
};

template<typename T, typename PRED>
auto get_if(const T& c, PRED p)
{
    // vector<typename T::value_type> r;//T es epecificado como template, usamos typename para deducir el tipo de value_type
    vector<reference_wrapper<const typename T::value_type>> r;//con esto hacemos un vector de referencias,,,, value_type es de typo nombre_apellido
    for(auto& e : c)
    {
        if(p(e))
            r.push_back(ref(e));//ref es para asegurarnos que cree una referencia
    }
    return r;
}

int main()
{
    vector<nombre_apellido> ns;
    ns.push_back({"Juan", "perez"});
    ns.push_back({"Jorge", "Lopez"});
    ns.push_back({"Romulo", "Rojas"});
    ns.push_back({"Alavaro", "Perez"});

    auto f = get_if(ns, [](auto& n){
        return n.apellido == "Perez";
    });

    for(auto& e : f)
    {
        cout << e.get().nombre  << " " << e.get().apellido << "\n";
    }//esta trucho por que el vector es una copia de cada objeto, para eso includir functional
}