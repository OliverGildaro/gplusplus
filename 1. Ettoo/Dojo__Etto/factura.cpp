#include "factura.h"
#include "item.h"
#include "sistema_facturacion.h"
factura::factura(const m_string &nombre, const m_string &nit, sistema_facturacion& sis)
: nombre{nombre},nit{nit}, descuento{0}, sis{sis}
{
}

void factura::agregar_item(size_t cantidad, const m_string & codigo)
{
    item* it = new item{cantidad,codigo, sis};
    items.add(it);
}
void factura::agregar_descuento(double desc)
{
    descuento += desc;
}
void factura::mostrar() const
{
    cout<<nombre.get_str()<<"\t"<<nit.get_str()<<'\n';
    cout<<"ITEMS:\n\n";
    items.mostrar();
}

