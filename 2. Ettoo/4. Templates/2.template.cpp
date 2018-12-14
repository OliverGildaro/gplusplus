#include <iostream>

using namespace std;

template <int N, char K>//solo tipos enteros y boleanos
//valores conocidos en compile time
void print()
{
      
      for(size_t i = 0; i < N; i++)
      {
            cout << K <<"\n";
      }
      cout << "\n";
      
}

int main()
{
      print<4, '*'>();
      print<6, '#'>();

      constexpr int n = 2;//esta variable debe ser conocida en tiempo de compilacion
      print<n, 'A'>();

}