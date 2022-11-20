#11. Leia dois vetores de 5 números inteiros (word) e armazene na memória iniciando na
#posição 0x10010000. Concatene os vetores e imprima o resultado na tela.
#Exemplo
#vetor1: 1 5 4 3 5
#vetor2: 2 3 4 6 8
#saida: 1 5 4 3 5 2 3 4 6 8


.data

    v1: 
    	.word  1, 5, 4, 3, 5
    v2: 
    	.word  2, 3, 4, 6, 8 
    	
.text

main:
    lui     $t1, 0x1001     #endereço de memória 0x10010000 para o registrador $v1.
    la      $t1, v1         #carrega $t1 com os dois vetores v1 e v2.
    li      $v0, 0         
    li      $t0, 0          #contador
loop:
    bge     $t0, 10, fim    #quando o contador chega no final dos dois vetores, vai pro fim

    lw      $t2, 0($t1)     # tem que carregar a palavra do endereço e ir para o próximo endereço
    addi    $t1, $t1, 4

    move    $a0, $t2
    li      $v0, 1          #para imprimir inteiro   
    syscall
 
    li      $v0, 11         #para imprimir caractere ' '
    syscall

    addi    $t0, $t0, 1     #aumenta o contador
    j      loop

fim:
    li      $a0, 10         #para printar os 10 nrs
    syscall
