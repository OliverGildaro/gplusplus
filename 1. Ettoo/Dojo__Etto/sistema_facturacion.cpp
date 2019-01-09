#include "sistema_facturacion.h"
#include "m_string.h"
#include "factura.h"
#include "producto.h"

void sistema_facturacion::agregar_producto(const m_string &nombre, 
                                    const m_string &marca, 
                                    const m_string &codigo, 
                                    size_t cantidad, 
                                    double precio)
{
    producto* prod = new producto {nombre, marca, codigo, cantidad, precio};
    productos.add(prod);
    
}

factura& sistema_facturacion::crear_factura(const m_string &nombre, const m_string &nit)
{
    factura* fac = new factura{nombre, nit,*this};
    facturas.add(fac);
    return *fac;
} 

array_list sistema_facturacion::obtener_facturas_de_hoy() const
{
    array_list aux;
    for(size_t i=0;i< facturas.size(); i++)
    {
        aux.add((object*)&(facturas[i]));

    }
    return aux;

}
const producto& sistema_facturacion::get_producto_por_codigo(const m_string& codigo) const
{
    producto aux("", "", codigo , 0, 0);
    return static_cast<const producto&>(productos.get_object(aux));

    
}