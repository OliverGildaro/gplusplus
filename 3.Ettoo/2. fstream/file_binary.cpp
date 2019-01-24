#include <string>
#include <iostream>
#include <fstream>//archivo de escritura
#include <vector>
#include <string>
using namespace std;

struct student
{
    int id;
    char name[124];
};

//escritura binaria en archivos
int main()
{
    vector<student> sts;

    sts.push_back(student{1, "Avril Lavigen"});
    sts.push_back(student{1, "Natalia Lafourcade"});
    sts.push_back(student{1, "Lady Gaga"});

    ofstream j{"students.dat", ios::binary};//con ios::bin le decimos que es un archivo binario y no un archivo de texto

    for(auto& s : sts)
    {
        j.write((char*)&s, sizeof(student));
    }
    j.close();//libera la memoria del archivo

    student arr[3];

    ifstream k{"students.dat", ios::binary};
    k.read((char*)arr, 3*sizeof(student));
    k.close();

    for(auto& a : arr)
    {
        cout << a.name << "\n";
    }
    size_t size;
    //ios::beg.... al principio del archivo
    //ios::cur
    ifstream m{"students.dat", ios::binary};
    m.seekg(0, ios::end);//permite saltar a cualquier posicion del archivo

    size = m.tellg();
    cout << size <<"\n";//el tama;o en memoria del disco

    cout << size/sizeof(student) << "\n";//me da la cantidad de students

    student n;
    m.seekg(1*sizeof(student), ios::beg);
    m.read((char*)&n, sizeof(student));

    cout << n.name <<"\n";
}