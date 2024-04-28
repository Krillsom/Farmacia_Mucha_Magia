#pragma once
#include "Medicamento.h"

template<class T>
class Lista_Medicamentos
{
private:
	struct Nodo;
	Nodo* ini;
	int lon;

public:
	Lista_Medicamentos();
	~Lista_Medicamentos();
	void    agregaInicial(T medicina);
	void    eliminaInicial();
	void    eliminarPos(int pos);
	void	coutLista();
	int get_lon();
	void forEach(function<void(T)> callback);
	T       obtenerPos(int pos);
};

template <typename T>
struct Lista_Medicamentos<T>::Nodo {
	T       medicina;
	Nodo* sig;
	//Nodo* ant;
	//Nodo* last;
	//Nodo* first;

	Nodo(T medicina = NULL, Nodo* sig = nullptr) : medicina(medicina), sig(sig) {}
};



template<class T>
Lista_Medicamentos<T>::Lista_Medicamentos()
{
	this->ini = nullptr;
	this->lon = 0;
}



template<class T>
Lista_Medicamentos<T>::~Lista_Medicamentos()
{
}

template <typename T>
void Lista_Medicamentos<T>::agregaInicial(T medicina) {
	Nodo* nuevo = new Nodo(medicina, ini);
	if (nuevo != nullptr) {
		ini = nuevo;
		lon++;
	}
}


template <typename T>
void Lista_Medicamentos<T>::eliminaInicial() {
	if (lon > 0) {
		Nodo* aux = ini;
		ini = ini->sig;
		delete aux;
		lon--;
	}
}


template<class T>
inline void Lista_Medicamentos<T>::eliminarPos(int pos)
{
	if (pos >= 0 && pos < lon) {
		Nodo* aux = ini;
		Nodo* anterior = nullptr;
		for (int i = 0; i < pos; i++) {
			anterior = aux;
			aux = aux->sig;
		}
		if (anterior != nullptr) {
			anterior->sig = aux->sig;
		}
		else {
			ini = aux->sig;
		}
		delete aux;
		lon--;
	}
}


template<class T>
inline void Lista_Medicamentos<T>::coutLista()
{
	int pos = 0;
	Nodo* aux = ini;
	while (aux != nullptr) {
		aux->medicina.mostrar(9, ConsoleColor::Yellow, ++pos);
		aux = aux->sig;
	}

}

template<class T>
T Lista_Medicamentos<T>::obtenerPos(int pos) {

	if (pos >= 0 && pos < lon) {
		Nodo* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->sig;
		}
		return aux->medicina;
	}
	/*else {
		return nullptr;
	}*/
}

template<class T>
inline int Lista_Medicamentos<T>::get_lon()
{
	return this->lon;
}

template<class T>
inline void Lista_Medicamentos<T>::forEach(function<void(T)> callback)
{
	Nodo* aux = ini;
	while (aux != nullptr) {
		callback(aux->medicina);
		aux = aux->sig;
	}
}
