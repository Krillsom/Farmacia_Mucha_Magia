#pragma once

#include "sstream"
#include <iostream>
using namespace System;
using namespace std;

class Cupon
{
public:
	Cupon(int intnombre);
	Cupon(string nombre, int porcentaje);
	~Cupon();
	void mostrar();

private:
	string nombre_str = "";
	int nombre_int = 0;
	int porcentajeDescuento;
};


Cupon::Cupon(int intnombre)
{
	//int random = rand() % 1000;
	float porcentajeDescuento = rand() / 10;

	this->nombre_int = intnombre;  //se le pone un numero para despues hacer un: cout << "Proceso" << random
	this->porcentajeDescuento = porcentajeDescuento;
}

inline Cupon::Cupon(string nombre, int porcentaje)
{
	this->nombre_str = nombre;  //se le pone un numero para despues hacer un: cout << "Proceso" << random
	this->porcentajeDescuento = porcentaje;
}


Cupon::~Cupon()
{
}

inline void Cupon::mostrar()
{
	stringstream* ss = new stringstream;

	if (nombre_int == 0)
	{
		*ss << this->nombre_str;
	}
	else {
		*ss << "\nCupon N° " << this->nombre_int;
	}
	*ss << "\nEste cupon da un " << this->porcentajeDescuento << "% de descuento";

	cout << ss->str();

	delete ss;
}
