#2. Escreva um programa que calcule o produtório abaixo. O valor de n deve ser lido da
#posição 0x10010000 da memória no início do programa. O valor de A deve ser
#escrito na memória no fim do programa, na posição 0x10010004.
#OBS: considere a divisão inteira:
#       n
# A =   Π   (n i/2)
#      i=0


.data
  n:.word 3 # n = 3
  str: .asciiz   "Produtório = "

.text
main:
  lui $v1, 0x1001          #endereço de memória 0x10010000 para o registrador $v1.
  lw $v0, 0x0($v1)         # atribui o valor escolhido de n para o registrador $v0, de mesmo endereço.
  
  add $t0, $zero , 0       #i = 0.
  li $t1,0                 # inicializando o fator: (n + i/2) = 0.
  li $s0,1                 #A = 1.
  
  beq $v0,$zero,fim        #Se o n escolhido for 0, fecha o programa.

  j loop                   #chama o loop.


loop:
  beq $v0,$t0,fim          # Se n == i então encerra.

  # vamos fazer o fator (n + i/2):
  move $t1, $t0            #Passamos o valor de i para t1 que calculará o fator, enquanto o t0 permanesce como contador.
  div $t1, $t1, 2          # t1 = t1/2, portanto t1 = i/2.
  add $t1, $t1 , $v0       # t1 = t1 + n , ou seja, t1 = i/2 + n, que é o fator que queríamos.

  mult $s0,$t1             #sum * (n + i/2);
  mflo $s0                 #sum = sum * (n + i/2);

  add $t0, $t0, 1          # i++;


  j loop                   #chama o loop novamente, até n == i.

 
fim:
                          #quando i == n ele faz o último fator da multiplicação, que não está incluso no loop:
#fazendo o fator:
move $t1, $t0    #t1: t1 = i;
div $t1, $t1, 2 #t1 = i/2;
add $t1, $t1 , $v0 #t1 = i/2 + n;

mult $s0,$t1  #sum * (n + i/2);
mflo $s0 #sum = sum * (n + i/2);
#-----------------------------------

li  $v0,4       #print string.
la  $a0,str
syscall

li $v0,1        #print valor produtorio.
move $a0,$s0
syscall

sw $s0, 0x10010004 # armazena o valor do somatório na memória.
