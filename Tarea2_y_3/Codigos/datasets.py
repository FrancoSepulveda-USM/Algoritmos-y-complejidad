import random
import string

alfabeto=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

def generar_cadenas_distintas_distinto_tamano(minimo,maximo):#cadenas distintas
    rango1 = random.randint(minimo,maximo)#Escoge un numero entre 0 y la longitud para s1
    rango2 = random.randint(minimo,maximo)#Escoge un numero entre 0 y la longitud para s2
    cadena = []
    s1 = ""
    s2 = ""
    #print("tamaño s1: ",rango1, "tamaño s2", rango2)
    for _ in range(rango1):
        s1 += random.choice(alfabeto)
    for _ in range(rango2):
        s2 += random.choice(alfabeto)
    cadena.append(s1)
    cadena.append(s2)
    return cadena
def generar_cadena(minimo,maximo):
    rango1 = random.randint(minimo,maximo)
    s = ""
    for _ in range(rango1):
        s+=random.choice(alfabeto)
    return [''.join(s)]

def generar_cadenas_distintas_mismo_tamano(minimo,maximo):#cadenas distintas mismo tamano
    rango1 = random.randint(minimo,maximo)
    cadena=[]
    s1=""
    s2=""
    for _ in range(rango1):
        s1 += random.choice(alfabeto)
        s2 += random.choice(alfabeto)
    cadena.append(s1)
    cadena.append(s2)
    return cadena
    
def generar_cadenas_identicas(minimo,maximo):#cadenas iguales
    rango1 = random.randint(minimo,maximo)
    cadena=[]
    s1=""
    s2=""
    for _ in range(rango1):
        s1 += random.choice(alfabeto)
    s2=s1
    cadena.append(s1)
    cadena.append(s2)
    return cadena
    
def generar_cadenas_parecidas_mismo_tamano(minimo,maximo):#Esta bien, cambia 3 caracteres
    rango1 = random.randint(minimo,maximo)
    cadena=[]
    s1=""
    s2=""
    for _ in range(rango1):
        s1 += random.choice(alfabeto)#Genera cadena aleatoria
    
    s2=list(s1)
    
    ind = random.randint(0,len(s2)-1)
    for _ in range(ind):#Hace "ind" cambios de caracter
        ran = random.randint(0,len(s2)-1)
        nuevo_caracter = random.choice(alfabeto)
        while nuevo_caracter==s2[ran]:    
            nuevo_caracter = random.choice(alfabeto)
        s2[ran]=nuevo_caracter
        
    s2=''.join(s2)
    cadena.append(s1)
    cadena.append(s2)
    return cadena
    
def generar_cadenas_parecidas_distinto_tamano(minimo,maximo):#Esta bien, cambia 3 caracteres
    rango1 = random.randint(minimo,maximo)
    cadena=[]
    s1=""
    s2=""
    for _ in range(rango1):
        s1 += random.choice(alfabeto)#Genera cadena aleatoria
    
    s2=list(s1)
    #largo = len(s2)
    cambio = random.choice([-1,1])
    
    if cambio==-1:#Elimino
        eliminar = random.randint(1,5)
        s2=s2[:len(s2)-eliminar]
    else:#Agrando
        agrandar = random.randint(1,5)
        s2+=(random.choice(alfabeto) for _ in range(agrandar))
    if len(s2)>1:
        ind = random.randint(0,len(s2)-1)
    else:
        ind = 0
    for _ in range(ind):#Hace "ind" cambios de caracter
        ran = random.randint(0,len(s2)-1)
        nuevo_caracter = random.choice(alfabeto)
        while nuevo_caracter==s2[ran]:    
            nuevo_caracter = random.choice(alfabeto)
        s2[ran]=nuevo_caracter
    
    
        
    s2=''.join(s2)
    cadena.append(s1)
    cadena.append(s2)
    return cadena

def generar_cadenas_parecidas_mismo_tamano_con_transposicion(minimo,maximo):#Esta bien, cambia 3 caracteres
    rango1 = random.randint(minimo,maximo)
    cadena=[]
    s1=""
    s2=""
    for _ in range(rango1):
        s1 += random.choice(alfabeto)#Genera cadena aleatoria
    
    s2=list(s1)
    
    ind = random.randint(0,len(s2)-1)
    for _ in range(ind):#Hace "ind" cambios de caracter
        ran = random.randint(0,len(s2)-1)
        nuevo_caracter = random.choice(alfabeto)
        while nuevo_caracter==s2[ran]:    
            nuevo_caracter = random.choice(alfabeto)
        s2[ran]=nuevo_caracter
        
    cantidad = random.randint(0, len(s2) - 1)  # Genera un número entre 3 y len(s2) - 3
    for _ in range(cantidad):#Hace "cantidad" transposiciones
        i = random.randint(0,len(s2) - 2)  
        s2[i], s2[i + 1] = s2[i + 1], s2[i]
    s2=''.join(s2)
    cadena.append(s1)
    cadena.append(s2)
    return cadena
    
def generar_cadenas_parecidas_distinto_tamano_con_transposicion(minimo,maximo):#Esta bien, cambia 3 caracteres
    rango1 = random.randint(minimo,maximo)
    cadena=[]
    s1=""
    s2=""
    for _ in range(rango1):
        s1 += random.choice(alfabeto)#Genera cadena aleatoria
    
    s2=list(s1)
    #largo = len(s2)
    cambio = random.choice([-1,1])
    
    if cambio==-1:#Elimino
        eliminar = random.randint(1,5)
        s2=s2[:len(s2)-eliminar]
    else:#Agrando
        agrandar = random.randint(1,5)
        s2+=(random.choice(alfabeto) for _ in range(agrandar)) 
    
    cantidad = random.randint(0, len(s2) - 1)  # Genera un número entre 3 y len(s2) - 3
    for _ in range(cantidad):#Hace "cantidad" transposiciones
        i = random.randint(0,len(s2) - 2)  
        s2[i], s2[i + 1] = s2[i + 1], s2[i]
    
    ind = random.randint(0,len(s2)-1)
    for _ in range(ind):#Para cambiar algunos caracteres
        ran = random.randint(0,len(s2)-1)
        nuevo_caracter = random.choice(alfabeto)
        while nuevo_caracter==s2[ran]:    
            nuevo_caracter = random.choice(alfabeto)
        s2[ran]=nuevo_caracter
        
    s2=''.join(s2)
    cadena.append(s1)
    cadena.append(s2)
    return cadena

    
def generar_cadenas_con_transposiciones(minimo,maximo):#Hace 1 cadena con solo transposiciones
    cadena = []
    s1 = ''.join(random.choices(string.ascii_lowercase, k=maximo))
    s2 = list(s1)
    cantidad = random.randint(0, len(s2) - 1)  # Genera un número entre 3 y len(s2) - 3
    for _ in range(cantidad):#Hace "cantidad" transposiciones
        i = random.randint(0,len(s2) - 2)  
        s2[i], s2[i + 1] = s2[i + 1], s2[i]
    s2 = ''.join(s2)
    cadena.append(s1)
    cadena.append(s2)
    return cadena



def generar_cadenas_aleatorias_repetitivas(longitud1, longitud2, repeticiones=10):
    # Genera las cadenas con longitud aleatoria
    s1=""
    s2=""
    # Repite caracteres aleatorios en las cadenas
    for _ in range(longitud1):
        repetir = random.choice([False,True])
        if repetir: 
            repeticion1 = random.randint(2,4)
            repetidos = random.choice(alfabeto)*repeticion1
            s1+=repetidos
        else:
            s1+=random.choice(alfabeto)
    for _ in range(longitud2):
        repetir = random.choice([False,True])
        if repetir: 
            repeticion2 = random.randint(2,6)
            repetidos = random.choice(alfabeto)*repeticion2
            s2+=repetidos
        else:
            s2+=random.choice(alfabeto)
            
    return [''.join(s1), ''.join(s2)]


def escribir_data(archivo,s1,s2):    
    archivo.write(f"{len(s1)} {len(s2)}\n")
    archivo.write(s1+"\n")
    archivo.write(s2+"\n")
    archivo.write("\n")

a=open("datasets1.txt",'w')#Cadenas vacías
b=open("datasets2.txt",'w')#Cadenas iguales
c=open("datasets3.txt",'w')#Cadenas repetidas
d=open("datasets4.txt",'w')#Cadenas aleatorias de mismo tamaño
e=open("datasets5.txt",'w')#Cadenas aleatorias de distinto tamaño
f=open("datasets6.txt",'w')#Cadenas con transposiciones


minimo = 2
maximo = 8
ma = 4
mi = 2

#Cadenas vacías
for i in range(5):
    escribir_data(a,"","")
    cadena = generar_cadena(minimo,maximo)
    escribir_data(a,"",cadena[0])
    cadena = generar_cadena(minimo,maximo)
    escribir_data(a,cadena[0],"")
    minimo += 3
    maximo += 3
    

#Cadenas Identicas
minimo = 2#10
maximo = 6#30
for i in range(15):
    cadena = generar_cadenas_identicas(minimo,maximo)
    escribir_data(b,cadena[0],cadena[1])
    if(i%4==0):
        minimo += 3
        maximo += 2
    

#Cadenas repetitivas
minimo = 1
maximo = 3
for i in range(15):
    cadena = generar_cadenas_aleatorias_repetitivas(maximo,maximo,minimo)
    escribir_data(c,cadena[0],cadena[1])
    if(i%7==0):
        minimo += 1
        maximo += 1

#Cadenas mismo tamaño
minimo = 2
maximo = 6
for i in range(7):
    cadena = generar_cadenas_distintas_mismo_tamano(minimo,maximo)
    escribir_data(d,cadena[0],cadena[1])
    cadena = generar_cadenas_parecidas_mismo_tamano(minimo,maximo)
    escribir_data(d,cadena[0],cadena[1])
    if(i%2==0):
        minimo += 3
        maximo += 3

#Cadenas distinto tamaño
minimo = 2
maximo = 6
for i in range(7):
    cadena = generar_cadenas_distintas_distinto_tamano(minimo,maximo)
    escribir_data(e,cadena[0],cadena[1])
    cadena = generar_cadenas_parecidas_distinto_tamano(minimo,maximo)
    escribir_data(e,cadena[0],cadena[1])
    if(i%2==0):
        minimo += 4
        maximo += 4
        
#Cadenas con transposiciones
minimo = 2
maximo = 6
for i in range(5):
    cadena = generar_cadenas_con_transposiciones(minimo,maximo)
    escribir_data(f,cadena[0],cadena[1])
    cadena = generar_cadenas_parecidas_mismo_tamano_con_transposicion(minimo,maximo)
    escribir_data(f,cadena[0],cadena[1])
    cadena = generar_cadenas_parecidas_distinto_tamano_con_transposicion(minimo,maximo)
    escribir_data(f,cadena[0],cadena[1])
    if(i%2==0):
        minimo += 4
        maximo += 4

a.close()
b.close()
c.close()
d.close()
e.close()
f.close()