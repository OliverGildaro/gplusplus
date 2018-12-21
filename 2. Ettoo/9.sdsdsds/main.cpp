//CONTAINERS
//*Array_list, linked_list, colas, stack, mapas
#include <iostream>
#include <array>//c++11
#include <list>//listas enlazadas... muy ineficientes
#include <vector>
#include <map>
#include <vector>

using namespace std;

template <typename T>
void print(const T& x)
{
      for(auto i : x)
      {
            cout << i <<"\n";
      }
}

template <typename T, typename PRED>
void erase_items(list<T>& e, PRED p)
{
      for(auto i = e.begin(); i!=e.end(); /*nothing*/)
      {
            if(p(*i))
                  i = e.erase(i);//devuelve el siguiente iterador
            else
                  i++;
      }
}

struct X
{
      ~X() 
      { 
            cout << "bye\n";
      }
};


int main()
{
      //ARRAY, creado en el stack
      array<int, 6> x;// el uso de estos arrays es muy limitado, el tamanio debe ser conocido en time compile
      x[0] = 8;
      x[1] = 3;
      x[2] = 7;
      x[3] = 4;
      x[4] = 6;
      x[5] = 7;

      print(x);

      //LISTA
      list<string> dias = {"martes", "miercoles", "jueves", "viernes", "sabado"};
      dias.push_back("domingo");
      dias.push_front("lunes");

      print(dias);
      cout << dias.size() << "\n";

      erase_items(dias, [] (auto& x){
            return x[0] == 'm';
      });

      print(dias);

      //VECTOR, almacenado en el heap
      vector<int> n = {4,5,7,8};
      n.push_back(4);
      n.push_back(34);
      cout << n[5] << "\n";
      cout << n.at(2) << "\n";

      vector<X> x1 = {X{}, X{}, X{}};//hace tres copias

      puts("**********");
      vector<X*> x2 = {new X{}, new X{}, new X{}};//para polimorfismo, usar smart pointers
      for(auto i : x2)
      {
            delete i;
      }
}