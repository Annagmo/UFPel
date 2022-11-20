#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
int main( int argc, char *argv[ ] )
{
	if (argc != 7){
		printf("Numero de argumentos incorreto. Utilize:\n");
		printf("./cacheCool <nsets> <bsize> <assoc> <substituição> <flag_saida> arquivo_de_entrada\n");
		exit(EXIT_FAILURE);
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

    // Seu codigo vai aqui
	
		int miss_compulsorio =0, n_bits_tag =0;
		int endereco = 0, tag =0, indice = 0, miss =0, hit =0, i =0, miss_conflito =0, miss_capacidade=0, qtd_acessos=1;
		float taxa_hit=0, taxa_miss=0, taxa_miss_comp=0,taxa_miss_conf=0, taxa_miss_cap=0;
		char lixo, string[50];
		int n_bits_offset =0, n_bits_indice =0;

		int cache_val [nsets * assoc];  //é a lista dos bits de validade da cache
		int cache_tag [nsets * assoc];  //é a lista dos bits de tag da cache

		n_bits_offset = (log2(bsize));
		n_bits_indice = (log2(nsets));
		n_bits_tag = 32 - n_bits_offset - n_bits_indice;
		//descobre o número de bits de cada parcela do endereço para todos os endereços do arquivo

		FILE *fptr;
		fptr = fopen(arquivoEntrada, "rb"); //aprendi hoje q tinha q ser rb.


		while (fgetc(fptr) != EOF )
		{
			//para ler o arq binario:
			unsigned char buffer[1]; //o buffer vai pegar de endereco por endereco
			fread(buffer,sizeof(buffer),1,fptr); // le 1 byte para o buffef. Vai de um em um pq se pegasse todos teria que iterar a lista e ver hit/miss de cada 1.

			if(buffer[0]!=0){ //de alguma forma a lista ta ficando:    endereco  0  endereco  0  endereco  0  .... entao apreciem minha gambiarra: se nao for 0 entra no calculo.
    			printf("%u ", buffer[0]); // imprime serie de bytes
				endereco = buffer[0]; //pega cada byte e bota pra o endereco cada um na sua vez
			}
			//--------------

			 //essa tristeza desse treco ta em pseudo codigo. O tal >> no existe em C. E ai como nao existe o codigo passa direto pelos dois primeiros ifs que tem alguma condiçao 
			 // e cai no if que conta  tudo como miss de capacidade e de conflito.

			tag = endereco >> (n_bits_offset + n_bits_indice);  
			indice = (endereco >> n_bits_offset) & (2^n_bits_indice -1);
			//isso é uma máscara que vai deixar apenas os bits do índice na variável “endereço”.

			//--------------------------


			qtd_acessos++;

			if(assoc ==1){ //Mapeamento Direto
				// para o mapeamento direto
				if (cache_val[indice] == 0)
				{
				miss_compulsorio++;
				cache_val[indice] = 1;
				cache_tag[indice] = tag;
				// estas duas últimas instruções representam o tratamento da falta.
				}
				else
				if (cache_tag[indice] == tag)
				hit++;

				else //a pos cheia e miss
				{
					miss++;
					cache_val[indice] = 1;
					cache_tag[indice] = tag;
					//conflito ou capacidade?
					for(i=0; i<sizeof(cache_val); i++){
						if(cache_val[i] ==0){
							miss_conflito++;
						}
						else{miss_capacidade++;}
					}

				}
			} 

			if(nsets == 1){   //totalmente associativo
			}
		
		}
		taxa_hit = hit/qtd_acessos;
		taxa_miss = miss/qtd_acessos;
		taxa_miss_cap = miss_capacidade/qtd_acessos;
		taxa_miss_comp = miss_compulsorio/qtd_acessos;
		taxa_miss_conf = miss_conflito/qtd_acessos;

		if(flagOut==0){
			printf("---------------------\n");
			printf("Qntd Acessos: %d\n",qtd_acessos); //isso nao faz parte do print q ele quer mas eh teste pra ver se pelo menos ele le os 100 end.  ( ta com 201 [100 zeros],[100 enderecos][1 EOF] )
			printf("Taxa de hit: %f\n",taxa_hit);
			printf("Taxa de miss: %f\n",taxa_miss);
			printf("Taxa de miss de compulsório: %f\n",taxa_miss_comp);
			printf("Taxa de miss de capacidade: %f\n",taxa_miss_cap);
			printf("Taxa de miss de conflito: %f\n",taxa_miss_conf);
			printf("---------------------\n");
		}
		else if (flagOut == 1){
			printf("%f, %f, %f, %f, %f\n",taxa_hit, taxa_miss, taxa_miss_comp, taxa_miss_cap, taxa_miss_conf);
		}
		fclose(fptr);
		
	return 0;
}




