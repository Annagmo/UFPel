#Faça um programa que some os números decimais 326, -211, 311 e -684 e
#escreva o resultado no registrador $t0. NÃO utilize a instrução sub.

ori $t1, $zero, 326 
addi $t2, $zero, -211 
ori $t3, $zero, 311 
addi $t4, $zero, -684 

add $t0, $t1, $t2 
add $t0, $t0, $t3 
add $t0, $t0, $t4 