#include <iostream>
#include <cstring>
using namespace std;


struct main
{
      /* data */
};


int main()
{
      int p[5];//el 5 es conocido en tiempo de compilacion
      int r =5;
      int* q = new int[r];// r es conocido en tiempo de ejecucion

      q[0] = 4;
      q[1] = 4;
      q[2] = 4;
      q[3] = 4;
      q[4] = 4;

      
      for(size_t i = 0; i < r; i++)
      {
            cout << q[i] << "\n"; 
      }
      delete[] q;
}