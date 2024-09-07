#include "sorts.hpp"
#include "matrices.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

/* printTiempo: Función que se encarga de escribir en un archivo csv llamado "tiempo_cuadradas.csv" los tiempos que demoran los algoritmos 
*  de multiplicacion de matrices al implementarlos en distintas matrices cuadradas de potencias de 2.
*   
* Parametro: 
*   duracion: Tiempo que demoró el algoritmo estandar de multiplicacion de matrices.
*   duracion1: Tiempo que demoró el algoritmo optimizado (con matriz transpuesta) de multiplicacion de matrices.
*   duracion2: Tiempo que demoró el algoritmo de Strassen.
*   tiempo: Archivo "tiempo_cuadradas.csv" donde se hará la tabla con los tiempos que demora cada algoritmo.
*   tamano: Cantidad de filas de matriz A. Al ser matrices cuadradas, tanto la primera matriz (A) como la segunda tienen
*   mismas dimensiones.
*
* Retorno: No tiene.
*/
void printTiempo(int duracion,int duracion1,int duracion2, ofstream &tiempo, int tamano){
    tiempo<<tamano<<","<<tamano*tamano<<","<<duracion<<","<<duracion1<<","<<duracion2<<"\n";
    tiempo.flush();
}


/* main: Declara y define variables a utilizar en el desarrollo del programa. Aparte utiliza un ciclo while donde se leerán las matrices 
*  almacenadas en el dataset "data_cuadradas.txt", en cada iteracion se leen dos matrices A y B, las cuales se mutiplicaran usando el
*  algoritmo estandar de multiplicacion de matrices, el optimizado (tranponiendo B) y el de Strassen. Para cada algoritmo se toma el 
*  tiempo que demora en ejecutarse y se procede a llamar a la funcion printTiempo para ir creando la tabla, con los tiempos que tomo cada algoritmo,
*  en el archivo de salida "tiempo_cuadradas.csv".
*
* Retorno: Retorna 0 una vez finalice el programa.
*/
int main(){
    int i=1;
    ofstream tiempo;
    ifstream archivo;
    std::vector<std::vector<int>> C;
    archivo.open("data_cuadradas.txt");
    tiempo.open("tiempo_cuadradas.csv");
    
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo data\n";
        exit(1);
    }
    if(tiempo.fail()){
        cout<<"No se pudo abrir el archivo salida\n";
        exit(1);
    }
    int filas,columnas;
    tiempo<<"Cant. Filas,Tamano(n*n),Estandar,Optimizada,Strassen\n";
    
    while(archivo>>filas>>columnas){ //En este caso son del mismo valor
        std::vector<std::vector<int>> A(filas, std::vector<int>(columnas));
        
        // Leer los elementos de la matriz A
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                archivo >> A[i][j];
            }
        }

        archivo>>filas>>columnas;
        std::vector<std::vector<int>> B(filas, std::vector<int>(columnas));

        // Leer los elementos de la matriz B
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                archivo >> B[i][j];
            }
        }

        //Normal
        auto start = std::chrono::high_resolution_clock::now();
        C=mul_matrices(A,B);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        //Optimizada
        auto start1 = std::chrono::high_resolution_clock::now();
        C=mul_matrices_opti(A,B);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
        
        //Strassen
        auto start2 = std::chrono::high_resolution_clock::now();
        C=multiply_matrix(A, B);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
        
        printTiempo(duration.count(),duration1.count(),duration2.count(),tiempo,filas);
    }
    archivo.close();
    tiempo.close();
    return 0;
}