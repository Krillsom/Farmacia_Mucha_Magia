#pragma once

template <class T>
class Medicamento
{
public:
	Medicamento();
	template<typename T1, typename T2, typename T3>
	Medicamento(T1 nombre, T2 cantidad, T3 precioUnitario);
	~Medicamento();

	T& getNombre();
	void setNombre(T& nombre);

	T& getCantidad();
	void setCantidad(T& cantidad);

	T& getPrecoUnitario();
	void setPrecioUnitario(T& precioUnitario);

private:
	T nombre;
	T cantidad;
	T precioUnitario;
};

template <class T>
Medicamento<T>::Medicamento(){
	nombre = T();
	cantidad = T();
	precioUnitario = T();
}

template <class T, typename T1, typename T2, typename T3>
Medicamento<T>::Medicamento(T1 n, T2 c, T3 p){
	this->nombre = n;
	this->cantidad = c;
	this->precioUnitario = p;
}

template <class T>
Medicamento<T>::~Medicamento(){}

template<class T>
T& Medicamento<T>::getNombre(){
	return nombre;
}

template<class T>
void Medicamento<T>::setNombre(T& nombre) {
	this-> nombre = nombre;
}

template<class T>
T& Medicamento<T>::getCantidad(){
	return cantidad;
}

template<class T>
void Medicamento<T>::setCantidad(T& cantidad){
	this->cantidad = cantidad;
}

template<class T>
T& Medicamento<T>::getPrecoUnitario(){
	return precioUnitario;
}

template<class T>
void Medicamento<T>::setPrecioUnitario(T& precioUnitario){
	this->precioUnitario = precioUnitario;
}
