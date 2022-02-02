#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/********************************************************
                    IMPLEMENTAÇÃO DE PILHA COM VETOR
***********************************************************/
Pilha* cria_vetor (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; /* inicializa com zero elementos */
    return p;
}


void push_vetor (Pilha* p, float v)
{
    if (p->n == MAX)   /* capacidade esgotada */
    {
        printf("Capacidade da pilha estourou.\n");
        exit(1); /* aborta programa */
    }
    /* insere elemento na próxima posição livre */
    p->vet[p->n] = v;
    p->n++;
}


float pop_vetor (Pilha* p)
{
    float v;
    if (vazia_Vetor(p))
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    /* retira elemento do topo */
    v = p->vet[p->n-1];
    p->n--;
    return v;
}
int vazia_Vetor (Pilha* p)
{
    return (p->n == 0);
}


void libera_vetor (Pilha* p)
{
    free(p);
}

/* imprime: versão com vetor */
void imprime_Vetor (Pilha* p)
{
    int i;
    for (i=p->n-1; i>=0; i--)
        printf("%f\n",p->vet[i]);
}

/**********************************************************************************8
                        IMPLEMENTAÇÃO DE PILHA COM LISTA
*****************************************************************************/


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
