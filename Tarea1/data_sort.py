import random

'''generate_random_list: Funcion que crea una lista entera de tamaño 'size' y almacena nros aleatorios entre 1 y 1000.
- Parametros:
-   size: tamaño de la lista.
- Retorno: Lista de tamaño 'size' con elementos enteros escogidos aleatoriamente entre 1 y 1000
'''
def generate_random_list(size):
    return [random.randint(1, 1000) for _ in range(size)]


'''generate_sorted_list: Funcion que crea una lista entera de tamaño 'size' ordenada ascendentemente.
- Parametros:
-   size: tamaño de la lista.
- Retorno: Lista de tamaño 'size' con elementos ordenados ascendentemente.
'''
def generate_sorted_list(size):
    return list(range(1, size + 1))

'''generate_reversed_list: Funcion que crea una lista entera de tamaño 'size' ordenada descendentemente.
- Parametros:
-   size: tamaño de la lista.
- Retorno: Lista de tamaño 'size' con elementos ordenados descendentemente.
'''
def generate_reversed_list(size):
    return list(range(size, 0, -1))

'''generate_partially_sorted_list: Funcion que crea una lista entera de tamaño 'size' mitad ordenada, mitad desordenada.
- Parametros:
-   size: tamaño de la lista.
- Retorno: Lista de tamaño 'size' con elementos ordenados ascendentemente hasta la mitad y la otra mitad desordenados.
'''
def generate_partially_sorted_list(size):
    # Crear una lista ordenada de 1 a size
    lst = list(range(1, size + 1))
    
    # Dividir la lista en dos mitades
    mid = size // 2
    
    # Mantener la primera mitad ordenada
    first_half = lst[:mid]
    
    # Desordenar la segunda mitad
    second_half = lst[mid:]
    random.shuffle(second_half)
    
    # Combinar ambas mitades
    partially_sorted_list = first_half + second_half
    return partially_sorted_list


'''generate_mixed_list: Funcion que crea una lista entera de tamaño 'size' y almacena nros aleatorios entre -1000 y 1000.
- Parametros:
-   size: tamaño de la lista.
- Retorno: Lista de tamaño 'size' con elementos enteros escogidos aleatoriamente entre -1000 y 1000
'''
def generate_mixed_list(size):
    return [random.randint(-1000, 1000) for _ in range(size)]

'''data_sort: Función que escribe en un archivo.txt(dataset) una lista, en la primera linea escribe el tamaño de la lista
-  y en la segunda linea escribe los elementos de la lista separados por un espacio.
- Parametros:
-   archivo: Archivo donde se escribirá la lista.
-   arr: Lista que se escribirá en el archivo.
- Retorno: No hay.
'''
def data_sort(archivo,arr):    
    archivo.write(str(len(arr))+"\n")
    for il in arr:
        archivo.write(str(il)+" ")     
    archivo.write("\n")

#Lista con los distintos tamaños que tomaran las listas.
lista=[10,50,100,200,300,500,1000,5000,10000,15000,25000,50000,75000,100000,150000,200000,250000,350000,500000,650000]        

#---------------------------------------------------------------
#Creacion archivo con listas ordenadas

archivo = open("data_sorted.txt", "w")
i=0
o=1

'''While que se encargara de llamar a funcion generate_sorted_list y data_sort para escribir en un archivo llamado "data_sorted.txt"(dataset)
20 listas ordenadas ascendentemente de distinto tamaño'''
while i<20: 
    size=lista[i]
    data_sort(archivo,generate_sorted_list(size))
    i+=1
    

archivo.close()

#--------------------------------------------------------------
#Creacion archivo de listas con elementos aleatorios
archivo = open("data_sort_random.txt", "w")
i=0

'''While que se encargara de llamar a funcion generate_sorted_list y data_sort para escribir en un archivo llamado "data_sort_random.txt"(dataset)
20 listas con elementos aleatorios, se intercalan, es decir, primero se imprime una lista con elementos aleatorios positivos y luego una 
con elementos aleatorios positivos y negativos y asi seguiria la secuencia hasta escribir 20 listas en total de distinto tamaño'''
while i<20: 
    size=lista[i]
    i+=1
    data_sort(archivo,generate_random_list(size))
    size=lista[i]
    data_sort(archivo,generate_mixed_list(size))
    i+=1
    

archivo.close()

#--------------------------------------------------------------------------------
#Creacion archivo de listas ordenadas descendentemente
archivo = open("data_sort_reversed.txt", "w")
i=0
o=1

'''While que se encargara de llamar a funcion generate_sorted_list y data_sort para escribir en un archivo llamado "data_sort_reversed.txt"(dataset)
20 listas ordenadas descendentemente de distinto tamaño'''
while i<20: 
    size = lista[i]
    data_sort(archivo,generate_reversed_list(size))
    i+=1
    


archivo.close()

#--------------------------------------------------------------------------
#Creacion archivo con listas parcialmente ordenadas
archivo = open("data_sort_parcial.txt", "w")
i=0

'''While que se encargara de llamar a funcion generate_sorted_list y data_sort para escribir en un archivo llamado "data_sort_parcial.txt"(dataset)
20 listas con la mitad izquierda ordenadas y la mitad derecha desordenadas, cada una de distinto tamaño'''
while i<20: 
    size = lista[i]
    data_sort(archivo,generate_partially_sorted_list(size))
    i+=1
    

archivo.close()


