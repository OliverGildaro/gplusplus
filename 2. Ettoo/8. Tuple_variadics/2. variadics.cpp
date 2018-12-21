#include <iostream>
#include <string>
//VARIADIC TEMPLATES (c++11)
using namespace std;

//PARAMS = parameter pack

// template <typename T, typename U>
// auto sum(const T& a, const U& b)
// {
//       cout << "entra\n";
//       return a+b;
// }

// template <typename T, typename...PARAMS>//recibe un conjunto de parametros llamados PARAMS
// auto sum(const T& n, const PARAMS&...args)
// {
//       cout << "entraargs\n";
//       return n + sum(args...);//args... = pack expansion
// }

auto get_string(int p)
{
      return std::to_string(p);
}

auto get_string(const string& s)
{
      return s;
}

auto get_string(const char* s)
{
      return string{s};
}

template <typename T>
string join(const string& sep, const T& a)
{
      return get_string(a);
}

template <typename P, typename...A>
string join(const string& sep, const P& p, const A&...args)
{
      return get_string(p) + sep + join(sep, args...);
}

int main()
{
      // cout << sum(2,8) << "\n";
      // cout << sum(2.3545,8,5) << "\n";
      // cout << sum(2,8.45,45,67,3,2,45) << "\n";

      auto p = join(";",2,"hola", "world");
      cout << p << "\n";
}