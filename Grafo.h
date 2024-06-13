#include <vector>
using namespace std;

template<class T, T vacio = -1>
class Grafo {

private:
	class Arco {
	public:
		T info;
		int v; //indice del vertice de llegada
		Arco(int vLlegada) {
			info = vacio;
			v = vLlegada;
		}
	};
	class Vertice {
	public:
		T info;
		vector<Arco*>* ady; //Lista de adyacencia
		Vertice() {
			info = vacio;
			ady = new vector<Arco*>();
		}
	};
	//Lista de vértices
	vector<Vertice*>* vertices;

public:
	Grafo() {
		vertices = new vector<Vertice*>();
	}

	//Operaciones del Grafo
	int adicionarVertice(T info) {
		Vertice* vert = new Vertice();
		vert->info = info;
		vertices->push_back(vert);
		return vertices->size() - 1;
	}

	int cantidadVertices() {
		return vertices->size();
	}

	T obtenerVertice(int v) {
		return (vertices->at(v))->info;
	}
	void modificarVertice(int v, T info) {
		(vertices->at(v))->info = info;
	}
	//Operaciones del arco
	int adicionarArco(int v, int vLlegada) {
		Vertice* ver = vertices->at(v);
		//Crear el objeto ARCO
		Arco* arc = new Arco(vLlegada);
		ver->ady->push_back(arc);
		return ver->ady->size() - 1;
	}

	int cantidadArcos(int v) {
		return (vertices->at(v))->ady->size();
	}

	T obtenerArco(int v, int apos) {
		Vertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->info;
	}

	void modificarArco(int v, int apos, T info) {
		Vertice* ver = vertices->at(v);
		(ver->ady->at(apos))->info = info;
	}

	int obtenerVerticeLlegada(int v, int apos) {
		Vertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->v; //indice del vertice de llegada
	}
};