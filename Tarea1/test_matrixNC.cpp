#include "sorts.hpp"
#include "matrices.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;

/* printTiempo: Función que se encarga de escribir en un archivo csv llamado "tiempo_nocuadradas.csv" los tiempos que demoran los algoritmos 
*  de multiplicacion de matrices al implementarlos en distintas matrices de diferentes dimensiones, dentro se crea una variable long long int
*  para prevenir el overflow al calcular el tamaño m x n x p, donde m es la cantidad de filas de la primera matriz, n la cantidad de columnas 
*  de la primera matriz y tambien la cantidad de filas de la segunda matriz y p es la cantidad de columnas de la segunda matriz. 
*   
* Parametro: 
*   duracion: Tiempo que demoró el algoritmo estandar de multiplicacion de matrices.
*   duracion1: Tiempo que demoró el algoritmo optimizado (con matriz transpuesta) de multiplicacion de matrices.
*   tiempo: Archivo "tiempo_nocuadradas.csv" donde se hara la tabla con los tiempos que demora cada algoritmo.
*   f1: Cantidad de filas de la matriz A, donde la multiplicacion de matrices sería: A x B.
*   c1: Cantidad de columnas de la matriz A (debe ser igual al tamaño fila matriz B).
*   c2: Cantidad de columnas matriz B.
*
* Retorno: No tiene.
*/
void printTiempo(int duracion,int duracion1, ofstream &tiempo, int f1, int c1, int c2){
    long long int F1 = f1, C1 = c1, C2 = c2;

    // Verificación de desbordamiento antes de realizar la multiplicación
    if (F1 > 0 && C1 > 0 && C2 > 0 &&
        F1 <= std::numeric_limits<long long int>::max() / C1 &&
        F1 * C1 <= std::numeric_limits<long long int>::max() / C2) {
        
        long long int tam = F1 * C1 * C2;
        tiempo << f1 << "," << c1 << "," << c2 << "," << tam << "," << duracion << "," << duracion1 << "\n";
    } else {
        // Si hay riesgo de desbordamiento, imprime un mensaje de error o un valor predeterminado
        tiempo << f1 << "," << c1 << "," << c2 << "," << "OVERFLOW" << "," << duracion << "," << duracion1 << "\n";
    }

    tiempo.flush();
}


/* main: Declara y define variables a utilizar en el desarrollo del programa. Aparte utiliza un ciclo while donde se leerán las matrices 
*  almacenadas en el dataset "data_nocuadradas.txt", en cada iteracion se leen dos matrices A y B, las cuales se mutiplicaran usando el
*  algoritmo estandar de multiplicacion de matrices y el optimizado (tranponiendo B). Para cada algoritmo se toma el tiempo que demora en 
*  ejecutarse y se procede a llamar a la funcion printTiempo para ir creando la tabla con los tiempos que tomo cada algoritmo.
*
* Retorno: Retorna 0 una vez finalice el programa.
*/
int main(){
    int i=1;
    ofstream tiempo;
    ifstream archivo;
    std::vector<std::vector<int>> C;
    
    archivo.open("data_nocuadradas.txt");
    tiempo.open("tiempo_nocuadradas.csv");
    
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo data\n";
        exit(1);
    }
    if(tiempo.fail()){
        cout<<"No se pudo abrir el archivo salida\n";
        exit(1);
    }
    
    long long int fila1,columna1,fila2,columna2;//fila2=columna1
    
    tiempo<<"Fila A(m),Col.A/FilaB(n),Col.B(p),Tamano(m x n x p),Estandar,Optimizada\n"; //m es la fila 1, n es la columna 1 y fila 2(son iguales) y p es la columna 2->Resultado final: m*l
    
    while(archivo>>fila1>>columna1){ //En este caso son del mismo valor
        std::vector<std::vector<int>> A(fila1, std::vector<int>(columna1));
        
        // Leer los elementos de la matriz A
        for (int i = 0; i < fila1; ++i) {
            for (int j = 0; j < columna1; ++j) {
                archivo >> A[i][j];
            }
        }

        archivo>>fila2>>columna2;
        std::vector<std::vector<int>> B(fila2, std::vector<int>(columna2));

        // Leer los elementos de la matriz V
        for (int i = 0; i < fila2; ++i) {
            for (int j = 0; j < columna2; ++j) {
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
        
        printTiempo(duration.count(),duration1.count(),tiempo,fila1,columna1,columna2);
    }
    archivo.close();
    tiempo.close();
    return 0;
}