#pragma once
#include <iostream>
#include "Nodo.h"

using namespace::std;

template<class T>
class Pila
{
public:
	Pila() { tope = nullptr;};
	void push(T v);
	T pop();
	bool estaVacia();

private:
	Nodo<T>* tope;
};

template<class T>
void Pila<T>::push(T v){
	if (estaVacia()) {
		tope = new Nodo<T>(v);
	}else{
		tope = new Nodo<T>(v, tope);
	}
}

template<class T>
T Pila<T>::pop()
{
	if (estaVacia()){
		return T();
	}
	else {
		T elemento = (T)(tope->dato);
		tope = (Nodo<T>*) tope->siguiente;
		return elemento;
	}
}

template<class T>
bool Pila<T>::estaVacia()
{
	return (tope == NULL);
}
