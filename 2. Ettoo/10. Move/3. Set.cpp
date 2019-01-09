#include <iostream>
#include <set>
#include <tuple>

//SETS
//*set... arbol binario de busqueda balanceado
//*unorderedset.... implementado como una tabla HASH
//*multiset para tener elementos repetidos
using namespace std;
//insert O(log2N)... tiene buen rendimiento
//erase O(log2N)
//find O(log2N)


struct mypair
{
      int x, y;
};


struct mypair_comparator
{
      bool operator()(const mypair& a, const mypair& b) const
      {
            return tie(a.x, a.y) < tie(b.x, b.y);
      }
};

ostream& operator<<(ostream& os, const mypair& e)
{
      os << "("<<e.x << e.y <<")";
      return os;
}

bool c2(const mypair& a, const mypair& b)
{
      return tie(a.y, a.x) < tie(b.y, b.x);
}

int main()
{
      using ctype = bool (*)(const mypair&, const mypair&);
      set<string> s;

      s.insert("java");
      s.insert("c++");
      s.insert("rust");
      s.insert("swift");
      s.insert("python");
      s.insert("c#");

      for(auto i = s.begin(); i!=s.end(); ++i)
      {
            cout << *i << "\n";
            s.erase("swift");
      }

      auto it = s.find("c++");
      if(it != s.end())
      {
            cout << "found and killed" << *it <<"\n";
            s.erase(it);
      }
      //el mejorado
      // for(auto i : s)
      // {
      //       cout << i <<"\n";
      // }

      set<mypair, mypair_comparator> mps;
      mps.insert(mypair{6,5});
      mps.insert(mypair{8,2});
      mps.insert(mypair{4,9});
      mps.insert(mypair{6,6});

      for(auto i : mps)
      {
            cout << i <<"\n";
      }

    //   set<mypair, ctype> mps{c2};
    //   mps.insert(mypair{6,5});
    //   mps.insert(mypair{8,2});
    //   mps.insert(mypair{4,9});
    //   mps.insert(mypair{6,6});

    //   for(auto i : mps)
    //   {
    //         cout << i <<"\n";
    //   }
}
