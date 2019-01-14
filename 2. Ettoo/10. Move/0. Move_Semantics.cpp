#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
using namespace std;

class A
{
  private:
    string p;

  public:
    A(const string &s)
    :p{s}  //aca se llama al const copia de la clase string
    { 
        cout <<"const copia\n";
    }
    ~A() { }

    A(string &&s)
    :p(move(s))
    {
        cout << "const move string\n";
    }

    A(A &&src) //recibe un rvalue reference no constante a la fuente
    : p{move(src.p)}
    {
        cout << "const move object\n";
    }

    string get() const
    {
        return p;
    }
};

vector<int> get_list()
{
    vector<int> z;

    for (size_t i = 0; i < 10000; i++)
    {
        z.push_back(i);
    }
    return z;
}

int main()
{
    A a{"hola"}; //se crea un string temporal en este punto, hace movida
    //gracias a la sobrecarga del const de movida

    string s = "2019"; //en este caso no estamos creando un string temporal
    A b{s};//hace copia

    A c{move(s)};//le obligo a hacer una movida, "conviene"

    A d{move(b)};//el objeto b ya no existe

    cout << a.get() << "\n";
    cout << c.get() << "\n";
    cout << d.get() << "\n";

    vector<int> r;
    r = move(get_list());//en lugar de realizar una copia hacemos una movida

    for(auto& i : r)
    {
        cout << i << "\n";
    }
}