.text:

# inicializar programa
main:
    la a0, src #cargo la direccion de src
    la a1, dst #cargo la direccion de dst
    li a2, 12  #cargo la longitud de ambos arrays en a2
    call asignacion 

imprimir:
    la t2, dst
    # Cantidad de datos.
    li t3, 12
loop_imprimir:
    beqz t3, exit
    addi t3, t3, -1
    lw t4, 0(t2)
    # Imprime el resultado
    mv a0, t4
    li a7, 34
    ecall
    addi t2, t2, 4

    j loop_imprimir
exit:
    # Termina el programa.
    li a0, 0
    li a7, 93
    ecall

# recorrer arreglo y mover

asignacion:
#Cargo mis argumentos a otros registros 
#para no perderlo en las llamadas de los mismos
    mv s0, a0  # Direccion del array src 
    mv s1, a1  # Direccion del array dst
    mv s2, a2  # Longitud de ambos arrays
    mv a3, x0 # en a3 guardare mi indice 

loop:
    # while (s2 > 0)
    beqz s2, return
    addi s2, s2, -1

    #cargo los elementos a utilizar en la asignacion
    lw a0, 0(s0) # cargo elto de array src
    lw a1, 0(s1) #cargo elto de array dst

    #aplico xor entre los dos elementos del indice i 
    #asigno este resultado como nuevo elto de dst en la posicion i
    xor a0, a0 , a1
    sw a0, 0(s1)  #lo guardo en memoria

    #aumento mi indice a +1
    #Incremento la dirección al siguiente elemento en ambos arrays
    addi a3, a3, 1
    addi s0, s0 , 4
    addi s1,s1, 4

    j loop

return:
    ret

.data:
src:
.word 0xffffffff, 0x95555555, 0xf4444444, 0xf1111111
.word 0xffffff00, 0xf5005555, 0x95444444, 0xf1113311
.word 0xff00ffff, 0xf5550055, 0xa4444433, 0xa1551111      
dst:
.word 0xf5005555, 0x95444444, 0xf1113311, 0xffffff00
.word 0xf1111111, 0xffffffff, 0x95555555, 0xf4444444
.word 0xa1551111, 0xff00ffff, 0xf5550055, 0xa4444433
