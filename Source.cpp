#include "Tienda.h"
#include "string"
#include "Almacen.h"
#include "Medicamento.h"

using namespace std;

int main() {
	srand(time(nullptr));
	
	//Almacen<Medicamento<string, int, float>>* almacen = new Almacen<Medicamento<string, int, float>>;
	Tienda* objTienda = new Tienda();

	objTienda->menu();
	//almacen->mostrarPedidos();
	/*Farmacia farmacia;
	farmacia.menu();*/

	delete objTienda;

	cin.get();
	cin.ignore();
	return 0;
}