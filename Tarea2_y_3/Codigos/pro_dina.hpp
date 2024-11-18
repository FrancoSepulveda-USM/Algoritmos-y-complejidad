#include <vector>
#include "costos.hpp"
#include <iostream>
using namespace std;

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

//A partir de resolver los subproblemas iniciales, al inicio de la matriz, se van resolviendo los otros.
//n: tamaño de s1; m:=tamaño s2.
int distanciaPD(string s1, string s2, int n,int m){
    //matriz donde se van guardando los valores.
    vector<vector<int>> matriz=inicializarMatriz(s1,s2,n,m);
    for(int i=1;i<n+1;i++){
        //recorrer columnas
        for(int j=1;j<m+1;j++){
            //Esto lo estoy haciendo bajo la perspectiva de s1 en la matriz
            int costo_insertar = matriz[i][j-1] + costo_ins(s2[j-1]);/*Tengo que insertar la letra que está en el cadena 2*/
            int costo_eliminar = matriz[i-1][j] + costo_del(s1[i-1]);//Costo de eliminar la ultima letra de el string
            int costo_sustituir = (s1[i-1]==s2[j-1]) ? matriz[i-1][j-1]+0:matriz[i-1][j-1]+costo_sub(s1[i-1],s2[j-1]); //Si las letras en los strings son iguales, no es necesario sustituir(costo=0), caso contrario se suma el costo. 
            int costo_transponer = INT_MAX;
            if(i>=2 && j>=2 && s1[i-1]==s2[j-2] && s1[i-2]==s2[j-1]){
                costo_transponer= matriz[i-2][j-2] + costo_trans(s1[i-1],s1[i-2]);
            }
            /*if(costo_sustituir<costo_insertar && costo_sustituir<costo_eliminar && costo_sustituir<costo_transponer ){
                cout<<"SUSTITUCION en s1: "<<s1[i-1]<<" s2: "<<s2[j-1]<<"\n";
            }*/
            //cout<<"costo insertar: "<<costo_insertar<<" costo eliminar: "<<costo_eliminar<<" costo transponer: "<<costo_transponer<<" costo sustituir: "<<costo_sustituir<<endl;
            matriz[i][j]=min(min(costo_insertar,costo_eliminar),/*costo_sustituir*/min(costo_sustituir,costo_transponer));
        }
    }
    return matriz[n][m];
}

//COMPLEJIDAD: TEMPORAL->O(N*M)  ESPACIO ADICIONAL->O(N+1*M+1)=O(N*M)
