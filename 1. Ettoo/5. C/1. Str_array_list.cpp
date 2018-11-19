//string array list

#include <iostream>
#include <cstdlib> //para incluir malloc
#include <cstring>

using namespace std;

struct stringArraylist
{
      char** items;
      size_t n;
};

using SAL = stringArraylist; //definiendo un alias del tipo stringArrayLIST, se define despues de la declaracion
//otra forma mas limitada de hacerlo-> typedef stringArrayList SAL

void init(SAL* s)
{
      s->items = (char**) malloc(0);//mallo devuelve un void*, pide memoria de cero bits
      s->n = 0;
}

char* clone(const char* s)
{
      size_t len = strlen(s);
      char* cs = new char[len+1];
      //strcpy(cs, s);//copia caracter por caracter hast nullptr
      memcpy(cs, s, len+1);//copia la direccion de la memoria y el tamanio de bits
      return cs;
}

void add(SAL* ss, const char* s)
{
      ss->items = (char**) realloc(ss->items, (ss->n+1)*sizeof(char*)); //le pasamos el array y el numero de bits que queremos
      //para recervar memoria, al mismo tiempo ya elimina la memoria que ya no se usa, devuelve un puntero a la primera 
      //posicion de la nueva memoria 


      ss->items[ss->n] = clone(s);
      ss->n++;
}

void print(const SAL* s)
{
      
      for(size_t i = 0; i < s->n; i++)
      {
            cout << s->items[i] << "\n";
      }
      
}

void release(SAL* s)
{
      for(size_t i = 0; i < s->n; i++)
      {
            delete[] s->items[i];
      }
            
      free(s->items);//free libera la memoria recervada por malloc
}

int main()
{
      SAL ss;

      init(&ss);

      add(&ss, "hello");
      add(&ss, "world");
      add(&ss, "today");
      add(&ss, "is");
      add(&ss, "thursday");
      
      print(&ss);

      release(&ss);
}

