#Escreva a sequência 0x12345678 em $t1. A seguir, escreva um código
#que inverta a sequência, escrevendo 0x87654321 em $t2. Obviamente o
#código deve inverter os bits de $t1 e não simplesmente
#escrever 0x87654321 diretamente em $t2.

ori $t1, $zero, 0x1234 
sll $t1, $t1, 16
ori $t1, $t1, 0x5678

or $t3, $t1, $zero
sll $t3, $t3, 28

srl $t4, $t1, 4
sll $t4, $t4, 28
srl $t4, $t4, 4
or $t3, $t3, $t4

srl $t4, $t1, 8
sll $t4, $t4, 28
srl $t4, $t4, 8
or $t3, $t3, $t4

srl $t4, $t1, 12
sll $t4, $t4, 28
srl $t4, $t4, 12
or $t3, $t3, $t4

srl $t4, $t1, 16
sll $t4, $t4, 28
srl $t4, $t4, 16
or $t3, $t3, $t4

srl $t4, $t1, 20
sll $t4, $t4, 28
srl $t4, $t4, 20
or $t3, $t3, $t4

srl $t4, $t1, 24
sll $t4, $t4, 28
srl $t4, $t4, 24
or $t3, $t3, $t4

srl $t4, $t1, 28
sll $t4, $t4, 28
srl $t4, $t4, 28
or $t3, $t3, $t4

or $t2, $t3, $zero