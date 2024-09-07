#include <iostream>
//#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
#include <string>

using namespace std;

//Multiplicacion estandar
/* mul_matrices: Algoritmo estándar de multiplicación de matrices, utiliza 3 for anidados y se encarga de multiplicar
*  la matriz A con la matriz B, siempre y cuando las dimensiones de ambas matrices permitan multiplicarlas.
*  El resultado se almacena en una matriz C.
* 
* Parámetros:
*   A: Matriz de enteros que representa la primera matriz a multiplicar.
*   B: Matriz de enteros que representa la segunda matriz a multiplicar.    
*
* Complejidad:
*   Peor caso: O(n^3)
*   Mejor caso: O(n^3)
*
* Retorno: Matriz resultante de la multiplicacion entre matriz A y matriz B.
*/
vector<vector<int>> mul_matrices(vector<vector<int>> A, vector<vector<int>> B){
    
    int filaA=A.size();
    int columnaA=A[0].size();
    int filaB = B.size();
    int columnaB = B[0].size();

    if (columnaA != filaB){
        throw std::invalid_argument("Dimensiones Invalidas");
    }

    vector<vector<int>> C(filaA,vector<int>(columnaB,0));

    for (int i=0;i<filaA;i++){
        for (int j=0;j<columnaB;j++){
            for (int k=0;k<columnaA;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    return C;
} 

//-------------------------------------------------------------------------

//Multiplicacion con matriz transpuesta
/* transpuesta: Función auxiliar que transpone la matriz pasada por parametro, intercambiando filas por columnas.
* 
* Parámetros:
*   B: Matriz de enteros.    
*
* Retorno: Una nueva matriz que es la transpuesta de la matriz B, es decir, la matriz donde los elementos 
*          en la fila i y columna j de B se encuentran en la fila j y columna i en la matriz resultante.
*/
vector<vector<int>> transpuesta(vector<vector<int>> B){
    int fila = B.size();
    int columnas = B[0].size();
    vector<vector<int>> BT(columnas,vector<int>(fila));
    for (int i=0;i<fila;i++){
        for (int j=0;j<columnas;j++){
            BT[j][i]=B[i][j];
        }
    }
    return BT;
}

/* mul_matrices_opti: Algoritmo optimizado de multiplicación de matrices que realiza la multiplicación
*  de la matriz A con la transpuesta de la matriz B, siempre y cuando las dimensiones de ambas matrices permitan multiplicarlas.
* 
* Parámetros:
*   A: Matriz de enteros que representa la primera matriz a multiplicar.
*   B: Matriz de enteros que representa la matriz que se va a transponer y luego multiplicar con A.    
*
* Complejidad:
*   Peor caso: O(n^3)
*   Mejor caso: O(n^3)
*
* Retorno: Matriz resultante de la multiplicacion de la matriz A con la matriz transpuesta de B.
*/
vector<vector<int>> mul_matrices_opti(vector<vector<int>> A, vector<vector<int>> B){
    
    int filaA=A.size();
    int columnaA=A[0].size();
    int filaB = B.size();
    int columnaB = B[0].size();

    if (columnaA != filaB){
        throw std::invalid_argument("Dimensiones Invalidas");
    }

    vector<vector<int>> BT(columnaB,vector<int>(filaB));

    BT = transpuesta(B);
    vector<vector<int>> C(filaA,vector<int>(columnaB,0));

    for (int i=0;i<filaA;i++){
        for (int j=0;j<columnaB;j++){
            for (int k=0;k<columnaA;k++){
                C[i][j]+=A[i][k]*BT[j][k];
            }
        }
    }

    return C;
} 

//------------------------------------------------------

/*Strassen
*Implementacion sacada de internet, solo funciona para matrices cuadradas con dimensiones de potencia de 2.
*Fuente: https://www.geeksforgeeks.org/cpp-program-for-merge-sort/
*/

/* add_matrix: Suma dos matrices de enteros de igual tamaño y almacena el resultado en una tercera matriz.
* 
* Parámetros:
*   matrix_A: Matriz de enteros que representa la primera matriz a sumar.
*   matriz_B: Matriz de enteros que representa la segunda matriz a sumar.    
*   matrix_C: Matriz de enteros donde se almacenará el resultado de la suma entre A y B.
*   split_index: Tamaño de las submatrices que se están sumando. Se usa para definir el tamaño de la matriz resultante.  
*
* Retorno: No tiene, el resultado se almacena directamente en la matriz C.
*/
void add_matrix(vector<vector<int> > matrix_A, vector<vector<int> > matrix_B, vector<vector<int> >& matrix_C,int split_index){
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}

/* multiply_matrix: Algoritmo de multiplicación de matrices utilizando el algoritmo de Strassen.
*  Realiza la multiplicación de la matriz A con la matriz B. Para eso divide las matrices en submatrices
*  y aplica multiplicación de matrices recursiva, optimizando el proceso mediante la reducción de la cantidad de multiplicaciones.
*  La implementacion esta hecha solo para matrices cuadradas donde la dimensión sea potencia de 2.
* 
* Parámetros:
*   matrix_A: Matriz de enteros que representa la primera matriz a multiplicar.
*   Matriz_B: Matriz de enteros que representa la segunda matriz a multiplicar.    
*
* Complejidad:
*   Peor caso: O(n^2.81)
*   Mejor caso: O(n^2.81)
*
* Retorno: Matriz resultante de la multiplicacion de la matriz A con la matriz B.
*/
vector<vector<int>> multiply_matrix(vector<vector<int> > matrix_A, vector<vector<int> > matrix_B){
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if (col_1 != row_2) {
        cout << "\nError: The number of columns in Matrix "
                "A  must be equal to the number of rows in "
                "Matrix B\n";
        return {};
    }

    // Inicializa la matriz resultante con ceros
    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int> > result_matrix(row_1,
                                    result_matrix_row);

    // Caso base: multiplicación de matrices 1x1
    if (col_1 == 1)
        result_matrix[0][0]
            = matrix_A[0][0] * matrix_B[0][0];
    else {
        int split_index = col_1 / 2; // Dividir la matriz en submatrices de tamaño reducido

        // Inicializa las submatrices
        vector<int> row_vector(split_index, 0);
        vector<vector<int> > result_matrix_00(split_index,
                                            row_vector);
        vector<vector<int> > result_matrix_01(split_index,
                                            row_vector);
        vector<vector<int> > result_matrix_10(split_index,
                                            row_vector);
        vector<vector<int> > result_matrix_11(split_index,
                                            row_vector);

        vector<vector<int> > a00(split_index, row_vector);
        vector<vector<int> > a01(split_index, row_vector);
        vector<vector<int> > a10(split_index, row_vector);
        vector<vector<int> > a11(split_index, row_vector);
        vector<vector<int> > b00(split_index, row_vector);
        vector<vector<int> > b01(split_index, row_vector);
        vector<vector<int> > b10(split_index, row_vector);
        vector<vector<int> > b11(split_index, row_vector);

        // Llena las submatrices con los valores correspondientes de las matrices originales
        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index]
                                    [j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index]
                                    [j + split_index];
            }

         // Realiza las multiplicaciones y sumas utilizando las submatrices
        add_matrix(multiply_matrix(a00, b00),
                multiply_matrix(a01, b10),
                result_matrix_00, split_index);
        add_matrix(multiply_matrix(a00, b01),
                multiply_matrix(a01, b11),
                result_matrix_01, split_index);
        add_matrix(multiply_matrix(a10, b00),
                multiply_matrix(a11, b10),
                result_matrix_10, split_index);
        add_matrix(multiply_matrix(a10, b01),
                multiply_matrix(a11, b11),
                result_matrix_11, split_index);

        // Combina los resultados parciales en la matriz final
        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                result_matrix[i][j]
                    = result_matrix_00[i][j];
                result_matrix[i][j + split_index]
                    = result_matrix_01[i][j];
                result_matrix[split_index + i][j]
                    = result_matrix_10[i][j];
                result_matrix[i + split_index]
                            [j + split_index]
                    = result_matrix_11[i][j];
            }

        // Limpia las matrices temporales para liberar memoria
        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;
}

