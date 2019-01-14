#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
using namespace std;

class Fatty
{
private:
    char *p;

public:
    Fatty(char k)
    {
        p = new char[1000000];

        for (size_t i = 0; i < 1000000; i++)
        {
            p[i] = k;
        }
    }

    Fatty(const Fatty &src)
    {
        p = new char[1'000'000];

        for (size_t i = 0; i < 1'000'000; i++)
        {
            p[i] = src.p[i];
        }
    }

    Fatty &operator=(const Fatty &src)
    {
        delete[] p;

        p = new char[1'000'000];

        for (size_t i = 0; i < 1'000'000; i++)
        {
            p[i] = src.p[i];
        }
        return *this;
    }

    Fatty(Fatty &&src)
        : p{src.p}
    {
        src.p = nullptr;
    }

    Fatty &operator=(Fatty &&src)
    {
        delete[] p;

        p = src.p;

        src.p = nullptr;

        return *this;
    }

    ~Fatty()
    {
        delete[] p;
    }
};

template <typename T>
void swp(T &a, T &b)
{
    T aux = move(a);
    a = move(b);
    b = move(aux);
}

int main()
{
    Fatty a{'x'};
    Fatty b{'y'};

    auto z0 = clock();

    for (size_t i = 0; i < 30001; i++)
    {
        swp(a, b);
    }
    auto z1 = clock();

    cout << (z1 - z0) << "\n";
}