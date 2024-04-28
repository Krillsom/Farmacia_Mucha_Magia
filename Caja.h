#pragma once
#include "Proveedor.h"
#include "Lista_Medicamentos.h"
#include "Pila.h"
#include "Medicamento.h"

template <class T>
class Caja
{
public:
	Caja();
	Caja(Lista_Medicamentos<T> unalista);
	~Caja();

	void registrarVenta(string nombreMedicamento, int cantidadVenta);
	void mostrarHistorialVentas();

private:
	Lista_Medicamentos<T> unalista;
	Pila<T> historialVentas;
};

template <class T>
Caja<T>::Caja(Lista_Medicamentos<T> unalista){
	this->unalista, unalista;
}

template <class T>
Caja<T>::~Caja()
{
}

template<class T>
void Caja<T>::registrarVenta(string nombreMedicamento, int cantidadVenta) {
	gotoxy(getXCenter(86), Console::WindowTop + 1); cout << R"( 	____  _______________________________  ___    ____     _    _________   ___________ )";
	gotoxy(getXCenter(86), Console::WindowTop + 2); cout << R"(   / __ \/ ____/ ____/  _/ ___/_  __/ __ \/   |  / __ \   | |  / / ____/ | / /_  __/   |)";
	gotoxy(getXCenter(86), Console::WindowTop + 3); cout << R"(  / /_/ / __/ / / __ / / \__ \ / / / /_/ / /| | / /_/ /   | | / / __/ /  |/ / / / / /| |)";
	gotoxy(getXCenter(86), Console::WindowTop + 4); cout << R"( / _, _/ /___/ /_/ // / ___/ // / / _, _/ ___ |/ _, _/    | |/ / /___/ /|  / / / / ___ |)";
	gotoxy(getXCenter(86), Console::WindowTop + 5); cout << R"(/_/ |_/_____/\____/___//____//_/ /_/ |_/_/  |_/_/ |_|     |___/_____/_/ |_/ /_/ /_/  |_|)";
	
	bool medicamentoEnInventario = false;
	int cantidadDisponible = 0;

	Medicamento<string, int, float> venta;

	for (int i = 0; i < unalista.getLon(); ++i)
	{
		if (unalista.obtenerPos(i).getNombre() == nombreMedicamento) {
			medicamentoEnInventario = true;
			cantidadDisponible = unalista.obtenerPos(i).getCantidad();
			venta = unalista.obtenerPos(i);
			break;
		}
	}

	if (!medicamentoEnInventario)
	{
		cout << "El medicamento '" << nombreMedicamento << "' no esta disponible en el inventario" << endl;
	}

	if (cantidadDisponible >= cantidadVenta) {
		//Logica de la venta...
		
		cout << "Venta realizada: " << cantidadVenta << " unidades de " << nombreMedicamento << endl;
		historialVentas.push(venta);
	}
	else {
		cout << "Error: No hay suficientes unidades de '" << nombreMedicamento << "' en el inventario." << endl;
	}                                                                                       
}

template<class T>
void Caja<T>::mostrarHistorialVentas(){

	gotoxy(getXCenter(105), Console::WindowTop + 1);  cout << R"(	__  _____________________  ____  _______    __       ____  ______   _    _________   ___________   _____)";
	gotoxy(getXCenter(105), Console::WindowTop + 2); cout << R"(   / / / /  _/ ___/_  __/ __ \/ __ \/  _/   |  / /      / __ \/ ____/  | |  / / ____/ | / /_  __/   | / ___/)";
	gotoxy(getXCenter(105), Console::WindowTop + 3); cout << R"(  / /_/ // / \__ \ / / / / / / /_/ // // /| | / /      / / / / __/     | | / / __/ /  |/ / / / / /| | \__ \)";
	gotoxy(getXCenter(105), Console::WindowTop + 4); cout << R"( / __  // / ___/ // / / /_/ / _, _// // ___ |/ /___   / /_/ / /___     | |/ / /___/ /|  / / / / ___ |___/ / )";
	gotoxy(getXCenter(105), Console::WindowTop + 5); cout << R"(/_/ /_/___//____//_/  \____/_/ |_/___/_/  |_/_____/  /_____/_____/     |___/_____/_/ |_/ /_/ /_/  |_/____/  )";
																												

	Pila<T> copiaHistorial = historialVentas;
	while (!copiaHistorial.estaVacia()) {

		T dato = copiaHistorial.pop();
	}

}
