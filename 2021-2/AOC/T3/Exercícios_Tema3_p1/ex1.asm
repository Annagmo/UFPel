#Faça um programa que escreva o valor 0xDECADA70 no registrador
#$t7, incluindo um dígito hexadecimal por vez (isto é, insira letra por
#letra, individualmente) no registrador.

ori $t7, $zero, 0xD # 0x- é para dígito hexadecimal.  Copia o valor de $t0 para $t7 e adiciona o 'd' 
sll $t7, $t7, 4     #muda a letra 4 espaços para a esquerda, para caber outra letra de 4 bits.

ori $t7, $t7, 0xE #copia o valor de $t7 para $t7 e adiciona o 'e' 
sll $t7, $t7, 4   #muda a letra 4 espaços para a esquerda, para caber outra letra de 4 bits.

ori $t7, $t7, 0xC #copia o valor de $t7 para $t7 e adiciona o 'c' 
sll $t7, $t7, 4   #muda a letra 4 espaços para a esquerda, para caber outra letra de 4 bits. 

ori $t7, $t7, 0xA #copia o valor de $t7 para $t7 e adiciona o 'a' 
sll $t7, $t7, 4   #muda a letra 4 espaços para a esquerda, para caber outra letra de 4 bits.

ori $t7, $t7, 0xD #copia o valor de $t7 para $t7 e adiciona o 'd' 
sll $t7, $t7, 4   #muda a letra 4 espaços para a esquerda, para caber outra letra de 4 bits.

ori $t7, $t7, 0xA #copia o valor de $t7 para $t7 e adiciona o 'a' 
sll $t7, $t7, 4   #muda a letra 4 espaços para a esquerda, para caber outra letra de 4 bits.

ori $t7, $t7, 0x7 #copia o valor de $t7 para $t7 e adiciona o '7' 
sll $t7, $t7, 4   #muda a letra 4 espaços para a esquerda, para caber outra letra de 4 bits.     

ori $t7, $t7, 0x0 #copia o valor de $t7 para $t7 e adiciona o '0' 
