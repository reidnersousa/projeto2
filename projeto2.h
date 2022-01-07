

//fun��o criar pilha ; pilha com lista


struct no
{

    unsigned char   info;
    struct no* prox;
};
typedef struct no No;

typedef struct pilha_lista Pilha_lista;
struct pilha_lista
{
    No* prim;
};

/*A fun��o cria aloca a estrutura da pilha e inicializa a lista como sendo vazia.*/
Pilha_lista* cria_lista (void);

/* fun��o auxiliar: insere no in�cio */
No* ins_ini (No* l, unsigned char v);

/* fun��o auxiliar: retira do in�cio */
No* ret_ini (No* l);

/*fun��o que inserir um elemento na pilha ; pilha com lista */
void push_lista (Pilha_lista* p, unsigned char  v);
/*Fun��o que retirar um elemento na pilha ; pilha com lista */
float pop_lista (Pilha_lista* p);
/*A pilha estar� vazia se a lista estiver vazia ; pilha com lista */
int vazia_lista (Pilha_lista* p);
/*vai liberar os elementos armazenado na memoria */
void libera_lista (Pilha_lista* p);
/*vai imprimiro os elementos da pilha ; pilha com lista */
void imprime_lista (Pilha_lista* p);


/*********************************************************************************************
                    Calculadora polonesa
*******************************************************************************************/


/**Pilha com lista  **/

struct no_cal
{

    int info;
    struct no_cal* prox;
};
typedef struct no_cal No_cal;

typedef struct pilha_cal Pilha_cal;
struct pilha_cal
{
    No_cal* prim;
};

/**Fim da pilha com lista **/


/* Arquivo que define a interface da calculadora */
typedef struct calc Calc;
/* fun��es exportadas */
Calc* cria_calc (char * f);
void operando (Calc* c, float v);
void operador (Calc* c, char op);
void libera_calc (Calc* c);

struct calc
{
    char f[21]; /* formato para impress�o */
    Pilha_cal* p; /* pilha de operandos */
};


/**************************************
                Exemplo
*********************************/

// e o tabelo ASCI o float vai ser
struct no2
{

    float  valor;
    struct no2* proximo;
};
typedef struct no2 No2;


