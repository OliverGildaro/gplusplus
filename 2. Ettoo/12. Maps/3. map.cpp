#include <iostream>
#include <unordered_map>
//mapa no ordenado
using namespace std;

struct key
{
    int id1;
    int id2;
};

struct key_hash
{
    size_t operator()(const key& e) const
    {
        return e.id1*31 + e.id2;
    }
};

struct key_eq
{
    bool operator()(const key& a, const key& b) const
    {
        return a.id1 == b.id1 && a.id2 == b.id2;
    }
};

struct ph
{
    size_t operator()(int* e) const
    {
        return *e;
    }
};

struct pe
{
        bool operator()(int* a, int* b) const
        {
            return *a == *b;
        }
};

int main()
{
    unordered_map<int, string> ns;
    
    ns[0] = "cero";
    ns[10] = "diez";
    ns[20] = "veinte";
    ns[30] = "treinta";
    ns[40] = "cuarenta";
    
    for(auto& e : ns)
        cout << e.first << "" << e.second << "\n";
        
    //se complica cuando el tipo de dato no es un tipo conocido
    
    unordered_map<key, string, key_hash, key_eq> s;
    s[key{10, 15}] = "veinticinco";
    s[key{2, 8}] = "diez";
    s[key{4, 7}] = "once";
    s[key{1, 3}] = "cuatro";
    
    for(auto& e : s)
        cout << e.first.id1 << " " << e.first.id2  << " " << e.second << "\n";
        
    auto it = s.find(key{2, 8});
    
    if(it == s.end())
        cout << "not found\n";
    else
        cout << it->second << "\n";
        
    unordered_map<int*, string, ph, pe> p;
    
    p[new int{10}] = "diez";
    p[new int{11}] = "once";
    p[new int{14}] = "catorce";
    p[new int{0}] = "cero";
    
    int pivot = 14;
    
    auto i3 = p.find(&pivot);
    cout << i3->second << "\n";
}