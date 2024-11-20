#ifndef COSTOS_HPP
#define COSTOS_HPP
#include "globales.hpp"

/*
*Nombre: costo_sub.
***
*Entrada: (char) a-> Un caracter cualquiera(perteneciente al alfabeto ingles y en minuscula).
*         (char) b-> Un caracter cualquiera(perteneciente al alfabeto ingles y en minuscula).
***
*Descripción: Accede a la variable global que almacena los costos de sustituir una letra por otra,
por lo que calcula el costo de sustituir la letra a por la letra b. 
***
*Return: (int) Costo de sustituir letra a por letra b.
*/
int costo_sub(char a, char b){
    int pos_a=alfabeto[a],pos_b=alfabeto[b];
	return sustituir[pos_a][pos_b];
}

/*
*Nombre: costo_ins.
***
*Entrada: (char) a-> Un caracter cualquiera(perteneciente al alfabeto ingles y en minuscula).
***
*Descripción: Accede a la variable global que almacena los costos de insertar una letra,
por lo que calcula el costo de inserta la letra a. 
***
*Return: (int) Costo de insertar la letra a.
*/
int costo_ins(char a){
    int pos_a=alfabeto[a];
	return insertar[pos_a];
}

/*
*Nombre: costo_del.
***
*Entrada: (char) a-> Un caracter cualquiera(perteneciente al alfabeto ingles y en minuscula).
***
*Descripción: Accede a la variable global que almacena los costos de eliminar una letra,
por lo que calcula el costo de eliminar la letra a. 
***
*Return: (int) Costo de eliminar la letra a.
*/
int costo_del(char b){
    int pos_b=alfabeto[b];
	return deletear[pos_b];
}

/*
*Nombre: costo_trans.
***
*Entrada: (char) a-> Un caracter cualquiera(perteneciente al alfabeto ingles y en minuscula).
*         (char) b-> Un caracter cualquiera(perteneciente al alfabeto ingles y en minuscula).
***
*Descripción: Accede a la variable global que almacena los costos de transponer una letra por otra,
por lo que calcula el costo de transponer la letra a por la letra b. 
***
*Return: (int) Costo de transponer letra a por letra b.
*/
int costo_trans(char a, char b){
	int pos_a=alfabeto[a],pos_b=alfabeto[b];
	return transponer[pos_a][pos_b];	
}

#endif // COSTOS_HPP