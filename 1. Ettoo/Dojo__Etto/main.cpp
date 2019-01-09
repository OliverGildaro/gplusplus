#include <iostream>
#include "sistema_facturacion.h"
#include "factura.h"

using namespace std;

int main(){

    sistema_facturacion sf;

    sf.agregar_producto("Leche", "PIL", "1245235423451", 50, 5);
    sf.agregar_producto("Yogurt", "PIL", "4245845254", 20, 15);
    sf.agregar_producto("Paneton", "IC Norte", "2390482394283", 500, 22.50);

    auto &f = sf.crear_factura("Omar Vera", "1029382015");
    f.agregar_item(1, "1245235423451");
    f.agregar_item(2, "2390482394283");

    auto &g = sf.crear_factura("Juan Pedro");
    g.agregar_item(2, "1245235423451");
    g.agregar_item(1, "4245845254");
    g.agregar_descuento(5);

    auto fc = sf.obtener_facturas_de_hoy();
    for (auto i = 0U; i < fc.size(); i++)
        ((factura&)fc[i]).mostrar();
}
