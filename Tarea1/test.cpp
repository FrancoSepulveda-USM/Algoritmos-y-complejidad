#include "sorts.hpp"
#include "matrices.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;


/* printTiempo: Función que se encarga de escribir en un archivo csv llamado "tiempo_sort.csv" los tiempos que demoran los algoritmos para cada
* dataset de listas.
*   
* Parametro: 
*   duracion: Tiempo que demoró el algoritmo de Selection Sort.
*   duracion1: Tiempo que demoró el algoritmo de Merge Sort.
*   duracion2: Tiempo que demoró el algoritmo de Quick Sort.    
*   duracion3: Tiempo que demoró el algoritmo de Intro Sort
*   tiempo: Archivo "tiempo_sort.csv" donde se haran las tablas con los tiempos que demora cada algoritmo.
*
* Retorno: No tiene.
*/
void printTiempo(int duracion,int duracion1,int duracion2,int duracion3, ofstream &tiempo, int tamano){
    tiempo << tamano<<","<<duracion<<","<<duracion1<<","<<duracion2<<","<<duracion3<<"\n";
    tiempo.flush();
}


/* abrir_archivos: Se encarga de abrir todos los datasets y los archivos de salida que se utilizaran a lo largo del codigo.
*   
* Parametro: 
*   tiempo: Archivo de salida .csv, donde se escribirán las tablas con los tiempos.
*   sorted: Dataset que se leerá que almacena las listas ordenadas ascendentemente.    
*   random: Dataset que se leerá que almacena las listas desordenadas. 
*   parcial: Dataset que se leerá que almacena las listas parcialmente ordenadas. 
*   reverse: Dataset que se leerá que almacena las listas ordenadas descendentemente. 
*
* Retorno: No tiene.
*/
void abrir_archivos(ofstream &tiempo, ifstream &sorted, ifstream &random, ifstream &parcial, ifstream &reverse){
    
    sorted.open("data_sorted.txt"); //Para abrir el archivo de listas ordenadas
    tiempo.open("tiempo_sort.csv"); //Escribir en archivo csv los tiempos
    random.open("data_sort_random.txt"); //Archivo listas random
    parcial.open("data_sort_parcial.txt");//archivo listas paracialmente ordenadas
    reverse.open("data_sort_reversed.txt"); //archivo listas ordenadas descendentemente
    
    if(sorted.fail()){
        cout<<"No se pudo abrir el archivo data\n";
        exit(1);
    }
    if(tiempo.fail()){
        cout<<"No se pudo abrir el archivo salida\n";
        exit(1);
    }
    if(random.fail()){
        cout<<"No se pudo abrir el archivo random\n";
        exit(1);
    }
    if(parcial.fail()){
        cout<<"No se pudo abrir el archivo parcial\n";
        exit(1);
    }
    if(reverse.fail()){
        cout<<"No se pudo abrir el archivo reverse\n";
        exit(1);
    }
}

/* main: Función principal que declara las variables a utilizar en el desarrollo del programa, gestiona las llamadas a las funciones de 
* creación de archivos y apertura de archivos. Aparte en esta se hacen 4 bucles while distintos, donde en cada bucle se abre un dataset
* distinto de las listas que se utilizan para la exprimentacion. Entonces en el primer bucle se abre el dataset de las listas ordenadas
* y los tiempos se escriben en el archivo de salida "tiempo_sort.csv", en el proximo while se abre el dataset de listas desordenas y los
* tiempos se escriben en el mismo archivo de salida "tiempo_sort.csv". Los otros dos whiles hacen lo mismo pero cada uno abriendo uno de
* los dos datasets restantes.  Recalcar que todos los tiempos se escriben en el mismo archivo de salida, por lo que se harán 4 tablas 
* en total.
*    
* Retorno: Retorna 0 una vez finalice el programa.
*/
int main(){
    int i=1;
    ofstream tiempo;
    ifstream sorted, random, parcial, reverse;
    abrir_archivos(tiempo,sorted,random,parcial,reverse);
    
    int tamano;

    //-----------------------------------------------------------------------------------
    //Leer archivos con listas ordenadas (ascendentemente).
    tiempo<<"Sorted Lists\n";
    tiempo<<"Tamano,Selection Sort,Merge Sort,Quick Sort,Intro Sort\n";
    
    while(sorted>>tamano){
        
        int * principal = new int[tamano];
        int * selec = new int[tamano];
        int * merge = new int[tamano];
        int * quick = new int[tamano];
        int * intro = new int[tamano];
        for (int i = 0; i < tamano; i++){
            sorted >> principal[i];
        }
        //cout << "LISTA: ";
        for (int i = 0; i<tamano; i++){
            selec[i]=principal[i];
            merge[i]=principal[i];
            quick[i]=principal[i];
            intro[i]=principal[i];
        }
        
        //Selection sort
        auto start = std::chrono::high_resolution_clock::now();
        sel_sort(selec,tamano);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        
        //MergeSort
        auto start1 = std::chrono::high_resolution_clock::now();
        mergeSort(merge,0,tamano-1);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);

        
        //QuickSort
        auto start2 = std::chrono::high_resolution_clock::now();
        quickSort(quick,0,tamano-1);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

        //IntroSort
        auto start3 = std::chrono::high_resolution_clock::now();
        intro_sort(intro,intro,intro+tamano-1);
        auto end3 = std::chrono::high_resolution_clock::now();
        auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);

        printTiempo(duration.count(),duration1.count(),duration2.count(),duration3.count(),tiempo,tamano);
        
        delete [] principal;
        delete [] selec;
        delete [] merge;
        delete [] quick;
        delete [] intro;
    }
    sorted.close();
    tiempo<<"\n";

    //-----------------------------------------------------------------------------------
    //Leer archivos con listas desordenadas.
    tiempo<<"Random Lists\n";
    tiempo<<"Tamano,Selection Sort,Merge Sort,Quick Sort,Intro Sort\n";

    //Random
    while(random>>tamano){
        
        int * principal = new int[tamano];
        int * selec = new int[tamano];
        int * merge = new int[tamano];
        int * quick = new int[tamano];
        int * intro = new int[tamano];
        for (int i = 0; i < tamano; i++){
            random >> principal[i];
        }

        for (int i = 0; i<tamano; i++){
            selec[i]=principal[i];
            merge[i]=principal[i];
            quick[i]=principal[i];
            intro[i]=principal[i];
        }
        
        //Selection sort
        auto start = std::chrono::high_resolution_clock::now();
        sel_sort(selec,tamano);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        //MergeSort
        auto start1 = std::chrono::high_resolution_clock::now();
        mergeSort(merge,0,tamano-1);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
        
        //QuickSort
        auto start2 = std::chrono::high_resolution_clock::now();
        quickSort(quick,0,tamano-1);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

        //IntroSort
        auto start3 = std::chrono::high_resolution_clock::now();
        intro_sort(intro,intro,intro+tamano-1);
        auto end3 = std::chrono::high_resolution_clock::now();
        auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);

        //Salida orden

        printTiempo(duration.count(),duration1.count(),duration2.count(),duration3.count(),tiempo,tamano);
        
        delete [] principal;
        delete [] selec;
        delete [] merge;
        delete [] quick;
        delete [] intro;
    }
    random.close();
    tiempo<<"\n";

    //-----------------------------------------------------------------------------------
    //Leer archivos con listas parcialmente ordenadas, mitad ordenada y mitad desordenada.
    tiempo<<"Partial Lists\n";
    tiempo<<"Tamano,Selection Sort,Merge Sort,Quick Sort,Intro Sort\n";

    while(parcial>>tamano){
        
        int * principal = new int[tamano];
        int * selec = new int[tamano];
        int * merge = new int[tamano];
        int * quick = new int[tamano];
        int * intro = new int[tamano];
        for (int i = 0; i < tamano; i++){
            parcial >> principal[i];
        }
        
        for (int i = 0; i<tamano; i++){           
            selec[i]=principal[i];
            merge[i]=principal[i];
            quick[i]=principal[i];
            intro[i]=principal[i];
        }
        
        
        //Selection sort
        auto start = std::chrono::high_resolution_clock::now();
        sel_sort(selec,tamano);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        //MergeSort
        auto start1 = std::chrono::high_resolution_clock::now();
        mergeSort(merge,0,tamano-1);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
        
        
        //QuickSort
        auto start2 = std::chrono::high_resolution_clock::now();
        quickSort(quick,0,tamano-1);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

        //IntroSort
        auto start3 = std::chrono::high_resolution_clock::now();
        intro_sort(intro,intro,intro+tamano-1);
        auto end3 = std::chrono::high_resolution_clock::now();
        auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);

        printTiempo(duration.count(),duration1.count(),duration2.count(),duration3.count(),tiempo,tamano);
        
        delete [] principal;
        delete [] selec;
        delete [] merge;
        delete [] quick;
        delete [] intro;
    }
    parcial.close();
    tiempo<<"\n";

    //-----------------------------------------------------------------------------------
    //Leer archivos con listas ordenadas descendentemente.
    tiempo<<"Reversed Lists\n";
    tiempo<<"Tamano,Selection Sort,Merge Sort,Quick Sort,Intro Sort\n";

    //Reverse
    while(reverse>>tamano){
        
        int * principal = new int[tamano];
        int * selec = new int[tamano];
        int * merge = new int[tamano];
        int * quick = new int[tamano];
        int * intro = new int[tamano];
        for (int i = 0; i < tamano; i++){
            reverse >> principal[i];
        }
        
        for (int i = 0; i<tamano; i++){
            selec[i]=principal[i];
            merge[i]=principal[i];
            quick[i]=principal[i];
            intro[i]=principal[i];
        }
        
        
        //Selection sort
        auto start = std::chrono::high_resolution_clock::now();
        sel_sort(selec,tamano);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        //MergeSort
        auto start1 = std::chrono::high_resolution_clock::now();
        mergeSort(merge,0,tamano-1);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
        
        //QuickSort
        auto start2 = std::chrono::high_resolution_clock::now();
        quickSort(quick,0,tamano-1);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

        //IntroSort
        auto start3 = std::chrono::high_resolution_clock::now();
        intro_sort(intro,intro,intro+tamano-1);
        auto end3 = std::chrono::high_resolution_clock::now();
        auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);

        printTiempo(duration.count(),duration1.count(),duration2.count(),duration3.count(),tiempo,tamano);
        
        delete [] principal;
        delete [] selec;
        delete [] merge;
        delete [] quick;
        delete [] intro;
    }
    reverse.close();
    tiempo.close();
    return 0;
}