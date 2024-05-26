#pragma once
#include <functional>
#include "Lista_Medicamentos.h"
using namespace std;

template<class T>
void Merge(Lista_Medicamentos<T>* listaIzquierda, 
           Lista_Medicamentos<T>* listaDerecha, 
           Lista_Medicamentos<T>* listaFinal, 
           function<void(T, T)> cb) 
    {
    auto it1 = listaIzquierda->begin();
    auto it2 = listaDerecha->begin();

    while (it1 != listaIzquierda->end() && it2 != listaDerecha->end()) {
        T* temp1 = it1;
        T* temp2 = it2;

        if (cb(temp1, temp2) {
            listaFinal->agregaFinal(temp1);
            ++it1;
        }
        else {
            listaFinal->agregaFinal(temp2);
            ++it2;
        }
    }

    while (it1 != listaIzquierda->end()) {
        listaFinal->agregaFinal(it1);
        ++it1;
    }

    while (it2 != listaDerecha->end()) {
        listaFinal->agregaFinal(*it2);
        ++it2;
    }
}

template<class T>
void mergeSort(Lista_Medicamentos<T>* lst, function<void(T, T)> cb) {
    // Caso base: si la lista tiene 0 o 1 elemento, está ordenada
    if (lst->get_lon() <= 1) {
        return;
    }

    // Dividir la lista en mitades
    int mitad = lst->get_lon() / 2;
    Lista_Medicamentos<T>* listaIzquierda = new Lista_Medicamentos<T>;
    Lista_Medicamentos<T>* listaDerecha = new Lista_Medicamentos<T>;

    auto it = lst->begin();
    for (int i = 0; i < mitad; ++i) {
        listaIzquierda->agregaFinal(*it);
        ++it;
    }

    for (int i = mitad; i < lst->longitud(); ++i) {
        listaDerecha->agregaFinal(*it);
        ++it;
    }

    // Llamar recursivamente a mergeSort para ordenar las sublistas
    mergeSort(listaIzquierda);
    mergeSort(listaDerecha);

    // Fusionar las sublistas ordenadas para formar la lista final ordenada
    lst->borrarTodo();
    Merge(listaIzquierda, listaDerecha, lst, cb);

    // Liberar memoria
    delete listaIzquierda;
    delete listaDerecha;
}