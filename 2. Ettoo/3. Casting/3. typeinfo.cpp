//RTLL
// (run time type information)
//type_id es una palabra recervada que devuelve una instancia del tipo type_info

#include <iostream>
#include <typeinfo>

using namespace std;

struct FundacionJala
{
      
};

int main()
{
      int p=8, q=9;
      if(typeid(p) == typeid(q))//no trabaja con herencia
            cout << "hello\n";

      double d = 12.388;

      if(typeid(d) == typeid(double))
            cout <<"es double\n";

      auto c = new FundacionJala{};
      // auto ti = typeid(p);//no soporta una copia
      const type_info& ti = typeid(c);//no soporta una copia

      cout <<  ti.name() << "\n";
      cout << typeid(*c).name() << "\n";

      const char* a ="adsas";

      cout << typeid(a).name() <<"\n";
}