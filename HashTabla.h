#pragma once
#include <vector>
#include <list>
#include <string>
#include "Entidad.h"

#include <iostream>
using namespace std;

template <typename Key, typename Value>
class HashTabla {
private:
	vector<list<Entidad<Key, Value>>> listas;   // Tabla
	int  tamanoActual;

public:
	explicit HashTabla(int size = 150) : tamanoActual{ 0 }
	{
		listas.resize(150);
	}

	void makeEmpty()
	{
		for (auto& thisList : listas)
			thisList.clear();
	}

	bool insert(Entidad<Key, Value>&& x)
	{
		int hash = myhash(x.getKey());
		auto& whichList = listas[hash]; //Obtenemos la lista de elementos segun el hash obtenido

		/*
			Cambio de lugar
		*/
		for (auto& it : whichList) {
			if (it.getKey() == x.getKey()) {
				whichList = listas[min(int(listas.size() - 1), max(0, hash - (rand() % 4 + 1)))];

				if (max(0, hash - (rand() % 4 + 1)) <= 0) {
					whichList = listas[min(int(listas.size() - 1), hash + (rand() % 4 + 1))];
				}
				break;
			}
		}

		whichList.push_back(x); //Agregamos el nuevo elemento a la lista

		return true;
	}

	void DispAll() {
		int pos = 0;
		for (auto& thisList : listas) {
			cout << "Key: " + to_string(pos) << " -> ";
			for (auto& it : listas[pos]) {
				cout << it.getKey() << (pos + 1 < thisList.size() ? "," : "");
			}
			cout << endl;
			pos++;
		}
	}

private:

	int myhash(Key key) const {
		int hash = key * 1 / 8;

		hash %= listas.size();
		return(hash);
	}
};


