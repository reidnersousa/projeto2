#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhadechars.h"


struct no
{
    int  info;
    struct no* prox;
};

typedef struct no No;
struct pilha
{

    struct no* prim;
};




//função criar pilha ; pilha com lista
Pilha* cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

/* função auxiliar: insere no início */
/**esse char ta certo?*/
No* ins_ini_char (No* l, int cha)
{
    No* p = (No*) malloc(sizeof(No));

    p->info = cha;

    //strcpy(p->info,cha);
    p->prox = l;
    return p;
}
/* função auxiliar: retira do início */
No* ret_ini_char (No* l)
{
    No* p = l->prox;
    free(l);
    return p;
}



void push (Pilha* p, int c)
{
    p->prim = ins_ini_char(p->prim,c);
}
void  pop (Pilha* p)
{

    if (vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }



    //strcpy(p->info,cha);
    //p->info = v;
    //(p->prim->info,c);

    No*aux;
    aux=p->prim;
    p->prim=p->prim->prox;
    free(aux);

    return ;
}

int vazia (Pilha* p)
{
    return (p->prim==NULL);
}

void libera (Pilha* p)
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
void imprime (Pilha* p)
{
    No* q;
    for (q=p->prim; q!=NULL; q=q->prox)

        //erro no imprimir
        printf("%d\n",q->info);

    // printf(p->prim->info);
}

void imprime_char(Pilha*p)
{
    No*q;
    if (vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    for(q=p->prim; q!=NULL; q=q->prox)
        printf("%s\n",q->info);
}


/**Funções do deve   Implementação Biblioteca (Pilhas Dinâmicas) */
//empilha
void empilha(Pilha*pi,char val )
{
    No* p = (No*) malloc(sizeof(No));
    p->info = val;
    p->prox = pi->prim;
    pi->prim = p;
}


///
int pilhavazia(Pilha *pi)
{
    return (pi->prim==NULL);
}

void  desempilha (Pilha* pi)
{
    if (pilhavazia(pi))
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }


    No*aux;
    aux=pi->prim;
    pi->prim=pi->prim->prox;
    free(aux);

    return ;
}

Pilha* criaPilha (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}


/*****************************
*
*                       Funções do projeto 2 que faltam
*
*
*
********************************/
/* Arrumar pilha Cocola na forma inversa  */
void ArrumaPilha(Pilha*p,Pilha*secundaria)
{
    No*q;
    for(q=p->prim; q!=NULL; q=q->prox)
    {
        //printf("ER\n");
        push(secundaria,q->info);
    }
}



void AuxPilhaTer(Pilha*p,Pilha*terciaria)
{
    No*q;

    for( q =p ; q->info  != '('; q=q->prox);

    if(q==NULL)
    {
        printf("Não cadastrado");
        return ;
    }
    // if(q->prox->info =='A'){
    printf("Otario");
    //}
    printf("Faz algo \n");


}


void ajudaEu(Pilha*p, int tamanhoPilha,Pilha *pTer)
{
    No*q;
    int i=0;
    int v[10];
    int tamanho=tamanhoPilha;
    for(q=p->prim; q!=NULL; q=q->prox)
    {
        i++;
        printf("[%d]%s\n",i,q->info);
        // printf("%d\n",q->info);
        if(strcmp(q->info,"(")==0)
        {
            printf("Funcionar \n ");
            pop(p);
            tamanhoPilha-1;
        }
        if(strcmp(q->info,")")==0)
        {
            imprime_char_Unico(p,tamanhoPilha);
            //ArrumaPilha1So(p,pTer);
        }



    }

    //if(strcmp(q->info,""))

}


//função que pegar o elemento da pilha p e coloca na pilha sec
void ArrumaPilha1So(Pilha*p,Pilha*secundaria)
{
    No*q;
    q=p->prim;
    //for(q=p->prim; q!=NULL; q=q->prox){
    printf("Feito com Arruma pilha1 so \n");
    push(secundaria,q->info);
    //}
}

void imprime_char_Unico(Pilha*p,int tama)
{
    No*q;
    int indice;
    q=p->prim;
    for(indice=0; indice<tama ; indice++)
    {
        printf("Imprimiu viu char Unico %s\n",q->info);
    }

}
//função que tira os elementos de uma pilha .
void LimpaPilha(Pilha *texto,int tamanho)
{
    int ind;
    for(ind=0; ind<tamanho; ind++)
    {
        pop(texto);
    }
}
//função que quebra uma string e retorna o seu tamanho e colocas as palavra numa pilha
int QuebraString(Pilha * texto, char palavra[40],char *sub )
{
    int tamanho=0;
    int pesq=0,pdir=0;
    sub=strtok(palavra," ");
    while(sub != NULL)
    {
        printf("\n%s",sub);
        push(texto,sub);
        tamanho++;
        if(strcmp(sub,"(")==0)
        {
            pesq++;
            printf("( >>%d\n",pesq);
        }
        if(strcmp(sub,")")==0)
        {
            pdir++;
            printf("( >>%d\n",pdir);
        }


        sub=strtok(NULL," ");

    }
    return tamanho;

}
