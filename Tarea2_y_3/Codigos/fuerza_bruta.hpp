#include <iostream>
#include <vector>
#include "costos.hpp"
using namespace std;

/*
*Nombre: distanciaFB.
***
*Entrada: (string) s1-> Cadena 1.
*         (string) s2-> Cadena 2.
*         (int) n-> Largo cadena 1.
*         (int) m-> Largo cadena 2.
***
*Descripción: Calcula mediante recursiones, siguiendo el paradigma de fuerza bruta, la mínima distancia entre la 
cadena 1 con la cadena 2. Considera 4 operaciones(insertar, eliminar, sustituir y transponer) y también costos variables, 
accediendo a los costos de cada operación. 
***
*Return: (int) Distancia mínima entre s1 y s2.
*/
int distanciaFB(string s1,string s2,int n,int m){
    if(n==0){
        int costo=0; //retornar el costo de insertar hasta j veces la letra s2[j-1].
        for(int i=0;i<m;i++){
            costo+=costo_ins(s2[i]);
        }
        return costo;//calcula el costo total de insertar m letras para convertir la cadena vacia a m
    }
    if(m==0){
        int costo=0; //retornar el costo de insertar hasta j veces la letra s2[j-1].
        for(int i=0;i<n;i++){
            costo+=costo_del(s1[i]);
        }
        return costo;
    }
    if(s1[n-1]==s2[m-1]){//iguales no suma nada
        return distanciaFB(s1,s2,n-1,m-1);
    }
    int costo_insertar = distanciaFB(s1,s2,n,m-1)+costo_ins(s2[m-1]);
    int costo_delete = distanciaFB(s1,s2,n-1,m)+costo_del(s1[n-1]);
    int costo_sustituir = distanciaFB(s1,s2,n-1,m-1)+costo_sub(s1[n-1],s2[m-1]);
    int costo_transponer = INT_MAX;
    if(s1[n-1]==s2[m-2] && s1[n-2]==s2[m-1] && n>1 && m>1){
        costo_transponer = distanciaFB(s1,s2,n-2,m-2)+ costo_trans(s1[n-1], s1[n-2]);
    }
    return min(min(costo_insertar,costo_delete),/*costo_sustituir*/min(costo_sustituir,costo_transponer));
}

/*TEMPORAL: O(4^max(n,m)) ESPACIAL: O(N+M)*/