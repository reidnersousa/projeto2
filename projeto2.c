
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto2.h"

Pilha_lista* cria_lista (void)
{
    Pilha_lista* p = (Pilha_lista*) malloc(sizeof(Pilha_lista));
    p->prim = NULL;
    return p;
}




/* função auxiliar: insere no início */
No* ins_ini (No* l, unsigned char v)
{
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = l;
    return p;
}
/* função auxiliar: retira do início */
No* ret_ini (No* l)
{
    No* p = l->prox;
    free(l);
    return p;
}



void push_lista (Pilha_lista* p, unsigned char v)
{
    /*recebe auxilio da função insere */
    p->prim = ins_ini(p->prim,v);
}
float pop_lista (Pilha_lista* p)
{
    unsigned char v;
    if (vazia_lista(p))
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    v = p->prim->info;
    p->prim = ret_ini(p->prim);
    return v;
}

int vazia_lista (Pilha_lista* p)
{
    return (p->prim==NULL);
}

void libera_lista (Pilha_lista* p)
{
    No* q = p->prim;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}



/* imprime: versão com lista */
void imprime_lista (Pilha_lista* p)
{
    No* q;
    for (q=p->prim; q!=NULL; q=q->prox)
        printf("%c\n",q->info);
}

/*****************************************************************************************************************************************************
                                Calculadora Polenesa
************************************************************************************************************************************/

Calc* cria_calc (char* formato)
{
    Calc* c = (Calc*) malloc(sizeof(Calc));
    strcpy(c->f,formato);
    //c->p = cria(); /* cria pilha vazia */
    c->p=cria_lista();/*Cria pilha vazia pilha com lista */
    return c;
}

void operando (Calc* c, float v)
{

    /* empilha operando */
    push_lista(c->p,v);
    /* imprime topo da pilha */

    printf("Valor inserido");
    printf(c->f,v);
}

void operador (Calc* c, char op)
{
    float v1, v2, v;
    /* desempilha operandos */
    if (vazia_lista(c->p))
        v2 = 0.0;
    else
        v2 = pop_lista(c->p);
    if (vazia_lista(c->p))
        v1 = 0.0;
    else
        v1 = pop_lista(c->p);
    /* faz operação */
    switch (op)
    {
    case '+':
        v = v1+v2;
        break;
    case '-':
        v = v1-v2;
        break;
    case '*':
        v = v1*v2;
        break;
    case '/':
        v = v1/v2;
        break;
    }
    /* empilha resultado */
    push_lista(c->p,v);
    /* imprime topo da pilha */
    //vai imprimir o valor final .Por exemplo vai imprimir o valor de v+v ou v/v

    switch (op)
    {
    case '+':
        printf("Resultado da soma ");
        break;

    case '-':
        printf("Resultado da subtracao ");
        break;

    case '/':
        printf("Resultado da divisao ");
        break;

    case '*':
        printf("Resultado da multiplicacao");
        break;
    }
    printf(c->f,v);
}

void libera_calc (Calc* c)
{
    libera_lista(c->p);
    free(c);
}

/****************************************************************
                        Exemplo
********************************************************************/


No2 * empilhar2(No2*pilha_lista , float  num){
    No2*novo=malloc(sizeof(No2));

    if(novo){
        novo->valor=num;
        novo->proximo=pilha_lista;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria! \n");
    return NULL;

}


No2 * desempilhar2(No2**pilha_lista){
    No2*remover=NULL;

    if(*pilha_lista){
        remover=*pilha_lista;
        *pilha_lista=remover->proximo;
    }
    else
        printf("\tPilha vazia \n");
    return remover;
}


float operacao2(float a , float b , char x)
{
    switch(x){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;

    }
}



float resolver_expressao2(char x[]){
    char *pt;
    float  num;
    No2 * n1, *n2 ,*pilha_lista=NULL;
    pt=strtok(x," ");
    while(pt){
        if(pt[0]=='+'||pt[0]=='-'||pt[0]=='/'||pt[0]=='*'){
            n1=desempilhar2(&pilha_lista);
            n2=desempilhar2(&pilha_lista);
            num =operacao2(n2->valor , n1->valor , pt[0]) ;
            pilha_lista = empilhar2(pilha_lista , num);
            free(n1);
            free(n2);
        }
        else{
            num= strtol(pt,NULL , 10);
            pilha_lista = empilhar2(pilha_lista , num);
        }
        pt=strtok(NULL ," ");
    }
    n1 = desempilhar2(&pilha_lista);
    num = n1->valor;
    free(n1);
    return num;
}

