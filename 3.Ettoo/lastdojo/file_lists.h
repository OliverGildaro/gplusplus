#pragma once
#include <fstream>
#include <string>
#include "list_info.h"
using namespace std;

template<typename T>
class file_lists
{
private:
    std::fstream lists;
    fstream indexes;
    fstream data;
public:
    file_lists(const string& s)
    :lists{s + ".lst", ios::in|ios::out|ios::app|ios::binary},
     indexes{s + ".idx", ios::in|ios::out|ios::app|ios::binary},
     data{s + ".dat", ios::in|ios::out|ios::app|ios::binary}
    {
        // const char* ss = "hola";
        // lists.write(ss, 5);
        // lists.seekg(0);
        // char m[10];
        // lists.read(m, 5);
        // cout << m <<"\n";
    }

    long long get_new_list()
    {
        lists.seekp(0, ios::end);
        long long pos = lists.tellp();
        list_info linfo;
        lists.write(reinterpret_cast<const char*> (&linfo), sizeof(list_info));
        return pos;
    }

    void push_back(long long list, const T& elem)
    {
        list_info aux = get_list_info(list);
        
        if(aux.first == -1)
        {

        }
    }

private:

    list_info get_list_info(long long pos)
    {
        lists.seekg(pos, ios::beg);
        list_info aux;
        lists.read(reinterpret_cast<const char*> (&aux), sizeof(list_info));
        return aux;
    }
};
