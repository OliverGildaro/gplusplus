#include <iostream>
#include <memory>
#include <vector>
//SHARED PTR
using namespace std;
//los shared pointers no funcionan con referencias circulares
//para esto usamos weak pointers

class Int
{
private:
    int n;
public:
    Int(int n)
    :n{n} { }
    ~Int() 
    { 
        cout << "bye " << n <<"\n";
    }
};

int main()
{
    shared_ptr<Int> a{new Int{19}};
    shared_ptr<Int> b = make_shared<Int>(60);
    auto c = make_shared<Int>(88);
    auto d = a;
    b = make_shared<Int>(429);
    auto e = a;
    a = make_shared<Int>(8000);
    cout <<"******************\n";
}