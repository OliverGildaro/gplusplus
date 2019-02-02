#include <iostream>
#include "file_lists.h"
#include "person.h"
using namespace std;


// template <typename Key, typename Var>
// class file_map
// {
//     private:
//     string m_name;
//     public:
//     file_map(const string& p_name)
//     :m_name{p_name}
//     {

//     }

//     void insert(pair< int, person>)
//     {

//     }
// };

// int main()
// {
//     file_map<int, person> m { "persona"};

//     m.insert(make_pair(1231234, person { "Federico", "Froebel", 1942 }));
//     m.insert(make_pair(5483457, person { "German", "Urquidi", 1877 }));
//     m.insert(make_pair(7934722, person { "Adela", "Zamudio", 2012 }));
//     m.insert(make_pair(6056938, person { "Eduardo", "Mitre", 1875 }));
//     m.insert(make_pair(5669569, person { "Jaimes", "Freyre", 1962 }));

//     m.iterate([](auto& p)
//     {
//         cout << p << endl;
//     });

//     cout << "**********************" << endl;

//     auto value = m.find(5669569);
//     if (value.has_value())
//         cout << value.get_value() << endl;
//     else
//     {
//         cerr << "Not found" << endl;
//     }
    

// }



int main()
{
    file_lists<person> p { "people"};

    auto list = p.get_new_list();
    cout << list << endl;
    // p.push_back(list, person { "adela", "zamudio", 1992 });
    // p.push_back(list, person { "armando", "chirveches", 1923 });

    // auto list2 = p.get_new_list();
    // list2.push_back(person { "peter", "gabriel", 2002 });
    // list2.push_back(person { "phil", "collings", 1938 });

    // auto list3 = p.get_list(list2);
    // list3.push_back(person { "kylie", "minogue", 1954 });

    // list1.iterate([](const person& x)
    // {
    //     cout << x << endl;
    // });

    // list2.iterate([](const person& x)
    // {
    //     cout << x << endl;
    // });
}
