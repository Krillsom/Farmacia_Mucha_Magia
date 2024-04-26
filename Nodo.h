#pragma once
 
template<class T>
class Nodo
{
public:
	T dato;
	Nodo<T>* siguiente;

	//Contructor sin parametros

	Nodo() {
		dato = 0;
		siguiente = nullptr;
	}

	//Constructor con parametros
	Nodo(T v, Nodo<T> *sig = NULL){
		dato = v;
		siguiente = sig;
	}

};
