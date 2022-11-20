# Escreva um programa equivalente ao código C abaixo com o assembly do MIPS.
# Assim como no exemplo em C, utilize duas subrotinas (soma3n e soma). 
# Armazene os valores em $t0, $t1, $t2 e $t3, para X, Y, Z e R, respectivamente.


.main:
	# Inicializar variaveis
	ori $t0, $zero, 150			# Definir o valor de X
	ori $t1, $zero, 230			# Definir o valor de Y
	ori $t2, $zero, 991			# Definir o valor de Z
	ori $t3, $zero, 0			# Definir o valor de R
	
	la $a0, ($t0)				# Definir o primeiro parametro de soma3n
	la $a1, ($t1)				# Definir o segundo parametro de soma3n			
	la $a2, ($t2)				# Definir o terceiro parametro de soma3n

	jal soma3n				# Chamar a subrotina soma3n
	
	la $t3, ($v1)				# $t3 recebe o resultado final da chamada de subrotinas
	
	li $v0, 10				# Encerrar programa
	syscall

soma3n:
	addiu $sp, $sp, -4
	sw $ra, ($sp)				# Salvar $ra na pilha
	
	jal soma				# Chamar a subrotina soma para o primeiro calculo
	
	la $a0, ($a2)				# Atualizar o primeiro parametro da proxima chamada da subrotina soma
	la $a1, ($v0)				# Atualizar o segundo parametro da proxima chamada da subrotina soma
	
	jal soma				# Chamar a subrotina soma para o segundo calculo
	
	la $v1, ($v0)				# Armazena em $v1 o resultado da soma final
	
	lw $ra, ($sp)
	addiu $sp, $sp, 4 			# Retirar $ra da pilha
		
	jr $ra					# Retorna para onde a subrotina foi chamada
	
soma:
	addu $v0, $a0, $a1			# Armazena em $v0 a soma de $a1 com $a2 (return A + B)
	jr $ra					# Retorna para onde a subrotina foi chamada
