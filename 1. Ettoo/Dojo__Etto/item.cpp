#include"item.h"
#include "sistema_facturacion.h"
#include "producto.h"
item::item(size_t cantidad, const m_string& codigo, sistema_facturacion& sis)
:cant{cantidad}, codigo{codigo}, sis{sis}
{

}

void item::mostrar()const
{
    const producto& p = sis.get_producto_por_codigo(codigo);
    cout << cant << "\t" << codigo.get_str() << "\n";
    cout << p.get_name().get_str() << "\n";
    cout << p.get_marca().get_str() << "\n";
    cout << p.get_precio() << "\n";
    
    
}