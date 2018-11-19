#include <iostream>

using namespace std;

void do_something(int n)
{
      cout << "hello\n";
      cout << "one\n";
      cout << "two\n";

      if(n == 3)
            goto SAY_BYE; // sirve para liberar memoria que se haya recervado cuando ya no puede continuar el programa
      return; 

      cout << "four\n";

      SAY_BYE: // esta etiqueta solo se puede implementar en el mismo ambito
      cout << "bye\n";
}

int main()
{
      do_something(5);
      cout << "****\n";
      do_something(3);
}