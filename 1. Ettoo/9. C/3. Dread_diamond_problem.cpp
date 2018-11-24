//DRead diamond problem
#include <iostream>
using namespace std;


struct J
{
    int p;
};


struct K1 : J
{
    void print()
    {
        cout << p << "\n";
    }
};

struct K2 : J
{
    void show()
    {
        cout << p << "\n";
    }
};


struct L : K1, K2
{
    
};


int main()
{
    L ins;
    ins.K1::p = 18; //se debe desambiguar
    ins.K2::p = 25; //se debe desambiguar
    ins.print();
    ins.show();
}

