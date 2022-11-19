#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct No *Apontador; //para a função remove

typedef long tipoChave;
typedef struct {
    tipoChave chave;
} registro;

typedef struct Nodo { 
    registro reg;
    struct Nodo *pEsq;
    struct Nodo *pDir;
} Nodo;

int insere (Nodo **ppRaiz, registro reg);
void imprimeAVL (Nodo *pRaiz, int nivel);
void limpaAVL (Nodo *pRaiz);
int nivel;
int FB (Nodo *pRaiz);
int altura (Nodo *pRaiz);
void RSE (Nodo **ppRaiz);
void RSD (Nodo **ppRaiz);
int balanceamento(Nodo **ppRaiz);
int balancaEsq (Nodo **ppRaiz);
int balancaDir (Nodo **ppRaiz);
int verificaArvAVL (Nodo *pRaiz);
void segCenario();


int main () {
    Nodo *pRaiz = NULL;
    registro reg;
    int i;
    int numNodos, numRand;

    printf("Digite o numero de nodos: ");
    scanf("%d", &numNodos);
    getchar();
    
    srand(time(0));

    for (i=0; i < numNodos; i++){
        numRand = rand() % 100;
        reg.chave = numRand;
        insere(&pRaiz, reg);
    }

    printf("Primeiro Cenário:\n");
    imprimeAVL(pRaiz, nivel);

    if(verificaArvAVL(pRaiz)) {
        printf("\nA árvore digitada é uma árvore AVL.");
    } else {
        printf("\nA árvore digitada não é uma árvore AVL");
    }

    limpaAVL(pRaiz);//para fazer o segundo cenário
    segCenario();

    return 0;
}

int altura(Nodo *pRaiz) 
{
    int iEsq, iDir;

    if (pRaiz == NULL) {
        return 0;
    }

    iEsq = altura(pRaiz -> pEsq);
    iDir = altura(pRaiz -> pDir);

    if (iEsq > iDir){
        return iEsq + 1;
    } else {
        return iDir + 1;
    }
    nivel++;
}

void RSE (Nodo** ppRaiz) 
{ 
    Nodo *pAux;

    pAux = (*ppRaiz) -> pDir;
    (*ppRaiz)->pDir = pAux -> pEsq;
    pAux -> pEsq = (*ppRaiz);
    (*ppRaiz) = pAux;
}

void RSD (Nodo **ppRaiz) 
{
    Nodo *pAux;

    pAux = (*ppRaiz) -> pEsq;
    (*ppRaiz) -> pEsq = pAux -> pDir;
    pAux -> pDir = (*ppRaiz);
    (*ppRaiz) = pAux;
}

int balancaEsq(Nodo **ppRaiz) 
{
    int FBE = FB( (*ppRaiz) -> pEsq );

    if (FBE >= 0) {
        RSD(ppRaiz);
        return 1;
    } else if (FBE < 0) { 
        RSE ( &((*ppRaiz) -> pEsq) );
        RSD (ppRaiz);
        return 1;
    }
    return 0;
}

int balancaDir (Nodo **ppRaiz) 
{
    int FBD = FB( (*ppRaiz) -> pDir );
    
    if (FBD <= 0) { 
        RSE (ppRaiz);
        return 1;
    } else if (FBD > 0) {
        RSD ( &((*ppRaiz) -> pDir) );
        RSE (ppRaiz);
        return 1;
    }
    return 0;
}


int balanceamento(Nodo **ppRaiz) 
{
    int fb = FB(*ppRaiz);

    if (fb > 1) 
    {
        return balancaEsq(ppRaiz);
    } 
    else if (fb < -1)
    {
        return balancaDir(ppRaiz);
    } 
    else 
        return 0;
    
}

int insere (Nodo **ppRaiz, registro numRegistro) 
{
    if (*ppRaiz == NULL) 
    {
        *ppRaiz = (Nodo*)malloc(sizeof(Nodo));
        (*ppRaiz) -> reg = numRegistro;
        (*ppRaiz) -> pEsq = NULL;
        (*ppRaiz) -> pDir = NULL;
        return 1;

    } 
    else if ((*ppRaiz) -> reg.chave > numRegistro.chave ) 
    {
        if (insere( &(*ppRaiz) -> pEsq, numRegistro )){
            if (balanceamento(ppRaiz)) {
                return 0;
            } 
            else {
                return 1;
            }
        }
    } 
    else if ((*ppRaiz) -> reg.chave < numRegistro.chave ) 
    {
        if (insere (&(*ppRaiz) -> pDir, numRegistro)) {
            if (balanceamento(ppRaiz)) {
                return 0;
            } 
            else {
                return 1;
            }
        }
    } 
    else 
        return 0;

    return 0;
}


int verificaArvAVL (Nodo *pRaiz) { 
    int fb;
    fb = FB (pRaiz);

    if (pRaiz == NULL) {
        return 1;
    }

    if (!verificaArvAVL(pRaiz -> pEsq)) {
        return 0;
    }

    if (!verificaArvAVL(pRaiz -> pDir)) {
        return 0;
    }

    if ((fb < -1) || (fb > 1)) {
        return 0;
    } else {
        return 1;
    }
}

int FB(Nodo *pRaiz)
{  
    if (pRaiz == NULL) {
        return 0;
    }

    return altura(pRaiz -> pEsq) - altura(pRaiz -> pDir);
}

void imprimeAVL (Nodo *pRaiz, int nivel) { 
    int i;
    if(pRaiz == NULL) return;
    if(pRaiz){
        imprimeAVL(pRaiz->pDir, nivel+1);
        printf("\n\n");

        for(i=0; i<nivel; i++){printf("\t");}
        printf("%ld", pRaiz -> reg.chave);
        imprimeAVL(pRaiz->pEsq, nivel+1);
    }
}

void limpaAVL (Nodo *pRaiz) {
    if (pRaiz == NULL) return;

    limpaAVL(pRaiz -> pEsq);
    limpaAVL(pRaiz -> pDir);

    free(pRaiz);
}

int Remove(registro Reg, Nodo **ppRaiz){
    Apontador aux;

    if(*ppRaiz == NULL){
        printf("ERRO: nao tem registro na arvore\n");
        return 0;
    }
    if(Reg.chave < (*ppRaiz)->reg.chave){    
        Remove(Reg, &(*ppRaiz)->pEsq);
        return 0; 
    }
    if(Reg.chave > (*ppRaiz)->reg.chave){
        Remove(Reg, &(*ppRaiz)->pDir);
        return 0;
    }

    if((*ppRaiz)->pDir == NULL){
        aux = *ppRaiz;
        *ppRaiz= (*ppRaiz)->pEsq;
        free(aux);
        return 0;
    }
    aux = *ppRaiz;
    *ppRaiz = (*ppRaiz)->pDir;
    free(aux);
}


void segCenario(){
    registro reg;

    printf("Segundo Cenário:\n");
    
    //cria uma árvore pra esse caso:
    Nodo *pRaiz = NULL;

    //#########################################
    printf("\n\n#########################################\n");
    printf("Case 1a: Insert 15\n");

    reg.chave = 20;
    insere(&pRaiz, reg);
    reg.chave = 4;
    insere(&pRaiz, reg);
    printf("Árvore antes do 15:\n");
    imprimeAVL(pRaiz, nivel);
    printf("\n");

    printf("Árvore depois do 15:\n");
    reg.chave = 15;
    insere(&pRaiz, reg);
    imprimeAVL(pRaiz, nivel);

    //limpa tudo
    limpaAVL(pRaiz);
    printf("\n#########################################\n\n");
    //#########################################



    //#########################################
    printf("\n\n#########################################\n");
    printf("Case 2a: Insert 15\n");

    //recria uma árvore pra esse caso:
    pRaiz = NULL;
    //inserir os dados nos nodos:
    reg.chave = 20;
    insere(&pRaiz, reg);
    reg.chave = 4;
    insere(&pRaiz, reg);
    reg.chave = 26;
    insere(&pRaiz, reg);
    reg.chave = 3;
    insere(&pRaiz, reg);
    reg.chave = 9;
    insere(&pRaiz, reg);
    //-------------------------
    printf("Árvore antes do 15:\n");
    imprimeAVL(pRaiz, nivel);
    printf("\n");
    printf("Árvore depois do 15:\n");
    reg.chave = 15;
    insere(&pRaiz, reg);
    imprimeAVL(pRaiz, nivel);
    
    //limpa tudo
    limpaAVL(pRaiz);
    printf("\n#########################################\n\n");
    //#########################################



    //#########################################
    printf("\n\n#########################################\n");
    printf("Case 3a: Insert 15\n");

    //recria uma árvore pra esse caso:
    pRaiz = NULL;
    //inserir os dados nos nodos:
    reg.chave = 20;
    insere(&pRaiz, reg);
    reg.chave = 4;
    insere(&pRaiz, reg);
    reg.chave = 26;
    insere(&pRaiz, reg);
    reg.chave = 3;
    insere(&pRaiz, reg);
    reg.chave = 9;
    insere(&pRaiz, reg);
    reg.chave = 2;
    insere(&pRaiz, reg);
    reg.chave = 7;
    insere(&pRaiz, reg);
    reg.chave = 11;
    insere(&pRaiz, reg);
    reg.chave = 21;
    insere(&pRaiz, reg);
    reg.chave = 30;
    insere(&pRaiz, reg);

    //--------------------
    printf("Árvore antes do 15:\n");
    imprimeAVL(pRaiz, nivel);
    printf("\n");

    printf("Árvore depois do 15:\n");
    reg.chave = 15;
    insere(&pRaiz, reg);
    imprimeAVL(pRaiz, nivel);

    //limpa tudo
    limpaAVL(pRaiz);
    printf("\n#########################################\n\n");
    //#########################################



    //#########################################
    printf("\n\n#########################################\n");
    printf("Case 1b: Insert 8\n");

    //recria uma árvore pra esse caso:
    pRaiz = NULL;
    //inserir os dados nos nodos:
    reg.chave = 20;
    insere(&pRaiz, reg);
    reg.chave = 4;
    insere(&pRaiz, reg);

    //--------------------
    printf("Árvore antes do 8:\n");
    imprimeAVL(pRaiz, nivel);
    printf("\n");

    printf("Árvore depois do 8:\n");
    reg.chave = 8;
    insere(&pRaiz, reg);
    imprimeAVL(pRaiz, nivel);
    
    //limpa tudo
    limpaAVL(pRaiz);
    printf("\n#########################################\n\n");
    //#########################################



    //#########################################
    printf("\n\n#########################################\n");
    printf("Case 2b: Insert 8\n");

    //recria uma árvore pra esse caso:
    pRaiz = NULL;
    //inserir os dados nos nodos:
    reg.chave = 20;
    insere(&pRaiz, reg);
    reg.chave = 4;
    insere(&pRaiz, reg);
    reg.chave = 26;
    insere(&pRaiz, reg);
    reg.chave = 3;
    insere(&pRaiz, reg);
    reg.chave = 9;
    insere(&pRaiz, reg);

    //---------
    printf("Árvore antes do 8:\n");
    imprimeAVL(pRaiz, nivel);
    printf("\n");

    printf("Árvore depois do 8:\n");
    reg.chave = 8;
    insere(&pRaiz, reg);
    imprimeAVL(pRaiz, nivel);
    
    //limpa tudo
    limpaAVL(pRaiz);
    printf("\n#########################################\n\n");
    //#########################################



    //#########################################
    printf("\n\n#########################################\n");
    printf("Case 3b: Insert 8\n");

    //recria uma árvore pra esse caso:
    pRaiz = NULL;
    //inserir os dados nos nodos:
    reg.chave = 20;
    insere(&pRaiz, reg);
    reg.chave = 4;
    insere(&pRaiz, reg);
    reg.chave = 26;
    insere(&pRaiz, reg);
    reg.chave = 3;
    insere(&pRaiz, reg);
    reg.chave = 9;
    insere(&pRaiz, reg);
    reg.chave = 21;
    insere(&pRaiz, reg);
    reg.chave = 30;
    insere(&pRaiz, reg);
    reg.chave = 2;
    insere(&pRaiz, reg);
    reg.chave = 7;
    insere(&pRaiz, reg);
    reg.chave = 11;
    insere(&pRaiz, reg);

    //---------------
    printf("Árvore antes do 8:\n");
    imprimeAVL(pRaiz, nivel);
    printf("\n");
    printf("Árvore depois do 8:\n");
    reg.chave = 8;
    insere(&pRaiz, reg);
    imprimeAVL(pRaiz, nivel);
    
    //limpa tudo
    limpaAVL(pRaiz);
    printf("\n#########################################\n\n");
    //#########################################

}
