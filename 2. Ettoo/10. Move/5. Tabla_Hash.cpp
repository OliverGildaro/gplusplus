#include <iostream>
#include <unordered_set>

//UNORDERED
//*tabla hash es un array gigante desordenado...desperdicia mucho espacio de memoria
//insert (O(1) + RH)... rehash
//Find (O(1)
//erase (O(1)
using namespace std;
//examen 21
int main()
{
     unordered_set<string> ms;

     ms.insert("january");
     ms.insert("febreary");
     ms.insert("march");
     ms.insert("april");
     ms.erase("april");

     for(auto i : ms)
     {
           cout << i <<"\n";
     }

     unordered_set<string>::iterator it = ms.find("january");

     if(it != ms.end())
            cout << "finded" << *it <<"\n";
      else
            cout << "no finded\n";
}
