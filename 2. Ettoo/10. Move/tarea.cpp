#include <iostream>

using namespace std;

int main()
{
      pq<string, 4> s;
      s.enqueve(2, "hello");
      s.enqueve(3, "world");
      s.enqueve(1, "friends");
      s.enqueve(0, "today");
      s.enqueve(0, "is");
      s.enqueve(0, "tuesday");
      s.enqueve(1, "of");
      s.enqueve(1, "c++");

      
      while(!s.is_empty()){
            auto r = s.dequeue();
            cout << r <"\n";
      }
      
}