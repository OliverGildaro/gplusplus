#include <iostream>

using namespace std;

size_t divisor(size_t id)
{
      switch (id)
      {
            case 1:
                  return id = 10;
            case 2:
                  return id = 10;
            case 3:
                  return id = 100;
            case 4:
                  return id = 1000;
            case 5:
                  return id = 10000;
      }
}

void unidades(unsigned int n)
{
      switch (n)
      {
            case 1:
                  cout << " uno\n";
                  break;
            case 2:
                  cout << " dos\n";
                  break;
            case 3:
                  cout << " tres\n";
                  break;
            case 4:
                  cout << " cuatro\n";
                  break;
            case 5:
                  cout << " cinco\n";
                  break;
            case 6:
                  cout << " seis\n";
                  break;
            case 7:
                  cout << " siete\n";
                  break;
            case 8:
                  cout << " ocho\n";
                  break;
            case 9:
                  cout << " nueve\n";
                  break;   
      }
}

void decenas(unsigned int n)
{
      switch (n)
      {
            case 1:
                  cout << " diez";
                  break;
            case 2:
                  cout << " veinte";
                  break;
            case 3:
                  cout << " treinta";
                  break;
            case 4:
                  cout << " cuarenta";
                  break;
            case 5:
                  cout << " cincuenta";
                  break;
            case 6:
                  cout << " sesenta";
                  break;
            case 7:
                  cout << " setenta";
                  break;
            case 8:
                  cout << " ochenta";
                  break;
            case 9:
                  cout << " noventa";
                  break;   
      }
}

void centenas(unsigned int n)
{
      switch (n)
      {
            case 1:
                  cout << " cien";
                  break;
            case 2:
                  cout << " doscientos";
                  break;
            case 3:
                  cout << " trescientos";
                  break;
            case 4:
                  cout << " cuatroscientos";
                  break;
            case 5:
                  cout << " quinientos";
                  break;
            case 6:
                  cout << " seisientos";
                  break;
            case 7:
                  cout << " setecientos";
                  break;
            case 8:
                  cout << " ochosientos";
                  break;
            case 9:
                  cout << " novecientos";
                  break;   
      }
}

void miles(unsigned int n)
{
      switch (n)
      {
            case 1:
                  cout << " mil";
                  break;
            case 2:
                  cout << " dosmil";
                  break;
            case 3:
                  cout << " tresmil";
                  break;
            case 4:
                  cout << " cuatromil";
                  break;
            case 5:
                  cout << " cincomil";
                  break;
            case 6:
                  cout << " seismil";
                  break;
            case 7:
                  cout << " sietemil";
                  break;
            case 8:
                  cout << " ochomil";
                  break;
            case 9:
                  cout << " nuevemil";
                  break;   
      }
}

void print_as_text(unsigned int n)
{
      int x_cos;
      int x_res;
      int x_last;
      size_t count_dig = 0;

      unsigned int aux_saved = n;

      while(aux_saved >= 1)
      {
            x_cos = aux_saved/10;
            aux_saved = x_cos;
            count_dig++;
      }

      while(count_dig>0)
      {
            x_res = n/(divisor(count_dig));
           
            switch (count_dig)
            {
                  case 1:
                        unidades(n%(divisor(count_dig)));
                        break;
                  case 2:
                        decenas(x_res);
                        break;
                  case 3:
                        centenas(x_res);
                        break;
                  case 4:
                        miles(x_res);
                        break;
            }
            n = n%(divisor(count_dig));
            count_dig--;
      }
}

int main()
{
      print_as_text(5255);
}