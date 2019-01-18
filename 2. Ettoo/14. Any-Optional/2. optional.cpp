#include <iostream>
#include <vector>
#include <functional>
#include <optional>
#include <map>
using namespace std;

template <typename C, typename T>
optional<reference_wrapper <const typename C::mapped_type>> my_find(const C& c,     const T& val)
{
    auto it = c.find(val);
    if(it == c.end())
    {
        return{};
    }
    else
    {
        return ref(it->second);
    }
}

int main()
{
    map<int, string> m;

    m[10] = "diez";
    m[4] = "vuatro";
    m[3] = "tres";
    m[12]= "doce";
    m[20] = "veinte";

    auto r = my_find(m, 20);

    if(r)
    {
        cout << r.value().get() << " \n";//me llega un objeto de reference_wrapper por eso usamos get();
    }
    else
        cout << "not found\n";

}