#include <iostream>
#include <thread>
#include <chrono>//sirve para especificar datos de tiempo
#include <vector>
#include <mutex>//es un objeto que  marca un hilo como esta siendo usada, entonces otro hilo no puede entrar a ese codigo
using namespace std;

int main()
{
    vector<int> z;

    for(size_t i = 1000000 ; i >0; i--)
        z.push_back(i);
    
    int r = find_elem(z, 1);
        cout << r <<"\n";
}