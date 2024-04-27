#include "Nodo.h"

template<class T>
class Cola {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
	int _size;

public:
	Cola();
	~Cola();
	void enqueue(T v);
	T dequeue();
	bool esVacia();
	T peek();
	void forEach(void (*callback)(T));
	int size();

};

template<class T>
inline Cola<T>::Cola()
{
	this->inicio = nullptr;
	this->fin = nullptr;
	this->_size = 0;
}

template<class T>
bool Cola<T>::esVacia() {
	return (inicio == nullptr);
}

template<class T>
inline T Cola<T>::peek()
{
	return inicio;
}

template<class T>
inline void Cola<T>::forEach(void(*callback)(T))
{
	Nodo<T>* aux = inicio;
	while (aux != nullptr) {
		callback(aux->dato);
		aux = aux->siguiente;
	}
}

template<class T>
inline int Cola<T>::size()
{
	return _size;
}


template<class T>
inline Cola<T>::~Cola()
{
}

template<class T>
void Cola<T>::enqueue(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);
	if (esVacia()) {
		inicio = nodo;
		fin = inicio;
	}
	else {
		fin->siguiente = nodo;
		fin = nodo;
	}
	_size++;
	nodo = nullptr;
}

template<class T>
T Cola<T>::dequeue() {
	T dato = inicio->dato;

	if (inicio == fin) {
		inicio = nullptr;
		fin = nullptr;
	}
	else {
		inicio = inicio->siguiente;
	}

	_size--;
	return dato;
}

