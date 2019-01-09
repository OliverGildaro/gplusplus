#include <iostream>
#include "array_list.h"
#include "m_string.h"
#pragma once
using namespace std;

class factura;
class m_string;
class producto;

class sistema_facturacion
{
    array_list facturas;
    array_list productos;

    public:
        void agregar_producto(const m_string &nombre, const m_string &marca, const m_string &codigo, size_t cantidad, double precio);
        factura& crear_factura(const m_string &nombre, const m_string &nit = "0");
        array_list obtener_facturas_de_hoy() const;
        const producto& get_producto_por_codigo(const m_string&) const;
};