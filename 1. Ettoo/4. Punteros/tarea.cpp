#include <iostream>
#include <cstring>

struct node
{
      char* word;
      node* next;
};

struct SLL
{
      node* first;
      node* last;
};

void init(SLL& s)
{
      s.first = nullptr;
      s.last = nullptr;
}

void add_tail(SLL* s, const char* value)
{
      size_t len = strlen(value);
      char* aux_value = new char[len+1];
      memcpy(aux_value, value, len+1);

      node* new_node = new node{aux_value, nullptr};

      if(s->first == nullptr)
      {
            s->first = s->last = new_node;
      }
      else{
            s->last->next = new_node;
            s->last = new_node;
      }
}

void add_head(SLL* s, const char* value)
{
      size_t len = strlen(value);
      char* aux_value = new char[len+1];
      memcpy(aux_value, value, len+1);

      node* new_node = new node{aux_value, nullptr};

      if(s->first == nullptr)
      {
            s->first = s->last = new_node;
      }
      else{
            new_node->next = s->first;
            s->first = new_node;
      }
}

void print(SLL* s)
{
      node* aux_node = s->first;

      while(aux_node){
            std::cout << aux_node->word << "\n";
            aux_node = aux_node->next;
      }
}

void release(SLL* s)
{
      node* cursor = s->first;

      
      while(cursor){
            s->first = s->first->next;
            std::cout << "Bye: " << cursor->word << "\n";
            delete[] cursor->word;
            delete cursor;
            cursor = s->first;
      }
      
}

int main()
{
      //ejercicio
      SLL s;
      init(s);

      add_head(&s, "is");
      add_tail(&s, "thursday");
      add_head(&s, "today");
      add_head(&s, "world");
      add_head(&s, "hello");

      print(&s);
      release(&s);
}

