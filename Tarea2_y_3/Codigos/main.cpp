#include <iostream>
#include <vector>
#include "pro_dina.hpp"
#include "fuerza_bruta.hpp"
#include "globales.hpp"
#include "archivos.hpp"
#include <chrono>
#include <fstream>
using namespace std;

map<char, int> alfabeto = {{'a', 0},{'b', 1},{'c', 2},{'d', 3},{'e', 4},{'f', 5},{'g', 6},{'h', 7},{'i', 8},{'j', 9},
    {'k', 10},{'l', 11},{'m', 12},{'n', 13},{'o', 14},{'p', 15},{'q', 16},{'r', 17},{'s', 18},{'t', 19},{'u', 20},
    {'v', 21},{'w', 22},{'x', 23},{'y', 24},{'z', 25}};
vector<vector<int>> transponer(26, vector<int>(26)), sustituir(26, vector<int>(26));
vector<int> insertar(26),deletear(26);

/*
*Nombre: inicializar.
***
*Entrada: No tiene.
***
*Descripción: Inicializa las variables globales utilizando las funciones encargadas de leer los archivos txt que contienen los
*costos de cada operación. 
***
*Return: No tiene.
*/
void inicializar(){
    leer_insertar();
    leer_delete();
    leer_sustituir();
    leer_transponer();
}

/*
*Nombre: printTiempos.
***
*Entrada: (ofstream) tiempos->Archivo donde se guardaran los tiempos de ejecución de los algoritmos.
*         (string) s1->Cadena 1.
*         (string) s2->Cadena 2.
*         (int) n->Largo cadena 1.
*         (int) m->Largo cadena 2.
*         (double) duracion1->tiempo de ejecución del algoritmo de programación dinámica para la cadena 1 y la cadena 2 (en microsegundos).
*         (double) duracion2->tiempo de ejecución del algoritmo de fuerza bruta para la cadena 1 y la cadena 2 (en microsegundos).
***
*Descripción: Imprime en un archivo csv los tiempos de ejecución de cada algoritmo bajo las cadenas 1 y 2. 
***
*Return: No tiene.
*/
void printTiempos(ofstream &tiempos, string s1, string s2, int n, int m, double duracion1, double duracion2){
    if(n==0){
        s1 = "VACIO";
    }

    if(m==0){
        s2= "VACIO";
    }
    tiempos<<n<<","<<s1<<","<<m<<","<<s2<<","<<duracion1<<","<<duracion2<<"\n";
}

/*
*Nombre: leer_archivo.
***
*Entrada: (ofstream) tiempos->Archivo donde se guardaran los tiempos de ejecución de los algoritmos.
*         (ifstream) archivo->Archivo desde donde se leeran los datos provenientes de los datasets.
***
*Descripción: Lee los datos de un archivo txt(datasets), una vez obtenidos los datos, llama a las funciones que calculan las distancia minima
y calcula el tiempo de ejecucion de cada algoritmo. 
***
*Return: No tiene.
*/
void leer_archivo(ifstream &archivo, ofstream &tiempos){
    int n,m;
    string s1,s2;
    while (archivo >> n >>m){
        archivo.ignore();
        getline(archivo,s1);
        getline(archivo,s2);
        archivo.ignore();
        //cout << "n: " << n << ", m: " << m << endl;
        //cout << "s1: \"" << s1 << "\", s2: \"" << s2 << "\"" << endl;
        
        auto start = std::chrono::high_resolution_clock::now();
        int costo = distanciaPD(s1,s2,n,m);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration<double,std::micro>(end - start);  // Usar double para obtener decimales
        cout <<"Costo PD: "<< costo << " Duracion: " << duration1.count() << " microsegundos. ";

        start = std::chrono::high_resolution_clock::now();
        costo = distanciaFB(s1,s2,n,m);
        end = std::chrono::high_resolution_clock::now();
         auto duration2 = std::chrono::duration<double,std::micro>(end - start);  // Usar double para obtener decimales
        cout <<"Costo FB: "<< costo << " Duracion: " << duration2.count() << " microsegundos." << endl;
        printTiempos(tiempos,s1,s2,n,m,duration1.count(),duration2.count());
    }
    
        
}

int main(){
    ifstream archivo1("datasets1.txt");
    ifstream archivo2("datasets2.txt");
    ifstream archivo3("datasets3.txt");
    ifstream archivo4("datasets4.txt");
    ifstream archivo5("datasets5.txt");
    ifstream archivo6("datasets6.txt");
    ofstream tiempos("Tiempos.csv");
    if(!archivo1.is_open()){
        cerr << "Error al abrir el archivo 1" << endl;
        return 1;
    }
    if(!archivo2.is_open()){
        cerr << "Error al abrir el archivo 2" << endl;
        return 1;
    }
    if(!archivo3.is_open()){
        cerr << "Error al abrir el archivo 3" << endl;
        return 1;
    }
    if(!archivo4.is_open()){
        cerr << "Error al abrir el archivo 4" << endl;
        return 1;
    }
    if(!archivo5.is_open()){
        cerr << "Error al abrir el archivo 5" << endl;
        return 1;
    }
    if(!archivo6.is_open()){
        cerr << "Error al abrir el archivo 6" << endl;
        return 1;
    }
    if(!tiempos.is_open()){
        cerr << "Error al abrir el archivo csv" << endl;
        return 1;
    }
    inicializar();//Inicializar variables globales(tablas de costos)

    cout<<"LEYENDO DATASET1"<<endl;
    tiempos<<"CADENAS VACÍAS\n";
    tiempos<<"Tamano s1, Cadena 1, Tamano s2, Cadena 2, tiempoDP[µs], tiempoFB[µs]\n";
    //Lee el dataset 1
    leer_archivo(archivo1,tiempos);
    tiempos<<"\n";
    tiempos<<"\n";

    //dataset2
    cout<<"LEYENDO DATASET2"<<endl;
    tiempos<<"CADENAS IDENTICAS\n";
    tiempos<<"Tamano s1, Cadena 1, Tamano s2, Cadena 2, tiempoDP[µs], tiempoFB[µs]\n";
    leer_archivo(archivo2,tiempos);
    tiempos<<"\n";
    tiempos<<"\n";

    //dataset3
    cout<<"LEYENDO DATASET3"<<endl;
    tiempos<<"CADENAS REPETITIVAS\n";
    tiempos<<"Tamano s1, Cadena 1, Tamano s2, Cadena 2, tiempoDP[µs], tiempoFB[µs]\n";
    leer_archivo(archivo3,tiempos);
    tiempos<<"\n";
    tiempos<<"\n";

    //dataset4
    cout<<"LEYENDO DATASET4"<<endl;
    tiempos<<"CADENAS DE IGUAL TAMANO\n";
    tiempos<<"Tamano s1, Cadena 1, Tamano s2, Cadena 2, tiempoDP[µs], tiempoFB[µs]\n";
    leer_archivo(archivo4,tiempos);
    tiempos<<"\n";
    tiempos<<"\n";

    //dataset5
    cout<<"LEYENDO DATASET5"<<endl;
    tiempos<<"CADENAS DE DISTINTO TAMANO\n";
    tiempos<<"Tamano s1, Cadena 1, Tamano s2, Cadena 2, tiempoDP[µs], tiempoFB[µs]\n";
    leer_archivo(archivo5,tiempos);
    tiempos<<"\n";
    tiempos<<"\n";

    //dataset6
    cout<<"LEYENDO DATASET6"<<endl;
    tiempos<<"CADENAS CON TRANSPOSICIONES\n";
    tiempos<<"Tamano s1, Cadena 1, Tamano s2, Cadena 2, tiempoDP[µs], tiempoFB[µs]\n";
    leer_archivo(archivo6,tiempos);
    tiempos<<"\n";
    
    archivo1.close();
    archivo2.close();
    archivo3.close();
    archivo4.close();
    archivo5.close();
    archivo6.close();
    tiempos.close();
    return 0;
}