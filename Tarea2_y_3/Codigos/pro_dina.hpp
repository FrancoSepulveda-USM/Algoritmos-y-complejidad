#include <vector>
#include "costos.hpp"
#include <iostream>
using namespace std;

/*
*Nombre: inicializarMatriz.
***
*Entrada: (string) s1-> Cadena 1.
*         (string) s2-> Cadena 2.
*         (int) n-> Largo cadena 1.
*         (int) m-> Largo cadena 2.
***
*Descripción: Inicializa la matriz utilizada para calcular la distancia mínima entre las dos cadenas siguiendo el enfoque bottom up,
por lo que inicializa el caso en que la cadena 1 es vacía, la cadena 2 es vacía y cuando ambas son vacias. 
***
*Return: (vector<vector<int>>) Matriz inicializada.
*/
vector<vector<int>> inicializarMatriz(string s1, string s2,int n, int m){
    vector<vector<int>> matriz(n+1,vector<int> (m+1));
    matriz[0][0]=0;
    //Inicializar la cadena0(la palabra que estará en la columna) 
    for(int i=1; i<n+1;i++){
        matriz[i][0]=matriz[i-1][0]+costo_del(s1[i-1]);//elimino la letra en la cadena0
    }
    //Inicializar valores de la fila, se pone con insert pq representa el costo de insertar en cadena0=''
    //para que sea igual a cadena1
    for(int i=1;i<m+1;i++){
        matriz[0][i]=matriz[0][i-1]+costo_ins(s2[i-1]);//Debo insertar la letra que esta en cadena1
    }
    return matriz;
}

/*
*Nombre: distanciaPD.
***
*Entrada: (string) s1-> Cadena 1.
*         (string) s2-> Cadena 2.
*         (int) n-> Largo cadena 1.
*         (int) m-> Largo cadena 2.
***
*Descripción: Calcula mediante enfoque bottom-up, siguiendo el paradigma de programación dinámica, la mínima distancia entre la 
cadena 1 con la cadena 2. Considera 4 operaciones(insertar, eliminar, sustituir y transponer) y también costos variables, 
accediendo a los costos de cada operación. 
***
*Return: (int) Distancia mínima entre s1 y s2.
*/
//A partir de resolver los subproblemas iniciales, al inicio de la matriz, se van resolviendo los otros.
//n: tamaño de s1; m:=tamaño s2.
int distanciaPD(string s1, string s2, int n,int m){
    //matriz donde se van guardando los valores.
    vector<vector<int>> matriz=inicializarMatriz(s1,s2,n,m);
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            //Esto lo estoy haciendo bajo la perspectiva de s1 en la matriz
            int costo_insertar = matriz[i][j-1] + costo_ins(s2[j-1]);//Tengo que insertar la letra que está en el cadena 2
            int costo_eliminar = matriz[i-1][j] + costo_del(s1[i-1]);//Costo de eliminar la ultima letra de el string
            int costo_sustituir = (s1[i-1]==s2[j-1]) ? matriz[i-1][j-1]+0:matriz[i-1][j-1]+costo_sub(s1[i-1],s2[j-1]); //Si las letras en los strings son iguales, no es necesario sustituir(costo=0), caso contrario se suma el costo. 
            int costo_transponer = INT_MAX;
            if(i>=2 && j>=2 && s1[i-1]==s2[j-2] && s1[i-2]==s2[j-1]){
                costo_transponer= matriz[i-2][j-2] + costo_trans(s1[i-1],s1[i-2]);
            }
            matriz[i][j]=min(min(costo_insertar,costo_eliminar),min(costo_sustituir,costo_transponer));
        }
    }
    return matriz[n][m];
}

//COMPLEJIDAD: TEMPORAL->O(N*M)  ESPACIO ADICIONAL->O(N+1*M+1)=O(N*M)
