#include <iostream>
#include <cstring>
using namespace std;


struct ILLItem
{
      int value;
      ILLItem* next;
};


struct ILL
{
      ILLItem* first;
      ILLItem* last;
};

void init(ILL* x)
{
      x->first = x->last = nullptr;
}

void add(ILL* x, int n)
{
      auto item = new ILLItem{n, nullptr};

      if(x->first == nullptr)
      {
            x->first = x->last = item;
            return;
      }
      else{
            x->last->next = item;
            x->last = item;
      }
}

void print(const ILL* x)
{
      auto aux = x->first;
      while(aux)
      {
            cout << aux->value << "\n";
            aux = aux->next;
      }
}

void release(ILL* x)
{
      auto aux = x->first;

      while(aux)
      {
            auto next = aux->next;
            delete aux;
            aux = next;
            cout <<"bye\n";
      }
}

int main()
{
      ILL x;

      init(&x);
      add(&x, 85);
      add(&x, 34);
      add(&x, 66);
      add(&x, 34);
      
      print(&x);

      release(&x);

}

