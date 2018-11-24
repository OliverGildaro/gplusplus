//strings
#include <iostream>

using namespace std;

// size_t calc_length(const char* str)
// {
//       int len = 0;

//       while(str[len] != '\0')
//       {
//             len++;
//       }

//       return len;
// }


// size_t calc_length(const char* str)
// {
//       int len = 0;

//       while(*(str+len) != '\0')//utilizando aritmetica de punteros
//       {
//             len++;
//       }

//       return len;
// }


size_t calc_length(const char* str)
{
      const char* orig = str;
      while(*str++);

      return str - orig - 1;
}

void copiar_cadena(char* cd, const char* c)
{
      size_t pos = 0;
      while(c[pos]!='\0')
      {
            cd[pos] = c[pos];
            pos++;
      }
      cd[pos] = '\0';
}

void concatenar_cadena(char* cd, const char* d)
{
      // size_t count =0;
      // while(cd[count] != '\0')
      // {
      //       count++;
      // }

      // size_t count2 =0;
      // while(d[count2]!='\0')
      // {
      //       cd[count] = d[count2];
      //       count++;
      //       count2++;
      // }
      // cd[count] = '\0';

      //en una sola linea

      copiar_cadena(cd + calc_length(cd), d);
}

void substring(char* dst, const char* src, int n1, int n2)
{
      size_t count = 0;
      while(count < n2)
      {
            *(dst+count) = *(src+n1);
            count++;
            n1++;
      }
      *(dst+count) = '\0';
}

int main()
{
      const char* q = "hello world";//solo es de lectura, segmentation fault si se trata de escribir
      cout << q << "\n";

      char s[] = "hola mundo";
      cout << s << "\n";
      s[0] = 'c';
      cout << s << "\n";

      cout << calc_length(q) << "\n";
      cout << calc_length(s) << "\n";

      //Aritmetica de punteros "+ - ++ --"->operaciones permitidas

      const char* a = "perro";

      const char* b = a + 2;

      cout << b << "\n";
      b--;
      cout << b << "\n";

      //concatenar dos cadenas
      const char* c = "Fundacion";
      const char* d = "Jala";
      char cd[30];

      copiar_cadena(cd, c);
      cout << cd << "\n";
      concatenar_cadena(cd, d);
      cout << cd << "\n";

      auto r = "hoy es lunes 12";
      char rr[10];

      substring(rr,r,7,5);
      cout << rr << "\n";
}