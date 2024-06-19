#pragma once
#include <vector>
#include "Cupon.h"
using namespace std;

class CuponGenerator
{
public:
	CuponGenerator();
	~CuponGenerator();
	void crearValores();
	void crearCupon();

private:
	int elSuperNumero = 1;  //para que no se repitan los numeros
	vector<Cupon> cupones;
};

CuponGenerator::CuponGenerator()
{
    crearValores();
}

CuponGenerator::~CuponGenerator()
{
}

inline void CuponGenerator::crearValores()
{
    Random r;
    int cantidad = r.Next(10, 21);

    for (int i = 0; i < cantidad; i++)
    {
        Cupon* cupon = new Cupon(elSuperNumero);
        elSuperNumero++;
		cupones.push_back(*cupon);

        delete cupon;
    }
}

inline void CuponGenerator::crearCupon()
{
    Console::Clear();
    cout << "\nIngrese el nombre del cupon: ";
    string nombre;
    cin >> nombre;

    cout << "\nIngrese el porcentaje de descuento: ";
    int descuento;
    cin >> descuento;
    Cupon* cupon = new Cupon(nombre, descuento);
    cupones.push_back(*cupon);

	delete cupon;
}
