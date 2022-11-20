.data

                        bemVindo: .asciiz "\t\t\t\t***INSTRUCÕES***\n"  
	        	instrucoes: .asciiz "           Você deve completar o tabuleiro em todo lugar que haja o número 0.\n   Será perguntado qual número você quer por em seu lugar, o índice da linha e o da coluna.\n             Lembre-se que os índices das linhas e colunas começam em 0.\n\t\t\t\t **Boa sorte**\n"
	        	iniciaJogo: .asciiz "Digite 1 para jogar ou 0 para sair:\n"
	        	nv_linha: .asciiz "|\n"
	        	marcador_fundo_topo: .asciiz " ------------------------------------\n"
	        	separador_linha: .asciiz " | "
	        	errou: .asciiz "Você errou!  \\(° - ° )/ \n"
	        	acertou: .asciiz "Você acertou!  \\(°V°)/ \n"
	        	nr: .asciiz "Qual número você deseja adicionar?\n"
	        	linha: .asciiz "índice da linha:\n"
        	 	col: .asciiz "índice da coluna:\n"
  
jogo:       
        	 	.byte     0, 2, 3, 4   
        	 	.byte     3, 0, 1, 2  
        	 	.byte     4, 3, 0, 1
        	 	.byte     2, 1, 4, 0
        	           
.text
        	 	li $v0,4 
        	 	la $a0,bemVindo #carrega e imprime a mensagem de bem-vindo
        	 	syscall 
			
	         	li $v0,4 
        	 	la $a0,instrucoes #carrega e imprime as instruções
        	 	syscall 
			
        	 	li $v0,4 
        	 	la $a0,iniciaJogo #carrega e imprime o :  "Digite 1 para jogar:\n"
        	 	syscall
	
        	 	li $v0,5 #lê o que o usuário digitou: [0,1]
        	 	syscall
			
        	 	beq $v0,1,JOGAR #se ele clica 1 vai para o ramo JOGAR
        	 	beq $v0,0,FIMDEJOGO #se ele clica 0 vai para o ramo FIMDEJOGO e encerra o programa

        	 	j FIMDEJOGO
	
JOGAR:

	         	
	         	la $a0,jogo #carrega o tebuleiro
	         	jal atualiza_pilha #salva as nossas vaiáveis na pilha
	         	la $a0,jogo #carrega o tabuleiro novamente em uma lista 2d para saber a posição na lista que o user vai botar o nr
	         	jal chute #vai para o ramo chute
	
	         	j FIMDEJOGO
	
FIMDEJOGO:
         		li $v0,10 #10 é o código de saída do SPIM
         		syscall
      
atualiza_pilha:	
             	 	# vamos criar uma pilha
         		sub $sp, $sp, 16 
         		# sp vai ser o nosso registrador pilha, e nele nós valos alocar 4 coisas:
         		# a gente preenche/atualiza a pilha do último elemento pro primeiro lá na base da pilha.
	         	sw $ra, 12($sp) 
	         	# nos últimos 4 bytes da pilha nós armazenamos o endereço de retorno. 
	        	# como a jal "atualiza_pilha" vai sobrescrever o nosso endereço de retorno da pilha $ra <- PC+4 nós precisamos 
	        	# restaurar o endereço de retorno que tínhamos antes. E nós vamos restaurar este endereço no "jr $ra" só depois de 
	        	# imprimir o tabuleiro
	         	sw $s2, 8($sp) # Vai salvar o registrador $s2 que é a coluna que a gente tá no momento
         		sw $s1, 4($sp) # Vai salvar o registrador $s1 que é a linha que a gente tá no momento
         		sw $s0, 0($sp) # Vai salvar o registrador $s0 que é a linha que nós estamos imprimindo no momento
         	
             	 	# inicializa os registradores
         		move $s0,$a0 # em "la $a0,jogo" nós colocamos todas as nossas linhas do tabuleiro em $a0, e agora passamos pra $s0
         		#que vai guardando na pilha o nosso tabuleiro atualizado com a jogada do usuário.
         		move $s1, $zero # $s1 marca a linha que nós estamos no tabuleiro
         		move $s2, $zero # $s1 marca a coluna que nós estamos no tabuleiro
	         	
            	 	
	         	la $a0, marcador_fundo_topo # imprime o topo do tabuleiro " ------------------------------------\n"
	         	li $v0, 4
	         	syscall
	         	
imprime_linha:	         
			#eu tinha falado que nós só vamos restaurar o endereço de retorno da pilha só depois de imprimir o tabuleiro
			# neste ramo nós vamos imprimer linha por linha, nr por nr e depois de tudo, vamos restaurar o endereço de retorno
			#com o "jr $ra"	
			
			
            	 	 # antes de cada linha e depois de cada linha vamos imprimir um | para ficar visual.
	         	la $a0, separador_linha 
	         	li $v0, 4 #imprime o |
	         	syscall 
	         	
	         	#vamos imprimir nr por nr em cada uma das 4 linhas/ células do nosso tabuleiro
	         	lb $a0, ($s0) #lembra que nós guardamos todas as células/linhas na pilha? agora imprime elas
	         	li $v0, 1 #imprime o primeiro nr da primeira linha
         		syscall
			
         		addi $s0, $s0, 1 #aponta para a póxima linha/célula
	         	addi $s2, $s2, 1 # aumenta o registrador que está contando as colunas
	         	blt $s2, 4, imprime_linha  # vai iterando no mesmo ramo até acabarem todas as 4 colunas
	         	#já imprimiu 1 nr coluna 0⁰, proxima iteração: imprime 1 nr 1⁰ coluna...E assim vai 1 nr 2⁰ coluna, 1 nr 3⁰ coluna.
	         	#parabéns, você imprimiu uma linha.
	    
	         	
            	 	#imprime um \n pra próxioma linha, assim como um | pra fechar aquela linha
	         	la $a0, nv_linha #imprime o | \n
	         	li $v0, 4
	         	syscall 
			
	         	move $s2, $zero #resetamos o contador de colunas
	         	addi $s1, $s1, 1 # aumentamos no contador de linhas
         		
             	 	# vamos imprimir a próxima linha
	         	blt $s1,4, imprime_linha # não continua até que tenha impresso todas as 4 linhas
			
				
	         	# retorna a pilha para o que ela era no início, pq vamos precisar imprimir ela toda vez que o usuário for chutar
	         	lw $s0, 0($sp) # retorna o registrador que armazena a linha que estávamos imprimindo no momento para o que era
	         	lw $s1, 4($sp) #  retorna o contador de linhas para o que era
	         	lw $s2, 8($sp) #  retorna o contador de colunas para o que era
	         	lw $ra, 12($sp) #  retorna o endereço de retorno da pilha
         		addi $sp, $sp, 16 # limpa a pilha
	
	         	# imprime fundo do tabuleiro 
	         	la $a0, marcador_fundo_topo 
	         	li $v0, 4 # " ------------------------------------\n"
	         	syscall 
	
	         	jr $ra # Retorna o ra para o endereço de retorno que tinhamos antes, uma vez que por causa 
	         	#do "jal atualiza_pilha" tivemos "ra<- PC+4 "
	         	
chute:
			#nós tínhamos uma pilha para a primeira impressão do tabuleiro, agora vamos refazer essa pilha para
			#cada um dos chutes do usuário. Então nunca vamos ter um "jr $ra". Uma vez que, nós já vamos colocar
			# a nova pilha no endereço de retorno da antiga, e, vamos sempre atualizar essa pilha.
			
	         	# vamos refazer a pilha
	         	subi $sp, $sp, 16 # guardar 4 registradores com valores nela
	         	sw $ra, 12($sp) # salvar o endereço de retorno
	         	sw $s2, 8($sp) # marca coluna
	         	sw $s1, 4($sp) # marca linha
         		sw $s0, 0($sp) # linha que vamos imprimir
         	
           	 	# inicializa os registradores
	         	move $s0,$a0 # movemos a linha que vamos imprimir para o a0 para não afetar o armazenamento original s0.
	         	
	         	li $v0,4 # pergunta qual vai ser o chute:
         		la $a0,nr #"Qual número você deseja adicionar?\n"
         		syscall 
			
	         	li $v0,5 #lê o nr digitado
	         	syscall
	         	move $a1,$v0 #movemos para guardar num registrador
	         	
	         	li $v0,4 # pergunta: "índice da linha:\n"
	         	la $a0,linha 
	         	syscall 
			
	         	li $v0,5 #lê o índice da linha digitado
	         	syscall
         		move $a2,$v0 #movemos para guardar o índice da linha num registrador
         		
	         	li $v0,4 #pergunta: "índice da coluna:\n"
	         	la $a0,col 
	         	syscall

	         	li $v0,5 #lê o índice da coluna
	         	syscall #execute the syscall
	         	move $a3,$v0 #movemos para guardar o índice da coluna num registrador
	         
	         	move $a0,$s0
	         	move $t5,$s0 # move o endereço de retorno da pilha que tá armazenando o tabuleiro para um registrador manipulável
	         	# que não vai alterar o original
	         	
	         	li $t1,1
	         	li $t2,2
	         	li $t3,3
	         	li $t4,4
	         	#Checagem do chute:
	         	beq $t0, $a2, linha0
	         	beq $t1, $a2, linha1
	         	beq $t2, $a2, linha2
	         	beq $t3, $a2, linha3
	         	
	   
#elem 00           
linha0:
	beq $a1, $t1, chute_correto   # 1, 4, 2, 3 é a Diagonal principal
	
	j chute_errado
	
#elem 11	
linha1:
	beq $a1, $t4, chute_correto
	
	j chute_errado
	
#elem 22	
linha2:
	beq $a1, $t2, chute_correto
	
	j chute_errado 
	
#elem 33	
linha3:
	beq $a1, $t3, chute_correto
	
	j chute_errado  
	

	       		       			       		       		
chute_correto:
	         	li $v0,4 #imprime a mensagem de acerto:
	         	la $a0,acertou # "Você acertou!  \\(°V°)/ \n"
	         	syscall
			
chute_errado:
	         	li $v0,4
	         	la $a0,errou
	         	syscall	         	
      		       	         	
