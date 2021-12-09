
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
No* ins_ini (No* l, float v)
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



void push_lista (Pilha_lista* p, float v)
{
    /*recebe auxilio da função insere */
    p->prim = ins_ini(p->prim,v);
}
float pop_lista (Pilha_lista* p)
{
    float v;
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
        printf("%f\n",q->info);
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

