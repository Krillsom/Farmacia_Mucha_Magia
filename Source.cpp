#include "string"
#include "Tienda.h"

using namespace std;

int main() {
    srand(time(nullptr));

    //Almacen<Medicamento<string, int, float>>* almacen = new Almacen<Medicamento<string, int, float>>;
    Tienda* objTienda = new Tienda();

    objTienda->menu();
    //almacen->mostrarPedidos();
 

    delete objTienda;

    cin.get();
    cin.ignore();
    return 0;
}