//tarea

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct StringBuilder
{
      char* array;
      size_t acum_len;
};

using SB = StringBuilder;

void init(SB* sb)
{
      sb->array = (char*) malloc(0);
      sb->acum_len = 0;
      // sb->size_memory = 0;
}

// const char* clone(const char*())

void add(SB* sb, const char* value)
{
      size_t count = 0;
      size_t len = strlen(value);

      if(count==0)
      {
            sb->array = (char*) realloc(sb->array, (len)*sizeof(char));
            memcpy(sb->array, value, len);
      }
      else
      {
            sb->array = (char*) realloc(sb->array, (sb->acum_len)*sizeof(char));
            // memcpy(sb->array + sb->acum_len, value, sb->acum_len);
      }
      sb->acum_len = sb->acum_len + len;
      count++;
      std::cout << sb->array << "\n";
}

// void add(SB* sb, int n)
// {
//       char aux[10];
//       itoa(n, aux, 10);
// }

int main()
{
      SB sb;

      init(&sb);
      add(&sb, "hello");
      add(&sb, "hello");
      add(&sb, "hello");
      // add(&sb, 45);
}

//char aux[20];
//itoa(458, aux, "la base"10) transforma int a char



// void add_line(SB* sb, const char*);//a;adir un enter al final
// {
// }

// size_t get_length(const SB* sb)
// {
// }

// const char* get_string(const SB* sb)
// {
// }

// void release(SB* sb)
// {
// }
