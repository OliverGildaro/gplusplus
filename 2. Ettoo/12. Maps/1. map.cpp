#include <iostream>
#include <map>
//MAPS
//*elementos estan almacenados como clave y valor
//*No hay claves repetidas
//*map->arbol binario de busqueda
//*unordered_map->tabla hash
using namespace std;
//insert->O(log2N)
//delete->O(log2N)
//find->O(log2N)
int main()
{
    map<string, int> dpm;
    dpm.insert(pair<string, int>{"enero", 24});
    dpm.insert(make_pair("febrero", 28));
    dpm["marzo"] = 35;//busca la el valor que tenga esa clave, si no lo encuentra lo crea
    dpm["abril"] = 45;//no es bueno para buscar
    
    for(auto& e:dpm)//e es un para
        cout << e.first << ";" << e.second << "\n";
    
    dpm.insert(make_pair("febrero", 31));//lo ignora
    dpm["febrero"] = 31;//aca si se reemplaza el valor
    
    for(auto& e:dpm)//e es un para
        cout << e.first << ";" << e.second << "\n";
    
    cout << dpm["septiembre"] << "\n";//peligroso porque si no lo encuentra lo crea
    
    auto it = dpm.find("abril");
    
    if(it == dpm.end())
        cout <<"no found\n";
    else
        cout << it->second <<"\n";
}