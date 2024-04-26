#pragma once
#include <iostream>
#include "Pila.h"
template <class T>
class Caja
{
public:
	Caja();
	~Caja();

	void registrarVenta(T venta);
	void mostrarHistorialVentas() const;

private:
	Pila<T> historialCompras;
};

template <class T>
Caja<T>::Caja()
{
}

template <class T>
Caja<T>::~Caja()
{
}

template<class T>
void Caja<T>::registrarVenta(T venta){
	historialCompras.push(venta);
}

template<class T>
void Caja<T>::mostrarHistorialVentas() const{
	Pila<T> copiaHistorial = historialCompras;
	while (!copiaHistorial.estaVacia()) {

		T dato = copiaHistorial.pop();
		cout << dato << endl;
	}
}
