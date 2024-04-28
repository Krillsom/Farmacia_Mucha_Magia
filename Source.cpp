#include "string"
#include "Almacen.h"
#include "Medicamento.h"
#include "Caja.h"

using namespace std;

int main() {
	srand(time(nullptr));
	
	/*Almacen<Medicamento<string, int, float>>* almacen = new Almacen<Medicamento<string, int, float>>;
	
	almacen->registrarPedido();
	
	almacen->mostrarPedidos();
	Farmacia farmacia;
	farmacia.menu();*/

	Caja<string> caja;

	string nombreMedicamento = "Paracetamol";
	int cantidadVenta = 10;

	caja.registrarVenta(nombreMedicamento, cantidadVenta);

	caja.mostrarHistorialVentas();


	cin.get();
	cin.ignore();
	return 0;
}