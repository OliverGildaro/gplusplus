//tarea

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

#define ENDLINE "\n"

using namespace std;

struct StringBuilder
{
      char* array;
      char aux_value[10];
      size_t len;
      size_t nlen;
      size_t count;
};

using SB = StringBuilder;

void init(SB* sb)
{
      sb->array = (char*) malloc(0);
      sb->len = 0;
      sb->nlen = 0;
      sb->count = 0;
}

void add(SB* sb, const char* value)
{
      sb->len = strlen(value);
      if(sb->count == 0)
      {
            sb->array = (char*) realloc(sb->array, (sb->len+1)*sizeof(char));
            memcpy(sb->array, value, sb->len+1);
      }
      else
      {
            sb->array = (char*) realloc(sb->array, (sb->nlen + sb->len + 1)*sizeof(char));
            memcpy(sb->array + sb->nlen, value, sb->len+1);
      }
      sb->nlen = sb->nlen + sb->len;
      sb->count++;
}

void add(SB* sb, int value)
{
      sprintf(sb->aux_value, "%d", value);
      sb->len = strlen(sb->aux_value);
      if(sb->count == 0)
      {
            sb->array = (char*) realloc(sb->array, (sb->len+1)*sizeof(char));
            memcpy(sb->array, sb->aux_value, sb->len);
      }
      else
      {
            sb->array = (char*) realloc(sb->array, (sb->nlen + sb->len + 1)*sizeof(char));
            memcpy(sb->array + sb->nlen, sb->aux_value, sb->len+1);
      }
      sb->nlen = sb->nlen + sb->len;
      sb->count++;
}

void add_line(SB* sb, const char* value)//a;adir un enter al final
{
      sb->len = strlen(value);
      if(sb->count == 0)
      {
            sb->array = (char*) realloc(sb->array, (sb->len+2)*sizeof(char));
            memcpy(sb->array, value, sb->len+1);
            memcpy(sb->array + sb->len, ENDLINE, 2);
      }
      else
      {
            sb->array = (char*) realloc(sb->array, (sb->nlen + sb->len + 2)*sizeof(char));
            memcpy(sb->array + sb->nlen, value, sb->len+1);
            memcpy(sb->array + sb->nlen + sb->len, ENDLINE, 2);
      }
      sb->nlen = sb->nlen + sb->len+1;
      sb->count++;
}

const char* get_string(const SB* sb)
{
      return sb->array;
}

size_t get_length(const SB* sb)
{
      size_t get_count = 0;
      while(sb->array[get_count] != '\0')
      {
            get_count++;
      }
      return get_count;
}

void release(SB* sb)
{
      cout << "bye\n";
      free(sb->array);
}


int main()
{
      SB sb;

      init(&sb);
      add(&sb, "hello");
      // add(&sb, "world");
      add(&sb, 45);
      add_line(&sb, "world");
      add(&sb, "wise");
      add(&sb, 66);
      add_line(&sb, "world");
      cout << get_string(&sb);

      cout << get_length(&sb) << "\n";

      release(&sb);
}





