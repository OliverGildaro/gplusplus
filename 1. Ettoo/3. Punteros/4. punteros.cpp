#include <iostream>
using namespace std;

int sumar(const int* dd, size_t n)
{
    auto s = 0;
    
    for(size_t i = 0; i < n; i++)
    {
        s += dd[i];
    }
    return s;
}

int main()
{
    int r[] = {6,8,2,4,45,1};
    int s = sumar(r, 6);
    cout << s << "\n";
}