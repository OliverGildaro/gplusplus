#include <iostream>
#include <iomanip>
//MANIPULADORES
using namespace std;

template <size_t N>
ostream& stars(ostream& os)
{
    for(size_t i =0U; i <N; i++)
    {
        os <<"*";
    }
    return os;
}

class dashes
{
private:
    int n;
public:
    dashes(int n)
    :n{n} { }
    ~dashes() { }

    ostream& operator()(ostream& os) const
    {
        for(int i= 1; i<n; i++)
        {
            os << "-";
        }
        return os;
    }
};

ostream& operator<<(ostream& os, const dashes& das)
{
    return das(os);
}

int main()
{
    bool x = true;
    cout << boolalpha << x << endl;//endl tb es un manipulador

    for(int i= 1; i<100000; i*=10)
    {
        cout << setw(10) << i << "\n";
    }

    double p = 2344577542323.345;
    cout << p <<"\n";
    cout << fixed << p << "\n";
    cout << scientific << p << "\n";
    cout << defaultfloat << p <<"\n";
    cout <<setprecision(10) << p <<"\n";
    cout << 0xCAFEBABE <<"\n";//es una palabra recervada de java
    cout << hex <<0xCAFEBABE <<"\n";
    int d = 0xCAFEBABE;
    cout << uppercase << d <<"\n";
    cout << d <<"\n";
    cout << nouppercase << d <<"\n";
    cout << dec << d <<"\n";
    cout << oct << d << dec << "\n";
    cout << false <<"\n";
    cout << noboolalpha << false << "\n";

    // int a;
    // cin >> hex >> a;
    //escribir deadbeef
    // cout << hex << a <<"\n";

    cout << stars<5> << "hola" << "\n";

    cout << dashes(5) << "mundo" << "\n";
}