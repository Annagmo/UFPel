#Comece um programa pela instrução: ori $t1, $zero, 0x01. Usando
#apenas as instruções lógicas do tipo R (dois registradores como
#operandos) or, and e xor e instruções de shift (isto é, sem usar outras
#instruções ori além da inicial e nem instruções nor),
#escreva 0xFFFFFFFF em $t1. Procure usar o menor número de
#instruções possível.

ori $t1, $zero, 0x01  # inicializa o t1. t1 = 00000000000000000000000000000001 = 1

sll $t2, $t1, 1   # desloca o t1 de um bit e salva em t2. t2 = 00000000000000000000000000000010 = 2
or $t1, $t1, $t2  # concatena o t1 e o t2 e salva em t1. t1 = 00000000000000000000000000000011 = 3

sll $t2, $t1, 2   # desloca o t1 de dois bits e salva em t2. t2 = 00000000000000000000000000001100
or $t1, $t1, $t2  # concatena o t1 e o t2 e salva em t1. t1 = 00000000000000000000000000001111

sll $t2, $t1, 4   # desloca o t1 de dois bits e salva em t2. t2 = 00000000000000000000000011110000
or $t1, $t1, $t2  # concatena o t1 e o t2 e salva em t1. t1 = 00000000000000000000000011111111

sll $t2, $t1, 8   # desloca o t1 de dois bits e salva em t2. t2 = 00000000000000001111111100000000
or $t1, $t1, $t2  # concatena o t1 e o t2 e salva em t1. t1 = 00000000000000001111111111111111

sll $t2, $t1, 16   # desloca o t1 de dois bits e salva em t2. t2 = 11111111111111110000000000000000
or $t1, $t1, $t2  # concatena o t1 e o t2 e salva em t1. t1 = 11111111111111111111111111111111
