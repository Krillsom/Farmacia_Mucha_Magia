#pragma once
#include "Proveedor.h"
#include "Lista_Medicamentos.h"

template <class T>
class Almacen
{
private:
	Proveedor<T>* proveedor;
	Lista_Medicamentos<T> unalista;

public:
	Almacen();
	~Almacen();

	void registrarPedido();
	void mostrarPedidos();
	void elegirOpcion();
	void mostrarBotones();
	void agregarInicioLista(T obj);
	T getElementoLista(int n);
	void mostrarOpcion(string* message, int x, bool activado = false);
};

template<class T>
inline void Almacen<T>::agregarInicioLista(T obj)
{
	unalista.agregaInicial(obj);
}

template<class T>
inline T Almacen<T>::getElementoLista(int n)
{

	return unalista.obtenerPos(n);
}

template <class T>
Almacen<T>::Almacen()
{
	this->proveedor = new Proveedor<T>;
}

template <class T>
Almacen<T>::~Almacen()
{
	delete proveedor;
}

template<class T>
inline void Almacen<T>::mostrarPedidos()
{
	gotoxy(getXCenter(105), Console::WindowTop + 1); cout << R"(    ____  __________  ________  ____  _____    ____  _______   ______  ___________   ___________________)";
	gotoxy(getXCenter(105), Console::WindowTop + 2); cout << R"(   / __ \/ ____/ __ \/  _/ __ \/ __ \/ ___/   / __ \/ ____/ | / / __ \/  _/ ____/ | / /_  __/ ____/ ___/)";
	gotoxy(getXCenter(105), Console::WindowTop + 3); cout << R"(  / /_/ / __/ / / / // // / / / / / /\__ \   / /_/ / __/ /  |/ / / / // // __/ /  |/ / / / / __/  \__ \)";
	gotoxy(getXCenter(105), Console::WindowTop + 4); cout << R"( / ____/ /___/ /_/ // // /_/ / /_/ /___/ /  / ____/ /___/ /|  / /_/ // // /___/ /|  / / / / /___ ___/ /)";
	gotoxy(getXCenter(105), Console::WindowTop + 5); cout << R"(/_/   /_____/_____/___/_____/\____//____/  /_/   /_____/_/ |_/_____/___/_____/_/ |_/ /_/ /_____//____/)";


	proveedor->forEach([](T t) {
		t.mostrar(9);
		});

	int base_buttons = 9 + proveedor->size() * 3;

	mostrarBotones();

	elegirOpcion();
}

template<class T>
inline void Almacen<T>::registrarPedido()
{
	string temp_Name = "";
	int temp_cantidad = 0;

	cout << "\n\nIngrese el nombre de la medicina: ";
	cin >> temp_Name;
	cout << "\n\nIngrese la cantidad a pedir: ";
	cin >> temp_cantidad;

	proveedor->agregarPedido(temp_Name, temp_cantidad);
}

template<class T>
inline void Almacen<T>::elegirOpcion()
{
	int opcion = 0;

	while (1) {
		if (_kbhit()) {
			char tecla = _getch();
			if (tecla == 75) {
				opcion--;
				if (opcion < 0) opcion = 1;
			}
			else if (tecla == 77) {
				opcion++;
				if (opcion > 1) opcion = 0;
			}

			if (tecla == 75 || tecla == 77) {
				mostrarOpcion(new string("Volver al men" + string(1, 163)),
					getXCenter(37), opcion == 0);

				mostrarOpcion(new string("Recibir pedido"),
					getXCenter(37) + 19, opcion == 1);
			}

			if (tecla == 13) break;
		}
	}

	if (opcion == 0) {
		// Volver al menu
	}
	else if (opcion == 1) {
		// Recibir el pedido
	}
}

template<class T>
inline void Almacen<T>::mostrarBotones()
{

	int x = getXCenter(37);

	string* message = new string("Volver al men" + string(1, 163));

	mostrarOpcion(message, x, true);
	x += message->length() + 5;

	*message = "Recibir pedido";
	mostrarOpcion(message, x);

	delete message;
}

template<class T>
inline void Almacen<T>::mostrarOpcion(string* message, int x, bool activado = false)
{
	if (activado) color(ConsoleColor::Cyan);
	else color(ConsoleColor::White);

	gotoxy<short>(x, Console::WindowHeight - 3);

	cout << char(201);
	for (short i = 0; i < message->length() + 2; i++) cout << char(205);
	cout << char(187);

	gotoxy<short>(x, Console::WindowHeight - 2);

	cout << char(186) << " " << *message << " " << char(186);

	gotoxy<short>(x, Console::WindowHeight - 1);

	cout << char(200);
	for (short i = 0; i < message->length() + 2; i++) cout << char(205);
	cout << char(188);

	if (activado) color(ConsoleColor::White);

}