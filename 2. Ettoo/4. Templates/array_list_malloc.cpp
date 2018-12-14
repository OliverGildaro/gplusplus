#include <iostream>

using namespace std;

template <class T>
class ArrayList
{
private:
      T* items;
      size_t n;
public:
      ArrayList()
      :items{static_cast<T*>(malloc(0))}, n{0} { }
      //malloc y realloc solo funciona con POD
      //*int, char, double
      ~ArrayList() 
      { 
            free(items);
      }

      ArrayList<T>& add(const T& x)
      {
            items = static_cast<T*>(realloc(items, (n+1)*sizeof(T)));
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
};

struct PoormanInt
{
      int* n;
      PoormanInt(int p)
      :n{new int{p}} { }
      ~PoormanInt()
      {
            delete n;
      }
};

int main()
{
      ArrayList<int> p;//al instanciar objectos de clases, siempre debes pasarle el tipo

      p.add(5).add(6).add(15).add(40).show();

      // ArrayList<double> d;
      // d.add(4.44).add(2.34).add(4.67).show();

      // ArrayList<string> r;

      // r.add("hello").add("world").add("depeche").add("mode").show();

      // ArrayList<PoormanInt> z;
      
      // for(size_t i = 0; i < 100000000000; i++)
      // {
      //       z.add(i*17);
      // }
}