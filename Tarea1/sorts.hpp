#include <iostream>
//#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 

/* sel_sort: Implementacion algoritmo de selection sort, recorre el vector con dos for de manera tal de ir comparando
*  cada elemento con todos los elementos del arreglo e ir ordenandolos a medida que los compara.
*
* Parámetros:
*   vector[]: arreglo de enteros a ordenar.
*   n: Cantidad elementos del vector
*
* Complejidad:
*   Peor caso: O(n^2)
*   Mejor caso: O(n^2)
*   Caso promedio: O(n^2)
*
* Retorno: No hay explicitamente ya que trabaja directamente con el vector.
*/
void sel_sort(int vector[], int n){
    for (int i = 0;i<n-1;i++){
        int m = i;
        for (int j=i+1; j<n; j++){
            if (vector[j]<vector[m]){
                m=j;
            }
        }
        int aux = vector[i];
        vector[i]=vector[m];
        vector[m]=aux;
    }
}

//-------------------------------------------------------------------------------

/*Merge sort
*Implementacion sacada de internet pero adaptada a arreglos, tanto la funcion merge como mergeSort
*Fuente: https://www.geeksforgeeks.org/cpp-program-for-merge-sort/
*/

/* merge: Compara los elementos del subarreglo izquierdo del vector con los elementos del subarreglo derecho del vector y 
* los va ordenando ascendentemente en el arreglo principal.
* 
*  Parámetros:
*   array[]: Vector principal donde se ordenarán los elementos.
*   left: Posicion primer elemento del arreglo.
*   mid: Posicion del elemento en mitad del arreglo.
*   right: Posicion ultimo elemento del arreglo.
*
* Retorno: Al trabajar directamente con el arreglo, no hay retorno.
*/
void merge(int array[], int const left, int const mid, int const right){

    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0; 

    int indexOfMergedArray = left; 

    
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = 
            leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = 
            rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = 
        leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = 
        rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}


/* mergeSort: Función que implementa el algoritmo Merge sort, calcula la posicion intermedia del arreglo y procede a llamarse 
* recursivamente primero pasando como parametros la mitad izquierda con la posicion de inicio y la posicion intermedia, 
* luego la mitad derecha con la posicion intermedia y la posicion final. Por ultimo llama a la funcion merge.
* 
* Parámetros:
*   array[]: arreglo de enteros a ordenar.
*   begin: posicion del primer elemento en el arreglo (0)
*   end: posicion del ultimo elemento en el arreglo
* 
* Complejidad:
*   Peor caso: O(n logn)
*   Mejor caso: O(n logn)
*   Caso promedio: O(n logn)
* 
* Retorno: Como tal no tiene ya que trabaja directamente con el arrglo pasado por parametro.
*/
void mergeSort(int array[], int const begin, int const end){
    
    if (begin >= end){
        return; 
    }
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

//----------------------------------------------------------------------------

/*Quick Sort
*Implementacion sacada de internet, incluye la implementacion de funcion swap, 
*partition2, la cual fue modificada para poner como pivot al elemento en la posicion media del arreglo, y quickSort.
*Fuente: https://www.programiz.com/dsa/quick-sort
*/

/* swap: Función auxiliar que intercambia los valores de a y b.
* 
* Parámetros:
*   a: Puntero a un entero que representa la primera variable a intercambiar.
*   b: Puntero a un entero que representa la segunda variable a intercambiar.
* 
* Retorno: No tiene.
*/
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

/* partition2: Función de particion que reorganiza los elementos del arreglo alrededor del pivot, posicionando 
*  los elementos menores o iguales a este al lado izquierdo y los mayores al lado derecho.
* 
* Parámetros:
*   array: Arreglo que se utiliza en el proceso de particion.
*   low: Posicion primer elemento del arreglo. 
*   high: Posicion ultimo elemento del arreglo.   
*
* Retorno: Retorna la posicion final del pivote en el arreglo, que es el índice donde todos los elementos
* a su izquierda son menores o iguales al pivot, y todos los de la derecha son mayores.
*/
int partition2(int array[], int low, int high) {
    
    int mid = low + (high - low) / 2;
    int pivot = array[mid];

    std::swap(array[mid], array[high]);

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);

    return (i + 1);
}

/* quickSort: Llama a la función de partición para dividir el arreglo en subarreglos y luego aplica recursivamente quickSort en cada 
*  subarreglo, ordenando así todo el arreglo.
* 
* Parámetros:
*   array: Arreglo que se utiliza en el proceso de particion.
*   low: Posicion primer elemento del arreglo. 
*   high: Posicion ultimo elemento del arreglo.   
*
* Complejidad:
*   Peor caso: O(n^2)
*   Mejor caso: O(n logn)
*   Caso promedio: O(n logn)
*
* Retorno: No tiene, ya que trabaja directamente con el arreglo pasado por parametro.
*/
void quickSort(int array[], int low, int high) {
    if (low < high) {

        int pi = partition2(array, low, high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
}

//---------------------------------------------------------------------------
/*Intro Sort
*Implementacion sacada de internet, incluye la implementacion de funcion swap_value, insetion_sort, Partition,
*MedianOfThree, introsort_util e intro_sort.
*Fuente: https://www.geeksforgeeks.org/introsort-cs-sorting-weapon/
*/

/* swap_value: Función auxiliar que intercambia los valores de a y b.
* 
* Parámetros:
*   a: Puntero a un entero que representa la primera variable a intercambiar.
*   b: Puntero a un entero que representa la segunda variable a intercambiar.
* 
* Retorno: No tiene.
*/
void swap_value(int *a, int *b) 
{ 
    int *temp = a; 
    a = b; 
    b = temp; 
    return; 
} 

/* insertion_sort: Función que ordena un arreglo utilizando el algoritmo de ordenamiento por inserción, para esto la funcion
*  recorre el subarreglo desde el segundo elemento hasta el último. Para cada elemento se selecciona como "clave" (key) y se 
*  compara con los elementos anteriores. Si un elemento es mayor que la clave, se desplaza una posición hacia adelante.
*  Una vez que se encuentra la posición correcta, la clave se inserta en su lugar.
*  Este proceso se repite hasta que todo el subarreglo está ordenado.
* 
* Parámetros:
*   arr: Arreglo de enteros que se desea ordenar.
*   begin: Puntero al primer elemento del subarreglo a ordenar.
*   end: Puntero al último elemento del subarreglo a ordenar.
* 
* Retorno: No tiene.
*/
void insertion_sort(int arr[], int *begin, int *end) 
{ 
    int left = begin - arr; 
    int right = end - arr; 

    for (int i = left+1; i <= right; i++) 
    { 
        int key = arr[i]; 
        int j = i-1; 

        /* Mover los elementos de arr[0..i-1] que son mayores que key
        una posición adelante de su posición actual */
        while (j >= left && arr[j] > key) 
        { 
            arr[j+1] = arr[j]; 
            j = j-1; 
        } 
        arr[j+1] = key; 
    } 

    return; 
} 

/* Partition: Función que particiona un arreglo en base a un pivote y devuelve el punto de partición.
* La función selecciona el último elemento del subarreglo como pivote y reorganiza los elementos
* de manera que todos los elementos menores o iguales al pivote estén a la izquierda del pivote,
* y todos los elementos mayores estén a la derecha. Luego coloca el pivote en su posición correcta 
* y devuelve un puntero al pivote, que ahora está en la posición de partición.
* 
* Parámetros:
*   arr: Arreglo de enteros a particionar.
*   low: Índice del primer elemento del subarreglo a particionar.
*   high: Índice del último elemento del subarreglo a particionar.
* 
* Retorno: Retorna el índice final del pivote en el arreglo, que es la posición en la que el pivote queda 
*   después de la partición.
*/
int* Partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 

    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            // increment index of smaller element 
            i++; 

            std::swap(arr[i], arr[j]); 
        } 
    } 
    std::swap(arr[i + 1], arr[high]); 
    return (arr + i + 1); 
} 


/* MedianOfThree: Función auxiliar que calcula la mediana de tres elementos.
* 
* Utilizada para seleccionar un buen pivote en el algoritmo de QuickSort, mejorando la eficiencia al 
* evitar seleccionar un pivote demasiado pequeño o grande, lo que podría llevar a un peor caso de O(n^2).
* 
* Parámetros:
*   a: Puntero al primer valor.
*   b: Puntero al segundo valor.
*   c: Puntero al tercer valor.
* 
* Retorno:
*   Un puntero al valor que representa la mediana de los tres valores proporcionados.
*/ 
int *MedianOfThree(int * a, int * b, int * c) { 
    if (*a < *b && *b < *c){
        return b; 
    }
    if (*a < *c && *c <= *b){
        return c; 
    }
    if (*b <= *a && *a < *c){ 
        return a; 
    }
    if (*b < *c && *c <= *a){ 
        return c; 
    }
    if (*c <= *a && *a < *b){ 
        return a; 
    }
    if (*c <= *b && *b <= *a){ 
        return b; 
    }
    return b;
} 

/* introsort_util: Función auxiliar que implementa el algoritmo Introsort mediante recursión 
* (se llama recursivamente para las particiones izquierda y derecha).
* 
* La función alterna entre tres algoritmos de ordenamiento: Insertion Sort, QuickSort, y HeapSort,
* dependiendo del tamaño del subarreglo y del límite de profundidad.
* - Si el tamaño del subarreglo es menor a 16 elementos, se utiliza Insertion Sort, ya que es 
*   más eficiente para subarreglos pequeños.
* - En caso contrario, se usaría QuickSort, pero si `depthLimit` llega a 0, se cambia a HeapSort 
*   para evitar el peor caso de QuickSort (O(n^2)) y garantizar un orden O(n log n).
* 
* Parámetros:
*   arr: Arreglo de enteros que se desea ordenar.
*   begin: Puntero al primer elemento del subarreglo a ordenar.
*   end: Puntero al último elemento del subarreglo a ordenar.
*   depthLimit: Índice que representa la cantidad máxima de recursiones permitidas con QuickSort 
*               antes de cambiar a HeapSort para evitar el peor caso de QuickSort.
* 
* Retorno: No tiene.
*/
void introsort_util(int arr[], int * begin, 
                  int * end, int depthLimit) 
{ 
    // Count the number of elements 
    int size = end - begin; 

      // If partition size is low then do insertion sort 
    if (size < 16) 
    { 
        insertion_sort(arr, begin, end); 
        return; 
    } 

    // If the depth is zero use heapsort 
    if (depthLimit == 0) 
    { 
        std::make_heap(begin, end+1); 
        std::sort_heap(begin, end+1); 
        return; 
    } 

    // Else use a median-of-three concept to 
    // find a good pivot 
    int * pivot = MedianOfThree(begin, begin+size/2, end); 

    // Swap the values pointed by the two pointers 
    swap_value(pivot, end); 

   // Perform Quick Sort 
    int * partitionPoint = Partition(arr, begin-arr, end-arr); 
    introsort_util(arr, begin, partitionPoint-1, depthLimit - 1); 
    introsort_util(arr, partitionPoint + 1, end, depthLimit - 1); 

    return; 
} 

/*intro_sort: Función principal que primero calcula el limite de profundidad (dephtlimith), este servirá 
* para calcular la cantidad maxima de recursiones que se pueden hacer con QuickSort antes de cambiar 
* HeapSort. Esto se hace para evitar un orden  O(n^2) en el peor caso QuickSort y garantizar 
* un orden O(n log n) al cambiar a HeapSort.
* Luego llamará a una funcion auxiliar "introsort_util" para hacer la implementacion de IntroSort. 
* 
* Parámetros:
*   arr: Arreglo de enteros que se desea ordenar.
*   begin: Puntero al primer elemento del subarreglo a ordenar.
*   end: Puntero al último elemento del subarreglo a ordenar.
* 
* Retorno: No tiene.
*/
void intro_sort(int arr[], int *begin, int *end) 
{ 
    int depthLimit = 2 * log(end-begin); 

    // Perform a recursive Introsort 
    introsort_util(arr, begin, end, depthLimit); 

    return; 
} 
