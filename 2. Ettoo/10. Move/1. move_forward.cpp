#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
using namespace std;


class A
{
private:
      string p;
public:
      A(const string& s)
      :p{s} { }//aca se llama al const copia de la clase string
      ~A() { }

      A(A&& src)//recibe un rvalue reference no constante a la fuente
      :p{move(src.p)}
      {

      }

      A(string&& s): p(move(s))
      {
            cout << "move\n";
      }
      string get() const
      {
            return p;
      }
      
};




vector<int> get_list()
{
      vector<int> z;

      
      for(size_t i = 0; i < 10000; i++)
      {
            z.push_back(i);
      }
      return z;
}

class Person
{
private:
      char* name;
public:
      Person(const char* n) 
      { 
            cout << "copy\n";
            size_t len = strlen(n);
            name = new char(len+1);
            memcpy(name, n, len+1);
      }
      ~Person() 
      { 
            delete[] name;
      }

      Person(const Person& p)
      {
            cout << "copy=\n";
            auto len = strlen(p.name);
            name = new char[len+1];
            memcpy(name, p.name, len+1);
      }

      Person& operator=(const Person& p)
      {
            if(this == &p)
                  return *this;

            delete[] name;
            auto len = strlen(p.name);
            name = new char[len+1];
            memcpy(name, p.name, len+1);

            return *this;
      }

      Person(Person&& src)
      :name{src.name}
      {
            cout << "move\n";
            src.name = nullptr;
      }

      void show()
      {
            cout << name << "\n";
      }
};


class Couple
{
private:
      Person a;
      Person b;
public:
      template<typename T1, typename T2>
      Couple(T1&& a, T2&& b)
      :a{forward<T1>(a)}, b{forward<T2>(b)} { }//perfect fordward

      ~Couple() { }

      // Couple(Person&& a, Person&& b)
      // :a{move(a)}, b{move(b)}
      // {
      //       cout << "move\n";
      // }

      void show()
      {
            a.show();
            b.show();
      }
};


class Fatty
{
private:
      char* p;
public:
      Fatty(char k) 
      { 
            p = new char[1000000];
            
            for(size_t i = 0; i < 1000000; i++)
            {
                  p[i] = k;
            }
            
      }

      Fatty(const Fatty& src)
      {
            p = new char[1'000'000];
            
            for(size_t i = 0; i < 1'000'000; i++)
            {
                  p[i] = src.p[i];
            }
      }

      Fatty& operator=(const Fatty& src)
      {
            delete[] p;

            p = new char[1'000'000];

            
            for(size_t i = 0; i < 1'000'000; i++)
            {
                  p[i] = src.p[i];
            }
            return *this;
      }

      Fatty(Fatty&& src)
      :p{src.p}
      {
            src.p = nullptr;
      }

      Fatty& operator=(Fatty&& src)
      {
            delete[] p;

            p = src.p;

            src.p = nullptr;

            return *this;
      }

      ~Fatty() 
      { 
            delete[] p;
      }
};

template <typename T>
void swp(T& a, T& b)
{
      T aux = move(a);
      a = move(b);
      b = move(aux);
}

int main()
{
      // A m{"hola"};//se crea un string temporal en este punto

      // string n = "2019";//en este caso esta bien poruqe no se crea un string temporal
      // A q{move(n)};//en este caso el comp no sabe si quiere hacer una movida, hace copia

      // cout << m.get() << "\n";
      // cout << q.get() << "\n";

      // vector<int> r;
      // r = get_list();//

      //***********************************
      // Person p{"juan perez"};
      // Person q = p;
      // p.show();
      // q.show();

      // Person r = move(p);
      // r.show();
      // p.show();

      //***********************************


      // Person a1 {"adan"};
      // Person a2 {"Eva"};

      // Couple a{a1, a2};
      // a.show();

      // puts("******************");

      // Couple b{Person{"alvaro"}, Person{"paola"}};

      // b.show();

      // puts("******************");


      // Couple c{Person{"carlos"}, a2};//hay que tener const para cada caso, no es mantenible....solucion =template
      // c.show();


      Fatty a{'x'};
      Fatty b{'y'};

      auto z0 = clock();
      
      
      for(size_t i = 0; i < 30001; i++)
      {
            swp(a, b);
      }
      auto z1 = clock();


      cout << (z1-z0) << "\n";
}     