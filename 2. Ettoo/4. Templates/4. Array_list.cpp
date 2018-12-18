#include <iostream>

using namespace std;

template <class T>
class ArrayList
{
private:
      T* items;
      size_t n;
      size_t cap;
public:
      ArrayList()
      :items{new T[4]}, n{0}, cap{4} { }
      ~ArrayList() 
      { 
            delete[] items;
            //llama a los desctructores de los objetos que estan dentro de cada posicion y
            //luego recien destruye el array
      }

      ArrayList<T>& add(const T& x)
      {
            resize();
            items[n++] = x;
            return *this;
      }

      void show() const
      {
            for(size_t i = 0; i < n; i++)
            {
                  cout << items[i] << "\n";
            }
      }
private:
      void resize()
      {
            if(n < cap)
                  return;
            auto ncap = cap*2;
            auto nitems = new T[ncap];
            
            for(size_t i = 0; i < n; i++)
            {
                  nitems[i] = items[i];
            }
            delete[] items;
            items = nitems;
            cap = ncap;            
      }
};

struct PoormanInt
{
      int* n;
      PoormanInt(int p)
      :n{new int{p}} { }

      PoormanInt()
      :n{nullptr} { }

      ~PoormanInt()
      {
            delete n;
      }

      void operator=(const PoormanInt& src)
      {
            delete[] n;
            n = new int{*(src.n)};
      }
};


int main()
{
      ArrayList<int> p;//al instanciar objectos de clases, siempre debes pasarle el tipo
      p.add(5).add(6).add(15).add(40).show();

      ArrayList<double> d;
      d.add(4.44).add(2.34).add(4.67).show();

      ArrayList<string> r;

      r.add("hello").add("world").add("depeche").add("mode").show();

      ArrayList<PoormanInt> z;
      
      for(size_t i = 0; i < 100; i++)
      {
            z.add(i*17);
      }
}