#include <iostream>
#include <vector>
#include <fstream>
#include "globales.hpp"

using namespace std;

/*
*Nombre: leer_insertar.
***
*Entrada: No tiene
***
*Descripción: Lee el archivo que contiene el vector de costos de la operación insertar.
***
*Return: No tiene.
*/
void leer_insertar(){
    ifstream ins("cost_insert.txt");

    // Verificar apertura de archivos
    if (!ins.is_open()) {
        cerr << "Error al abrir el archivo cost_replace.txt" << endl;
        return; // Indica un error
    }
    for(int i=0;i<26;i++){
        if (!(ins >> insertar[i])) {
            cerr << "Error: el archivo cost_replace.txt no contiene 26 números en la fila " << i + 1 << endl;
            return;
        }
    }
    ins.close();
}


/*
*Nombre: leer_delete.
***
*Entrada: No tiene
***
*Descripción: Lee el archivo que contiene el vector de costos de la operación eliminar.
***
*Return: No tiene.
*/
void leer_delete(){
    ifstream del("cost_delete.txt");

    // Verificar apertura de archivos
    if (!del.is_open()) {
        cerr << "Error al abrir el archivo cost_replace.txt" << endl;
        return; // Indica un error
    }
    for(int i=0;i<26;i++){
        if (!(del >> deletear[i])) {
            cerr << "Error: el archivo cost_replace.txt no contiene 26 números en la fila " << i + 1 << endl;
            return;
        }
    }
    del.close();
}


/*
*Nombre: leer_sustituir.
***
*Entrada: No tiene
***
*Descripción: Lee el archivo que contiene la matriz de costos de la operación sustituir.
***
*Return: No tiene.
*/
void leer_sustituir(){
    ifstream sub("cost_replace.txt");

    // Verificar apertura de archivos
    if (!sub.is_open()) {
        cerr << "Error al abrir el archivo cost_replace.txt" << endl;
        return; // Indica un error
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (!(sub >> sustituir[i][j])) {
                cerr << "Error: el archivo cost_replace.txt no contiene 26 números en la fila " << i + 1 << endl;
                sub.close();
                return;
            }
        }
    }
    //cout<<"Leido exitosamente sustituir"<<endl;
    sub.close();
}


/*
*Nombre: leer_transponer.
***
*Entrada: No tiene
***
*Descripción: Lee el archivo que contiene la matriz de costos de la operación transponer.
***
*Return: No tiene.
*/
void leer_transponer(){
    ifstream transpose("cost_transpose.txt");
    if (!transpose.is_open()) {
        cerr << "Error al abrir el archivo cost_transpose.txt" << endl;
        return; // Indica un error
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (!(transpose >> transponer[i][j])) {
                cerr << "Error: el archivo cost_transpose.txt no contiene 26 números en la fila " << i + 1 << endl;
                transpose.close();
                return;
            }
        }
    }
    //cout<<"Leido exitosamente transponer"<<endl;
    transpose.close();
}