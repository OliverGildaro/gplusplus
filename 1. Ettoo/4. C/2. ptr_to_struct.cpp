#include <iostream>
#include <cstring>
using namespace std;

struct Persona
{
      char nombre[32];
      char apellido[32];
      size_t ci;
};

void init(Persona* p, const char* name, const char* last_name, int id)
{
      strcpy((*p).nombre, name);
      strcpy(p->apellido, last_name);
      p->ci = id;
}

void print(const Persona* p) //con esto le decimos al compilador que el objeto persona no va a cambiar en este scope
{
      cout << p->nombre << " " << p->apellido << " " << p->ci << "\n";
}

int main()
{
      Persona p1;

      init(&p1, "ivan", "rios", 1234567);
      print(&p1);

      Persona* h = new Persona();// el new siempre nos devuelve un puntero
      init(h, "jose maria", "leyes", 34566);
      print(h);
}