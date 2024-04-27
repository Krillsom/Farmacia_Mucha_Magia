#pragma once
#include "Utilidades.h"

template<typename T1, typename T2, typename T3>
class Medicamento
{
private:
	T1 nombre;
	T2 cantidad;
	T3 precio;
	int pos;

public:
	Medicamento();
	Medicamento(T1 nombre, T2 cantidad, T3 precio, int pos);
	~Medicamento();

	T1 getNombre();
	void setNombre(T1& nombre);

	T2 getCantidad();
	void setCantidad(T2& cantidad);

	T3 getPrecio();
	void setPrecio(T3& Precio);

	void mostrar(short baseY);

};


template<typename T1, typename T2, typename T3>
inline Medicamento<T1, T2, T3>::Medicamento()
{
	this->nombre = T1();
	this->cantidad = T2();
	this->precio = T3();
	this->pos = 0;
}

template<typename T1, typename T2, typename T3>
inline Medicamento<T1, T2, T3>::Medicamento(T1 nombre, T2 cantidad, T3 precio, int pos)
{ 	
	this->nombre = nombre;
	this->cantidad = cantidad;
	this->precio = precio;
	this->pos = pos;
}


template<typename T1, typename T2, typename T3>
inline Medicamento<T1, T2, T3>::~Medicamento()
{
}

template<typename T1, typename T2, typename T3>
inline T1 Medicamento<T1, T2, T3>::getNombre()
{
	return nombre;
}

template<typename T1, typename T2, typename T3>
inline void Medicamento<T1, T2, T3>::setNombre(T1& nombre)
{
	this->nombre = nombre;
}

template<typename T1, typename T2, typename T3>
inline T2 Medicamento<T1, T2, T3>::getCantidad()
{
	return cantidad;
}

template<typename T1, typename T2, typename T3>
inline void Medicamento<T1, T2, T3>::setCantidad(T2& cantidad)
{
	this->cantidad = cantidad;
}

template<typename T1, typename T2, typename T3>
inline T3 Medicamento<T1, T2, T3>::getPrecio()
{
	return this->Precio;
}

template<typename T1, typename T2, typename T3>
inline void Medicamento<T1, T2, T3>::setPrecio(T3& precio)
{
	this->precio = precio;
}

template<typename T1, typename T2, typename T3>
inline void Medicamento<T1, T2, T3>::mostrar(short baseY)
{
	stringstream* ss = new stringstream;

	*ss << "Nombre: " << this->nombre;
	*ss << "   Cantidad: " << this->cantidad;
	*ss << "   Precio: " << this->precio;

	string* message = new string;
	*message = ss->str();

	if (this->pos == 0) color(ConsoleColor::Cyan);
	else color(ConsoleColor::DarkGray);

	short* x = new short(getXCenter<short>(message->length() + 4));
	short* y = new short(baseY + pos * 3);

	gotoxy<short>(*x - 2, *y - 1);
	
	cout << char(201);
	for (short i = 0; i < message->length() + 2; i++) cout << char(205);
	cout << char(187);

	gotoxy<short>(*x - 2, *y);

	cout << char(186) << " " << *message << " " << char(186);

	gotoxy<short>(*x - 2, *y + 1);

	cout << char(200);
	for (short i = 0; i < message->length() + 2; i++) cout << char(205);
	cout << char(188);

	color(ConsoleColor::White);

	delete ss;
	delete message;
	delete x;
	delete y;
}
