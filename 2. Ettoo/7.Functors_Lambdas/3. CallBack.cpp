#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
//CALLBACKS

//tb se puede tener un alias
typedef void(*PROGRESSFPtr)(int, int);

void print_progress(int p, int c)
{
      cout << p << "de" << c << "elementos" << "\n";
}

void f(void(*PP)(int pos, int cant))//reeemplazar aca el alias
{
      for(size_t i = 0; i < 1'000'000'000; i++)
      {
            if(i%20'000'000)
                  PP(i, 20'000'000);
      }
}

int main()
{
      f(print_progress);
}