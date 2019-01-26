#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    stringstream ss;

    string hoy = "viernes";
    int dia = 25;
    const char* res = "enero";
    size_t anio = 2019;
    ss << "hoy es " << hoy << " " <<dia << " de" << res << anio << "\n";

    string str = ss.str();
    cout << str;
}