#pragma once
#include "Lista_Medicamentos.h"


template <class T>
class Almacen 
{
	Lista_Medicamentos<T> unalista;

public:
	Almacen();
	~Almacen();
	void agregar_inicio_lista(T obj);
	T get_elemento_lista(int n);

	void pedir_medicamento(T obj);

};

template <class T>
Almacen<T>::Almacen()
{
}

template <class T>
Almacen<T>::~Almacen()
{
}

template<class T>
inline void Almacen<T>::agregar_inicio_lista(T obj)
{
	unalista.agregaInicial(obj);
}

template<class T>
inline T Almacen<T>::get_elemento_lista(int n)
{

	return unalista.obtenerPos(n);
}

template<class T>
inline void Almacen<T>::pedir_medicamento(T obj)
{
	string temp_Name =  "";
	int temp_cantidad = 0;
	
	cout << "\n\nIngrese el nombre de la medicina: ";
	cin >> temp_Name;
	cout << "\n\nIngrese la cantidad a pedir: ";
	cin << temp_cantidad;

	//dar valores a proovedor para que cree el objeto medicina en su cola
}
