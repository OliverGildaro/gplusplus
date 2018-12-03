#include <iostream>
#include "object.h"
#include "m_string.h"

using namespace std;
class sistema_facturacion;
class item : public object
{
    size_t cant;
    m_string codigo;
    sistema_facturacion& sis;
    public:
        item(size_t , const m_string&, sistema_facturacion&);
        void mostrar() const override;

};