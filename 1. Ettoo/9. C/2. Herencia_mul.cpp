#include <iostream>

using namespace std;


struct A
{
    int a;
};


struct B
{
    int b;
};


struct C: A,B
{
    int c;
};


int main()
{
    C  c;
    c.a = 5;
    c.b = 66;
    c.c = 55;
}