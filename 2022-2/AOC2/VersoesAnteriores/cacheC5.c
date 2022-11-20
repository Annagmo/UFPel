#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

int substitui(char *sub, int bits_val []);

static void Help(){
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("\t\tBem-vindo à cacheCool:\n");
	printf(" Você digitou um número incorreto de argumentos. Utilize:\n");
	printf("./cacheCool <nsets> <bsize> <assoc> <substituição> <flag_saida> arquivo_de_entrada\n");
	printf("\n  Ex.: ./cacheCool 64 8 1 R 0 bin_100.bin\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	exit(EXIT_FAILURE);
}

int main( int argc, char *argv[ ] )
{
	if (argc != 7){
		Help();
	}
	int nsets = atoi(argv[1]);
	int bsize = atoi(argv[2]);
	int assoc = atoi(argv[3]);
	char *subst = argv[4];
	int flagOut = atoi(argv[5]);
	char *arquivoEntrada = argv[6];

	//printf("nsets = %d\n", nsets);
	//printf("bsize = %d\n", bsize);
	//printf("assoc = %d\n", assoc);
	//printf("subst = %s\n", subst);
	//printf("flagOut = %d\n", flagOut);
	//printf("arquivo = %s\n", arquivoEntrada);

		int miss_compulsorio =0, n_bits_tag =0, Ncheio = 0, vazio =0;
		int endereco = 0, tag =0, indice = 0, miss =0, hit =0, i =0, miss_conflito =0, miss_capacidade=0, qtd_acessos=0;
		float taxa_hit=0.0, taxa_miss=0.0, taxa_miss_comp=0.0,taxa_miss_conf=0.0, taxa_miss_cap=0.0;
		int n_bits_offset =0, n_bits_indice =0;
		int cache_val [nsets * assoc] = {0};  //é a lista dos bits de validade da cache
		int cache_tag [nsets * assoc] = {0};  //é a lista dos bits de tag da cache
		n_bits_offset = (log2(bsize));
		n_bits_indice = (log2(nsets));
		n_bits_tag = 32 - n_bits_offset - n_bits_indice;
		//descobre o número de bits de cada parcela do endereço para todos os endereços do arquivo

		//----------------------------------------------------------
		//Variaveis para o conjunto associativo;
		int achou = 0;
		typedef struct{
			int val;
			int tag;
			int info;
		}Cache; //cria uma struct de cache pq vai ter uma posicao em cada conjunto para o mesmo indice
		Cache cache[nsets * assoc][assoc] = {0}; //inicializa tudo em 0

		//----------------------------------------------------------
		//variaveis p/ o arquivo:
		FILE *fptr;
		fptr = fopen(arquivoEntrada, "rb"); //rb  para arquivos binarios.
		//----------------------------------------------------------

		if(fptr == NULL) {
			printf("Cannot open file \n");
			exit(0); //se não puder abrir o arquivo
		}
		while (!feof(fptr))
		{
			achou = 0;
			Ncheio = 0;
			vazio = 0;
			/* 
			Depois de muito pesquisar, descobri que o arquivo binario tem entradas do tipo "\0\0\0\x04Mary\0\0\0", 
			entao, teoricamente, os nossos numeros esto na quarta posicao em cada linha. Se eu pegar sempre a quarta posicao, eu pego so o inteiro q eu quero.
			*/

			//para ler o arq binario:
			unsigned char buffer[4]; //o buffer vai pegar de endereco por endereco
			fread(buffer,sizeof(int),1,fptr); // le 1 byte para o buffer. Vai de um em um pq se pegasse todos teria que iterar a lista e ver hit/miss de cada 1.

			endereco = buffer[3]; //pega cada byte e bota pra o endereco cada um na sua vez
    		//printf("%u, ", buffer[3]); // TESTE: imprimindo endereços

			qtd_acessos++;
			//printf("%d",tag);
			uint32_t mask = 0xffffffff >> n_bits_tag;
			tag = endereco >> ( n_bits_offset + n_bits_indice );
			indice = ( endereco & mask );
			indice = indice >> n_bits_offset;

			if(assoc == 1){ //Mapeamento Direto
			if (cache_val[indice] == 0)
			{
				miss++; 		//nao tava contando os miss_compulsorio pro tot de misses.
				miss_compulsorio++;
				cache_val[indice] = 1;
				cache_tag[indice] = tag;
							// estas duas últimas instruções representam o tratamento da falta.
			}
			else
				if (cache_tag[indice] == tag)
					hit++;
				else 			// a pos cheia e miss
				{
					miss++;
					
					// conflito ou capacidade?
					for(i=0; i < sizeof(cache_val); i++){
						if(cache_val[i] == 0){
							miss_conflito++;
							cache_val[indice] = 1;
							cache_tag[indice] = tag;
						}
						else{miss_capacidade++;
							indice = substitui(*subst, cache_val);
							cache_val[indice] = 1;
							cache_tag[indice] = tag;
							}
					}
				}
			} else { //Conjunto Associativo
				for(i=0; i<assoc; i++){    //HIT
					if(cache[indice][i].tag == tag && cache[indice][i].val == 1){ //i representa o conjunto naquela posiçao. Ex.: Assoc = 2 temos cache[indice][0] e cache[indice][1]
						hit++;
						achou = 1;
						//printf("%d",cache[indice][i].tag);
					}
					else if (cache[indice][i].tag ==0){ //se achou permanescer 0 eh pq nao achou hit em nenhum conjunto naquela posicao da cache
						Ncheio++; //Mas ter o achou ==0 nao quer dizer que nada esteja cheio, pode estar cheio mas nao ser o q eu procuro. Se nada estiver cheio eh miss comp, se estiver cheio eh miss de conflito.
					}	
				}
				if(achou==0){
					miss++; 
					for(i=0; i<assoc; i++){
						if(Ncheio == assoc){ //se nada ta cheio eh miss compulsorio
							miss_compulsorio++;
							//Tratamento da falta:
							cache[indice][i].tag = tag;//ja que deu miss, se eu achar um lugar vazio, boto do endereco la (colocando a tag e mudando Val)  if(cache[indice][i].tag ==0)
							cache[indice][i].val =1;
						}
						else if(cache[indice][i].tag !=0){ // se nao ta vazio e nao foi hit,eh miss de conflito.
							miss_conflito++; 
							//Tratamento da falta:
							cache[indice][i].tag = tag;
							cache[indice][i].val =1;
						}
						else if(Ncheio==0){ //se, depois de passar pelo if que incrementa o contador, continuar 0, eh pq ta tudo cheio e eh miss de capacidade.
							miss_capacidade++;
							//Tratamento da falta:
                            indice = substitui(*subst, cache_val); 
							cache[indice][i].tag = tag;
							cache[indice][i].val =1;
						}
					}
				}
			}
			// Totalmente associativo
			if (nsets == 1) {							// TA: n_conjuntos = tamanho da cachce 		      
				if (cache_val[indice] == 0) {					// Compulsory miss
					miss++; 
					miss_compulsorio++;
					cache_val[indice] = 1;					// Coloca os valores no local
					cache_tag[indice] = tag;
				} else { 
					if (cache_tag[indice] == tag) {                         // Hit
						hit++;
					} else {						// Capacity miss
						miss++; 
						miss_capacidade++;																 
						
						indice = substitui(*subst, cache_val);          // Atribui o valor solicitado à posição escolhida
						cache_val[indice] = 1;
						cache_tag[indice] = tag;  	
					}
				} 
			} 
		}
		taxa_hit = (((float)hit/qtd_acessos)*100);
		taxa_miss = (((float)miss/qtd_acessos)*100);
		taxa_miss_cap = (((float)miss_capacidade/qtd_acessos)*100);
		taxa_miss_comp = (((float)miss_compulsorio/qtd_acessos)*100);
		taxa_miss_conf = (((float)miss_conflito/qtd_acessos)*100);

		if(flagOut==0){
			printf("-------------------------------\n");
			printf("Qntd Acessos: %d\n",qtd_acessos-1); //Lembrando que, o -1 pq o acesso do EOF tambem eh 1 acesso
			printf("hit: %d\n",hit);
			printf("miss: %d\n",miss);
			printf("-------------------------------\n");
			printf("Taxa de hit: %.3f\n",taxa_hit);
			printf("Taxa de miss: %.3f\n",taxa_miss);
			printf("Taxa de miss de compulsório: %.3f\n",taxa_miss_comp);
			printf("Taxa de miss de capacidade: %.3f\n",taxa_miss_cap);
			printf("Taxa de miss de conflito: %.3f\n",taxa_miss_conf);
			printf("-------------------------------\n");
		}
		else if (flagOut == 1){
			printf("%d, %.3f, %.3f, %.3f, %.3f, %.3f\n",qtd_acessos-1, taxa_hit/100, taxa_miss/100, taxa_miss_comp/100, taxa_miss_cap/100, taxa_miss_conf/100);
		}
		fclose(fptr);
		
	return 0;
}
int substitui(char *sub, int bits_val []) {
	if(sub == 'r'){
		return 1 + (rand() % sizeof(bits_val));		// gera aleatório entre 1 e a quantidade total de índice   
	}
}
