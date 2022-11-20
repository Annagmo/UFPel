.data
			bemVindo: .asciiz "\t\t\t\t***INSTRUCÕES***\n"  
	        	instrucoes: .asciiz "           Você deve completar o tabuleiro em todo lugar que haja o número 0.\n   Será perguntado qual número você quer por em seu lugar, o índice da linha e o da coluna.\n             Lembre-se que os índices das linhas e colunas começam em 0.\n\t\t\t\t **Boa sorte**\n"
	        	iniciaJogo: .asciiz "Digite 1 para jogar ou 0 para sair:\n"
	        	nv_linha: .asciiz "|\n"
	        	marcador_fundo_topo: .asciiz " ------------------------------------\n"
	        	separador_linha: .asciiz " | "
	        	errou: .asciiz "\nVocê errou!  \\(° - ° )/ \n"
	        	acertou: .asciiz "\nVocê acertou!  \\(°V°)/ \n"
	        	nr: .asciiz "Qual número você deseja adicionar?\n"
	        	linha: .asciiz "Índice da linha:\n"
	        	final: .asciiz "\nParabéns, você acertou todos os números!!!\n"	 
	        	sudoku: .asciiz "\n1   2   3   4\n3   4   1   2\n4   3   2   1\n2   1   4   3\n"       			
  
			jogo:       
        	 		.byte     0, 2, 3, 4   
        	 		.byte     3, 0, 1, 2  
        	 		.byte     4, 3, 0, 1
        	 		.byte     2, 1, 4, 0
        	           
.text
        	 	li $v0,4 
        	 	la $a0,bemVindo # carrega e imprime a mensagem de bem-vindo
        	 	syscall 
			
	         	li $v0,4 
        	 	la $a0,instrucoes # carrega e imprime as instruções
        	 	syscall 
			
        	 	li $v0,4 
        	 	la $a0,iniciaJogo # carrega e imprime o :  "Digite 1 para jogar:\n"
        	 	syscall
	
        	 	li $v0,5 # lê o que o usuário digitou: [0,1]
        	 	syscall
			
        	 	beq $v0,1,JOGAR # se ele clica 1 vai para o ramo JOGAR
        	 	beq $v0,0,FIMDEJOGO # se ele clica 0 vai para o ramo FIMDEJOGO e encerra o programa

        	 	j FIMDEJOGO
	
JOGAR:         	
	         	la $a0,jogo # carrega o tebuleiro
	         	jal atualiza_pilha # salva as nossas vaiáveis na pilha
	         	jal chute # vai para o ramo chute
	
	         	j FIMDEJOGO
	
FIMDEJOGO:
         		li $v0,10 # 10 é o código de saída do SPIM
         		syscall
      
atualiza_pilha:	            	 	
	         	sw $s2, 8($sp) # vai salvar o registrador $s2 que é a coluna que a gente tá no momento
         		sw $s1, 4($sp) # vai salvar o registrador $s1 que é a linha que a gente tá no momento
         		sw $s0, 0($sp) # vai salvar o registrador $s0 que é o nr que nós estamos imprimindo no momento
         	
             	 	# inicializa os registradores
         		move $s0,$a0 # em "la $a0,jogo" nós colocamos todas as nossas linhas do tabuleiro em $a0, e agora passamos pra $s0
         		move $s1, $zero # $s1 marca a linha que nós estamos no tabuleiro
         		move $s2, $zero # $s1 marca a coluna que nós estamos no tabuleiro	         	
            	 	
	         	la $a0, marcador_fundo_topo # imprime o topo do tabuleiro " ------------------------------------\n"
	         	li $v0, 4
	         	syscall
	         	
imprime_linha:	         			
            	 	 # antes de cada linha e depois de cada linha vamos imprimir um | para ficar visual.
	         	la $a0, separador_linha 
	         	li $v0, 4 # imprime o |
	         	syscall 
	         	
	         	# vamos imprimir nr por nr em cada uma das 4 linhas/ células do nosso tabuleiro
	         	lb $a0, ($s0) # lembra que nós guardamos todas as células/linhas na pilha? agora imprime elas
	         	li $v0, 1 # imprime o primeiro nr da primeira linha
         		syscall
			
         		addi $s0, $s0, 1 # aponta para a póxima linha/célula
	         	addi $s2, $s2, 1 # aumenta o registrador que está contando as colunas
	         	blt $s2, 4, imprime_linha  # vai iterando no mesmo ramo até acabarem todas as 4 colunas
	         	# já imprimiu 1 nr coluna 0⁰, proxima iteração: imprime 1 nr 1⁰ coluna...E assim vai 1 nr 2⁰ coluna, 1 nr 3⁰ coluna.
	         	# parabéns, você imprimiu uma linha.
	    
	         	
            	 	# imprime um \n pra próxioma linha, assim como um | pra fechar aquela linha
	         	la $a0, nv_linha # imprime o | \n
	         	li $v0, 4
	         	syscall 
			
	         	move $s2, $zero # resetamos o contador de colunas
	         	addi $s1, $s1, 1 # aumentamos no contador de linhas
         		
             	 	# vamos imprimir a próxima linha
	         	blt $s1,4, imprime_linha # não continua até que tenha impresso todas as 4 linhas
	
	         	# imprime fundo do tabuleiro 
	         	la $a0, marcador_fundo_topo 
	         	li $v0, 4 # " ------------------------------------\n"
	         	syscall 	
	         	
chute:         	
	         	li $v0,4 # pergunta qual vai ser o chute:
         		la $a0,nr # "Qual número você deseja adicionar?\n"
         		syscall 
			
	         	li $v0,5 # lê o nr digitado
	         	syscall
	         	move $a1,$v0 # movemos para guardar num registrador
	         	
	         	li $v0,4 # pergunta: "índice da linha:\n"
	         	la $a0,linha 
	         	syscall 
			
	         	li $v0,5 # lê o índice da linha digitado
	         	syscall
         		move $a2,$v0 # movemos para guardar o índice da linha num registrador
         			   
	         	
	         	li $t0,0
	         	li $t1,1
	         	li $t2,2
	         	li $t3,3
	         	li $t4,4
	         	
	         	# checagem do chute:
	         	beq $t0, $a2, linha0
	         	beq $t1, $a2, linha1
	         	beq $t2, $a2, linha2
	         	beq $t3, $a2, linha3	         	
	   
#elem 00           
linha0:
			beq $a1, $t1, chute_correto 
	
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
			beq $a1, $t3, chute_final
	
			j chute_errado  
	       		       			       		       		
chute_correto:
	         	li $v0,4 # imprime a mensagem de acerto:
	         	la $a0,acertou # "Você acertou!  \\(°V°)/ \n"
	         	syscall
	         	
	         	jal chute
			
chute_errado:
	         	li $v0,4
	         	la $a0,errou
	         	syscall
	         	
	         	jal chute	 
	         
chute_final:
			li $v0,4 # imprime a mensagem de acerto:
	         	la $a0,acertou # "Você acertou!  \\(°V°)/ \n"
	         	syscall
	         	
	         	li $v0,4 # imprime a mensagem final
	         	la $a0,final # concluido
	         	syscall
	         	
	         	li $v0,4
	         	la $a0,sudoku # carrega o tabuleiro realizado	         	
	         	syscall
	         	
	         	j FIMDEJOGO	     
