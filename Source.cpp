#include "Farmacia.h"
#include "string"
#include "Almacen.h"
#include "Medicamento.h"

using namespace std;

int main() {
	srand(time(nullptr));
	
	Almacen<Medicamento<string, int, float>>* almacen = new Almacen<Medicamento<string, int, float>>;
	
	almacen->registrarPedido();
	
	almacen->mostrarPedidos();
	/*Farmacia farmacia;
	farmacia.menu();*/

	cin.get();
	cin.ignore();
	return 0;
}