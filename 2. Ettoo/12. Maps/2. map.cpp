#include <iostream>
#include <map>
//mapa ordenado
using namespace std;
struct id
{
  int n;
  string c;
};

bool operator<(const id& a, const id& b)
{
    return tie(a.n, a.c) < tie(b.n,b.c);
}

int main()
{
    map<id, string> pp;
    
    pp.insert(make_pair(id{23232, "CB"}, "Mauricio salazar"));
    pp[id{3454564, "PT"}] = "omar perez";
    pp[id{45677, "CH"}] = "Pamela Alvarez";
    
    for(auto& e : pp)
    {
        cout << e.first.n << " " << e.first.c << " " << e.second << "\n";
    }
    
    auto i2 = pp.find(id{45677, "CH"});
    if(i2 == pp.end())
        cout << "not find\n";
    else
        cout << i2->second << "\n";
}