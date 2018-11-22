#include <iostream>

using namespace std;

void p()
{
    static int n = 5;//la variable n solo se declara una vez, y vive solo dentro de este metodo
    cout << n++ <<"\n";
}

int main()
{
    p();
    p();
    p();
    p();
    p();
}