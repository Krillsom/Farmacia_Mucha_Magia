#include "string"
#include "Almacen.h"
#include "Medicamento.h"
#include "Lista_Medicamentos.h"
#include "Caja.h"

using namespace std;

int main() {
	srand(time(nullptr));
	
	/*Almacen<Medicamento<string, int, float>>* almacen = new Almacen<Medicamento<string, int, float>>;
	
	almacen->registrarPedido();
	
	almacen->mostrarPedidos();
	Farmacia farmacia;
	farmacia.menu();*/

	Lista_Medicamentos<Medicamento<string, int, float>>* lista = new Lista_Medicamentos<Medicamento<string,int,float>>;

	Caja<Medicamento<string,int,float>> caja(*lista);

	string nombreMedicamento = "Paracetamol";
	int cantidadVenta = 10;

	caja.registrarVenta(nombreMedicamento, cantidadVenta);
	Console::Clear;
	caja.mostrarHistorialVentas();


	cin.get();
	cin.ignore();
	return 0;
}