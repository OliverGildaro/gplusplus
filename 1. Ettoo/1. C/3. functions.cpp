#include <iostream>

using namespace std;

void print_as_text(unsigned int n);

bool is_even(int n)
{
      if(n%2 == 0)
            return true;
      return false;
}

void print_day(int n)
{
      switch(n)
      {
            default: cout <<"empty\n";
            case 0: cout <<"Domingo\n"; break;
            case 1: cout <<"Lunes\n"; break;
            case 2: cout <<"Martes\n"; break;
      }
}

void count_down(int n)
{
      while(n >= 0)
      {
            cout << n <<"\n";
            n--;
      }
}

void count(int n1, int n2)
{
      
      for(size_t i = n1; i <= n2; i++)
      {
            cout << i << "\n";
      }
      
}

void count(int a, int b, int c)
{
      int i = a;

      while(i<=b)
      {
            if(i == c)
            {
                  i++;
                  continue;
            }
            cout <<i <<"\n";
            i++;
      }
}

int main()
{
      cout << is_even(16) <<"\n";
      cout << is_even(45) <<"\n";
      print_day(0);

      count_down(5000000);

      count(5, 8);

      count(1,15,11);
}
