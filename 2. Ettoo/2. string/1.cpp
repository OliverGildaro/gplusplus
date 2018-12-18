#include <iostream>
#include <string>
// #include <string_view>
#include <string_view>
using namespace std::string_literals;
// #include <stdexcept>
//Strings
using namespace std;


class Person
{
private:
    string p;
public:
    Person(string_view sv)//al ser sv un objeto chquito basta pasarlo como valor
    :p{sv} { }
    ~Person() { }
    void print() const
    {
        cout <<p<<"\n";
    }
};

int main()
{
    //usar esto en linux con codigo UFT-8
    string h = "hello";
    string w = "world";

    string hw = h +" "+w;
    cout << hw << "\n";

    //usar esto solo en windows
    wstring hh = L"hola"; //cada elemento es un wchar_t
    wstring ww = L"mundo";

    wstring hhww = hh + L" " + ww;//soporta caracteres chinos, arabes
    wcout << hhww << "\n";

    cout << hw.length() << "\n";//length devuelve un size_t

    try{
        
        for(size_t i = 0; i < hw.length()+2; i++)//length es de orden O(1)
        {
            // cout << hw.at(i) << "\n";//este verifica si esta dentro del rango, trabajo extra
            cout << hw[i] << "\n";//este conviene
        }
        
    }catch(const exception& e)//vota un out_of_range exception
    {
        cout <<"hola\n";
        cerr << e.what() << "\n";
    }
    // hw[0] = 'b';
    // hw[3] = ',';
    cout <<hw <<"\n";
    hw.push_back('!');
    hw.push_back('!');
    hw.push_back('!');
    hw.insert(3, " ");
    hw.insert(0, "!");
    cout << hw <<"\n";
    
    auto b = hw.substr(0,3);
    cout << b <<"\n";

    auto v = hw.substr(9);
    cout << v <<"\n";

    auto d = "dinosaurio"s;//para soportar este casteo a string se debe includir.....literals
    auto index = d.find("sau");//devuelve la posicion donde encuentro la palabra
    if(index == string::npos)//quiere decir que no ha encontrado el elemento, devuelve -1... e index size_t
        cout << "no hay";
    else
        cout <<index <<"\n";

    Person p{"juan lopez"};//con string_view evitamos hacer una copia en este punto
    //dado que en este punto convierte el const char* en string y despues de enviarlo lo destruye
    Person g{"Jose suares"s};

    p.print();
    g.print();
}