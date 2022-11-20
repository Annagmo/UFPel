#Escreva 0xAAAAAAAA em $t1. Faça um shift de um bit para a direita
#desse valor e coloque o resultado em $t2, deixando $t1 inalterado. Em
#$t3, $t4 e $t5 coloque os resultados das operações or, and e xor entre
#$t1 e $t2, respectivamente. Em comentários no final do código, explique
#os resultados obtidos, mostrando os valores binários.

ori $t1, $zero, 0xA # 0x- é para dígito hexadecimal.  Copia o valor de $t0 para $t1 e adiciona o 'a' 
sll $t1, $t1, 4  #muda a letra 4 espaços para a esquerda, para caber outra letra de 4 bits.

ori $t1, $t1, 0xA
sll $t1, $t1, 4

ori $t1, $t1, 0xA
sll $t1, $t1, 4

ori $t1, $t1, 0xA
sll $t1, $t1, 4

ori $t1, $t1, 0xA
sll $t1, $t1, 4

ori $t1, $t1, 0xA
sll $t1, $t1, 4

ori $t1, $t1, 0xA
sll $t1, $t1, 4     

ori $t1, $t1, 0xA

#Faça um shift de um bit para a direita desse valor e coloque o resultado em $t2, deixando $t1 inalterado

srl $t2, $t1, 1 #srl = shift right logical
# O t1 é 32 bits 01010101010101010101010101010101, o t2 é 32bits 10101010101010101010101010101010 pq colocou um 0 à direita.


#Em $t3, $t4 e $t5 coloque os resultados das operações or, and e xor entre $t1 e $t2, respectivamente.
or $t3, $t1, $t2   # t3 fica 0xffffffff que é 32 bits 11111111111111111111111111111111

and $t4, $t1, $t2  # t4 fica 0x00000000 que é 32 bits 00000000000000000000000000000000

xor $t5, $t1, $t2  # t5 fica 0xffffffff que é 32 bits 11111111111111111111111111111111
