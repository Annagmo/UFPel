#2. Escreva um programa que calcule o produtório abaixo. O valor de n deve ser lido da
#posição 0x10010000 da memória no início do programa. O valor de A deve ser
#escrito na memória no fim do programa, na posição 0x10010004.
#OBS: considere a divisão inteira, i.e.:
#1 / 2 = 0,
#2 / 2 = 1,
#3 / 2 = 1,
#4 / 2 = 2, etc.
#A = prod (i=0 Ao n) (n+1/2)


.data
str: .asciiz    "Digite a qtd n de números:"
n: .asciiz   "Somatório = "


.text

main:
la $s0, 0x10010000 #fazendo o s0 ser o 10010000??
li $t1,0    # (n + i/2) = 0
li $s0,0    #somatório = 0
add $t0, $zero , 0 # t0 = 0, fazendo o i

li $v0,4    #carregando o serviço read para ler um int
la $a0,str #Para imprimir a string
syscall

li $v0,5    #Pega o n
syscall

beq $v0,$zero,fim #Se o user digitar 0, fecha o programa

j loop #chama o loop



loop:
beq $v0,$t0,fim  # Se n == i então encerra. Agora que eu entendi, BRANCH ON EQUAL, ele vai pro ramo/Branch Fim quando é EQUAL.

# vamos fazer o (n + i/2):
move $t1, $t0    # O i tá armazenado no t0, passamos pro t1: t1 = i
div $t1, $t1, 2 # t1 = t1/2, portanto t1 = i/2
add $t1, $t1 , $v0 # t1 = t1 + n   ou seja  t1 = i/2 + n, que é o fator que queríamos.

add $s0,$s0,$t1  #sum += sum + (n + i/2);

add $t0, $t0, 1 # i++;

j loop #chama o loop dnv, uma hora bate no n == i.


 
fim:
#quando i == n ele faz o último fator da soma, que não está incluso no loop
add $s0,$s0,$t1  #sum = sum + (n + i/2)

li  $v0,4       #print string
la  $a0,n
syscall

li $v0,1        #print valor somatório
move $a0,$s0
syscall

.end
