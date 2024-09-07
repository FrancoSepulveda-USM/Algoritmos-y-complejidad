import random

"""generate_matrix: Genera una matriz de dimensiones rows x cols con valores aleatorios entre 1 y 150.
*
*  Parametros:
*   rows: Numero de filas de la matriz.
*   cols: Numero de columnas de la matriz.
"""
def generate_matrix(rows, cols):
    return [[random.randint(1, 150) for _ in range(cols)] for _ in range(rows)]

"""write_matrices_to_file: Escribe una matriz en un archivo, en el archivo escribe la matriz con el siguiente formato:
*  En la primera linea escribe el numero de filas y columnas separadas por un espacio, luego en la segunda linea procede a imprimir
*  la matriz en orden rows * cols.
*
*  Parametros:
*   f: Archivo.txt(dataset) donde se escribirá la matriz.
*   matrix: Matriz a escribir en el dataset.
"""
def write_matrices_to_file(f, matrix):
    rows = len(matrix)
    cols = len(matrix[0]) if rows > 0 else 0
    f.write(f"{rows} {cols}\n")
    for row in matrix:
        f.write(" ".join(map(str, row)) + "\n")


if __name__ == "__main__":
    #GENERACION DE MATRICES CUADRADAS DE POTENCIAS DE 2
    
    i=0 #Define cuantos pares de matrices se escribirán en el dataset
    contador=0 #Utilizado para hacer 2 pares de matrices por cada potencia de 2
    n = 1 #Numero por el que se elevara el 2.
    
    f=open("data_cuadradas.txt",'w')
    
    '''While encargado de llamar a las funciones generate_matrix y write_matrices_to_file con distintos parametros 
    para crear y escribir las matrices cuadradas de potencia de 2 en el archivo "data_cuadradas.txt". Genera en total 32 matrices,
    16 matrices A y 16 matrices B'''
    while i<10: 
        
        #Matriz A
        matriz = generate_matrix(2**n,2**n)
        write_matrices_to_file(f, matriz)
        
        #Matriz B
        matriz = generate_matrix(2**n,2**n)
        write_matrices_to_file(f, matriz)
        
        n+=1
        i+=1
        
    
    #--------------------------------------------------------------
    #MATRICES DE DISTINTA DIMENSION
    i=0
    inf = 2  #limite inferios
    sup = 4 #limite superior para rango de nros
    
    f=open("data_nocuadradas.txt",'w')
    

    '''While encargado de llamar a las funciones generate_matrix y write_matrices_to_file con distintos parametros 
    para crear y escribir las matrices de distinta dimension, que cumplan orden n*m y m*k, en el archivo "data_nocuadradas.txt". 
    Genera 40 matrices en total'''
    while i<20:
        
        n = random.randint(inf, sup)
        m = random.randint(inf,sup)
        #Matriz A
        matriz = generate_matrix(n,m)
        write_matrices_to_file(f, matriz)
        #Matriz B
        k = random.randint(inf,sup)
        matriz = generate_matrix(m,k)
        write_matrices_to_file(f, matriz)
        # Guardar matrices en archivo
        if i==2:
            inf+=2
            sup+=4
        elif i%2==1:
            inf*=2
            sup*=2
        
        i+=1
    
f.close()