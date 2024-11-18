#ifndef COSTOS_HPP
#define COSTOS_HPP
#include "globales.hpp"
int costo_sub(char a, char b){
    int pos_a=alfabeto[a],pos_b=alfabeto[b];
	return sustituir[pos_a][pos_b];
}

int costo_ins(char a){
    int pos_a=alfabeto[a];
	return insertar[pos_a];
}

int costo_del(char b){
    int pos_b=alfabeto[b];
	return deletear[pos_b];
}

int costo_trans(char a, char b){
	int pos_a=alfabeto[a],pos_b=alfabeto[b];
	return transponer[pos_a][pos_b];	
}

#endif // COSTOS_HPP