mas_usadas = {'e','t','a','o','i','n','s','r','h','l'}#letras mas usadas en el ingles
alfabeto=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
vocales = {'a', 'e', 'i', 'o', 'u'}
consonantes = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'}

def insert_delete():
    # Abre dos archivos al mismo tiempo
    with open('cost_insert.txt', 'w') as insert, open('cost_delete.txt', 'w') as delete:
        for i in range(26):
            if alfabeto[i] in mas_usadas:#Las letras mas usadas valen menos.
                delete.write('1')
                insert.write('1')
            else:
                delete.write('2')
                insert.write('2')
            delete.write(" ")
            insert.write(" ")
            
def sub_trans():
    with open("cost_replace.txt", 'w') as replace, open("cost_transpose.txt", 'w') as transpose:
        for i in range(26):
            for j in range(26):
                if alfabeto[i] == alfabeto[j]:  # Letras iguales
                    replace.write('0 ')
                    transpose.write('0 ')
                elif (alfabeto[i] in vocales and alfabeto[j] in vocales):  # Vocal + Vocal
                    replace.write('1 ')
                    transpose.write('1 ')
                elif (alfabeto[i] in consonantes and alfabeto[j] in consonantes):  # Consonante + Consonante
                    replace.write('1 ')
                    transpose.write('1 ')
                elif (alfabeto[i] in vocales and alfabeto[j] in consonantes) or (alfabeto[i] in consonantes and alfabeto[j] in vocales):  # Vocal + Consonante o Consonante + Vocal
                    replace.write('2 ')
                    transpose.write('2 ')
                    
            # Añadir salto de línea al final de cada fila
            replace.write('\n')
            transpose.write('\n')
if __name__ == "__main__":
    insert_delete()
    sub_trans()