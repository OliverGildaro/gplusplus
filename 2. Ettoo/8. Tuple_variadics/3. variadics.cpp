#include <iostream>
#include <string>
//VARIADIC TEMPLATES (c++11)
using namespace std;

int sum(int a, int b)
{
      return a+b;
}

template <typename PROC, typename...ARGS>
auto invoke(PROC p, const ARGS&...args)
{
      cout << "invoke..\n";
      return p(args...);
}



int main()
{
      cout << invoke(std::to_string, 15) << "\n";
      auto z = invoke(sum, 6, 8);
}