.text:

# inicializar programa
main:
    la a0, arr  #cargamos direc. de array en a0
    li a1, 12   #guardamos la longitud del array
    li a2, 0xffffffff #guardamos valor de suma
    la a3, 0x0  #guardare mi indice en a3, inicializo en 0
    call intersecar_impares

exit:
    # Imprime la suma
    mv a0, t4
    li a7, 34
    ecall

    # Termina el programa.
    li a0, 0
    li a7, 93
    ecall

# recorrer arreglo y acumular

intersecar_impares:
# cargo los argumentos en otros registros para 
# no perderlos cuando haga la llamada de mis funciones aux.
    mv s0, a0  # Direccion del array
    mv s1, a1  #Longitud del array
    mv s2, a2  #suma inicia en 0xffffffff, aqui ire guardando el resultado
    mv s3, a3  #cargo mi indice en s3, inicializado en 0
    mv s4, ra  #return address


loop:
    #while(s1 > 0)
    beqz s1, return #si la longitud es cero entonces salto a return
    addi s1, s1, -1

    # Cargo el elemento a sumar (si cumple la condición de i = impar) 
    # Tambien cargo el indice (s3) a revisar si es impar
    lw a0, 0(s0)
    mv a4, s3
    call es_impar

    #en a4 tenemos el resultado de es_impar
    # vale 1 si indice es impar y 0 en caso contrario
    # entonces si el indice es impar salto a la etiqueta suma_YLogico 
    bgtz a4, suma_YLogico

    #Incremento la dirección del siguiente elemento
    #E incremento tambien mi indice
    addi s0,s0, 4 # 4 pues c/instruccion ocupa 4 direcciones de memoria
                  # dado que cada palabra es 32 bits y el direccionamiento es de a byte
    addi s3, s3, 1 #sumo 1 a mi indice

    j loop


suma_YLogico:
#Hago un and logico entre el valor suma y el elto que se encuentra 
#en el indice impar. Guardandolo en s2
    and s2, s2, a0
    mv a4, x0
    ret

return:
    #Coloco el resultado en el registro de retorno
    #Dado que el resultado se imprime desde t4, 
    #entonces vuelvo a guardar el resultado a t4
    mv a0, s2 
    mv ra, s4
    mv t4,a0
    ret

es_impar:
    andi a4, s3 , 1
    ret



.data:
arr:
.word	0xffffffff, 0x95555555, 0xf4444444, 0xf1111111
.word	0xffffff00, 0xf5005555, 0x95444444, 0xf1113311
.word	0xff00ffff, 0xf5550055, 0xa4444433, 0xa1551111

