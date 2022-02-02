

#define MAX 50


/*
Autor : Reidner Sousa dos Santos
Projeto : Pilha
Versao : 1.2
Ultima atualização : 10/11/2021 11:15

*/


/********************************************************
                    IMPLEMENTAÇÃO DE PILHA COM VETOR
***********************************************************/
struct pilha
{
    int n;
    float vet[MAX];
};

struct pilhaVectorChar
{
    char palavra;
    float vet[MAX];
};

typedef struct pilha Pilha;

/*Criar uma pilha com vetor */
Pilha* cria_vetor (void);
/*Função que inserir um elemento na pilha;pilha  com vector */
void push_vetor (Pilha* p, float v);
/*Função que retirar um elemento da pilha ; pilha com vector*/
float pop_vetor (Pilha* p);
/*Função que verifica se a pilha é vazia ;pilha com vector*/
int vazia_Vetor (Pilha* p);
/*função para liberar a memória alocada pela pilha ; ´pilha com vector */
void libera_vetor (Pilha* p);


/**********************************************************************************8
                        IMPLEMENTAÇÃO DE PILHA COM LISTA
*****************************************************************************/

struct no
{
    float info;
    struct no* prox;
};
typedef struct no No;

typedef struct pilha_lista Pilha_lista;
struct pilha_lista
{
    No* prim;
};

/*A função cria aloca a estrutura da pilha e inicializa a lista como sendo vazia.*/
Pilha_lista* cria_lista (void);

/* função auxiliar: insere no início */
No* ins_ini (No* l, float v);

/* função auxiliar: retira do início */
No* ret_ini (No* l);

/*função que inserir um elemento na pilha ; pilha com lista */
void push_lista (Pilha_lista* p, float v);
/*Função que retirar um elemento na pilha ; pilha com lista */
float pop_lista (Pilha_lista* p);
/*A pilha estará vazia se a lista estiver vazia ; pilha com lista */
int vazia_lista (Pilha_lista* p);
/*vai liberar os elementos armazenado na memoria */
void libera_lista (Pilha_lista* p);
/*vai imprimiro os elementos da pilha ; pilha com lista */
void imprime_lista (Pilha_lista* p);

