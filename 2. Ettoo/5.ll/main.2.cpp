#include <iostream>
#include <string>
#include <cstdio>
//TEMPLATE ESPECIALIZATION PARCIAL
using namespace std;

template <typename T>
class container
{
private:
      T value;
public:
      container(const T& value)
      :value{value} { }
      ~container() { }

      const T& get() const 
      {
            return value;
      }

     
};

template<>
class container<FILE*>
{
private:
      FILE* f;
public:
      container(const char* fn, const char* om)
      :f{fopen(fn,om)} { }
      ~container() 
      { 
            fclose(f);
      }

      void puts(const char* s)
      {
            fputs(s, f);
      }

      // const FILE& get() const 
      // {
      //       return value;
      // }
};

template<typename T>

class container<T*>
{
private:
      T* p;
public:
      container(T* p)
      :p{p} { }
      ~container() 
      { 
            cout << "bye container\n";
            delete p;
      }

      const T& get() const
      {
            return *p;
      }
      const T* operator->() const
      {
            return p;
      }
};



struct Z
{
      ~Z()
      {
            cout << "bye\n";
      }

      void salute() const
      {
            cout <<"laudanus t vernis\n";
      }
       //hacemos un smartpointer con esto
      
};


int main()
{
      // container<int> p{5};
      // container<int> q{7};

      // cout << p.get() + q.get() << "\n";

      // container<string> s{"hello"};
      // cout << s.get() << "\n";

      // container<FILE*> f{fopen("a.txt", "w")};//si no puede abrir devuelve un puntero a null
      //en caso de que la ruta no exista o el archivo sea restringido
      //w es escribir
      //r es leer
      //wb es escritura binaria
      //wt es escritura de texto
      //rb lectura binaria
      //rt lectura de texto
      // fputs("hello", f.get());
      // fclose(f.get());

      //especializacion de clase container que reciba un file, mas eficiente

      container<FILE*> g{"b.txt", "w"};
      g.puts("hello fryday");

      container<Z*> y {new Z{}};
      y->salute();
}

//nm -C main | grep factorial... muestra las funciones que genera
//main.cpp -o main -O2... para vender mi programa