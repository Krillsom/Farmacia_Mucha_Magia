#pragma once
#include "Almacen.h"
#include "Caja.h"
#include "Medicamento.h"

using namespace System;

class Tienda
{
public:
	Tienda();
	~Tienda();
	void menu();
private:
	Almacen<Medicamento<float>>* objAlmacen = new Almacen<Medicamento<float>>();
	Caja<int>* objCaja = new Caja<int>();
};

Tienda::Tienda()
{
}

Tienda::~Tienda()
{
}

void gotoxy(int x, int y) {
	Console::SetCursorPosition(x, y);
}

inline void Tienda::menu()
{
	Console::Clear;
	Console::SetWindowSize(130, 50);
	string indicador = "=>";
	gotoxy(3, 3); cout <<  R"(    ______                                _                   __  ___           __             __  ___            _          )";
	gotoxy(3, 4); cout <<  R"(   / ____/___ __________ ___  ____ ______(_)___ _     __     /  |/  /_  _______/ /_  ____ _   /  |/  /___ _____ _(_)___ _    )";
	gotoxy(3, 5); cout <<  R"(  / /_  / __ `/ ___/ __ `__ \/ __ `/ ___/ / __ `/  __/ /_   / /|_/ / / / / ___/ __ \/ __ `/  / /|_/ / __ `/ __ `/ / __ `/    )";
	gotoxy(3, 6); cout <<  R"( / __/ / /_/ / /  / / / / / / /_/ / /__/ / /_/ /  /_  __/  / /  / / /_/ / /__/ / / / /_/ /  / /  / / /_/ / /_/ / / /_/ /     )";
	gotoxy(3, 7); cout << R"(/_/    \__,_/_/  /_/ /_/ /_/\__,_/\___/_/\__,_/    /_/    /_/  /_/\__,_/\___/_/ /_/\__,_/  /_/  /_/\__,_/\__, /_/\__,_/      )";
	gotoxy(3, 8); cout <<  R"(                                                                                                        /____/               )";
	gotoxy(3, 9); cout << R"(-----------------------------------------------------------------------------------------------------------------------------)";
}







/*

void mostrar_menu() {
	definir_pantalla();
	string indicador = "=>";
	short opcion = 1;
	int x = WIDTH / 2 - 15, baseY = HEIGHT / 2 - 11 / 2, y;
	y = baseY + 7 + opcion - 1;

	Console::Clear();

	mostrar_titulo(WIDTH / 2 - 57.5, baseY);
	gotoxy(x, baseY + 6); cout << "   " << "---------------";
	Console::ForegroundColor = ConsoleColor::Cyan;
	gotoxy(x, baseY + 7); cout << indicador << " ";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Iniciar juego";
	gotoxy(x, baseY + 8); cout << "   " << "Introducciones";
	gotoxy(x, baseY + 9); cout << "   " << "Configuraci" << char(162) << "n";
	gotoxy(x, baseY + 10); cout << "   " << "Salir";

	gotoxy(WIDTH / 2 - 40, baseY + 11); cout << "   " << "Mueve con las flechas direcciones [" << char(24) << "," << char(25) << "] y presione enter para elejir la opci" << char(162) << "n";

	while (1) {
		if (_kbhit()) {
			char caracter = _getch();
			if (caracter == arriba) {
				gotoxy(x, y);
				cout << "   ";
				opcion--;
				y--;
				if (opcion < 1) {
					y = baseY + 10;
					opcion = 4;
				};
				gotoxy(x, y);
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << indicador;
			}
			if (caracter == abajo) {
				gotoxy(x, y);
				cout << "   ";
				opcion++;
				y++;
				if (opcion > 4) {
					y = baseY + 7;
					opcion = 1;
				};
				gotoxy(x, y);
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << indicador;
			}
			else if (caracter == enter) {
				Console::ForegroundColor = ConsoleColor::White;
				break;
			};
		}
	}
	

	if (opcion == 1) {
		juego();
		Console::Clear();
		mostrar_menu();
	}
	if (opcion == 2) {
		mostrar_instrucciones();
		Console::Clear();
		mostrar_menu();
	}
	if (opcion == 3) {
		pintar_configuracion(volumen_sonido_mapa);
		Console::Clear();
		mostrar_menu();
	}
	if (opcion == 4) {
		string message = "Ohhh, hasta luego :')";
		Console::Clear();
		gotoxy(WIDTH / 2 - message.length() / 2, HEIGHT / 2);
		for (int i = 0; i < message.length(); i++) {
			cout << message[i];
			_sleep(100);
		}
		exit(0);
	}
}

*/


