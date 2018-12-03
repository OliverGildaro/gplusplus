#include <iostream>
#include "m_string.h"
#include "object.h"

using namespace std;

class producto : public object
{
    m_string nombre;
    m_string marca;
    m_string codigo;
    size_t cantidad;
    double precio;

    public:
    producto(const m_string&, const m_string&, const m_string&, size_t, double);

    void mostrar() const override;
    bool equals_to(const object&) const override;

    const m_string &get_name() const;
    const m_string &get_marca() const;
    const size_t get_cantidad() const;
    const double get_precio() const;
};