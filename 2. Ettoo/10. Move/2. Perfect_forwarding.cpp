
#include <iostream>
//perfect forwarding
using namespace std;


int sum(int a, int b)
{
      return a+ b;
}

int inc(int& n)
{
      n++;
      return n;
}

template<typename PROC, typename... ARGS>
auto invoke(PROC p, ARGS&&... args)
{
//       return p(args...);
      return p(forward<ARGS>(args)...);//hace forward de cada elemento

}

// template<typename PROC, typename... ARGS>//revisar porque no funciona esto
// auto invoke(PROC p, const ARGS&... args)
// {
//       return p(forward<ARGS>(args)...);
// }

int main()
{
      auto r = invoke(sum, 4, 3);
      cout << r << "\n";

      int n = 8;

      invoke(inc, n);

      cout << n << "\n";
}