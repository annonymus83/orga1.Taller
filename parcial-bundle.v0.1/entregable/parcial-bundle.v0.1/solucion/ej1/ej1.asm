
section .text

%define TAMAÑO_LISTA_OT 16
%define TAMAÑO_PUNTERO_NODO_OT 8
%define OFF_SET_NODO_OT 8
%define OFF_SET_table_size 0 

global inicializar_OT_asm
global calcular_z_asm
global ordenar_display_list_asm

extern malloc
extern free


;########### SECCION DE TEXTO (PROGRAMA)

; ordering_table_t* inicializar_OT(uint8_t table_size);
; registros ; table_size[rdi]
inicializar_OT_asm:
    ;prologo
    push rbp
    mov rsp, rbp

    push rdi
    sub rsp, 8
    mov rdi, TAMAÑO_LISTA_OT
    call malloc
    add rsp,8
    pop rdi
    
    push rax
    MOV QWORD [rax + OFF_SET_table_size], rdi

    push rdi
    xor rdi, rdi
    mov r12, rdi
    ;el tamaño que ocupara el array en memoria
    .loop:
    cmp r12, 0
    jz .fin
    add rdi , 8
    sub r12, 1
    jmp .loop

    .fin:
    call malloc
    mov r12, rax
    pop rdi 
    
    .ciclo:
    cmp rdi, 0
    jz .final
    mov rax, [rax]
    mov QWORD [rax], 0
    add rax, 8
    sub rdi, 1
    jmp .ciclo

    .final:
    pop rax
    mov QWORD[rax + OFF_SET_NODO_OT], r12

    ;epilogo
    pop rbp
    ret


; void* calcular_z(nodo_display_list_t* display_list) ;
calcular_z_asm:

; void* ordenar_display_list(ordering_table_t* ot, nodo_display_list_t* display_list) ;
ordenar_display_list_asm:

