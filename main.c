#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include "projeto2.h"
/**
***
****             @autor                   Reidner sousa
******           @Version                 1.1
*******          @DataUltimaModificacao   07/01/2022 21:57
*******          @NomeCodigo              Projeto 2
******           @TipoCodigo              Lista Pilhas
*****            @CoisasParaFazer         Desenvolver um  algoritmo que utlizar notação polonesa
                                          Criar uma função que quebra as string
****
**/


typedef struct no1
{
    unsigned char  valor;
    struct no*proximo;
} No1;

No1 * empilhar(No1*pilha_lista, unsigned char  num)
{
    No1*novo=malloc(sizeof(No1));

    if(novo)
    {
        novo->valor=num;
        novo->proximo=pilha_lista;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria! \n");
    return NULL;

}

No1 * desempilhar(No1**pilha_lista)
{
    No1*remover=NULL;

    if(*pilha_lista)
    {
        remover=*pilha_lista;
        *pilha_lista=remover->proximo;
    }
    else
        printf("\tPilha vazia \n");
    return remover;
}



/***TEStes   **/

/**         @Nomefuncao operation_deleta_dps
*           @Funcaoque
*
*/
char operation_deleta_dps ( char a[], char b[], char x)
{


    switch(x)
    {
    case '+':
        strcat(a,x);
        strcat(a,b);
        return a;
        break;

    case '-':
        strcat(a,x);
        strcat(a,b);
        return a;
        break;
    case '/':
        strcat(a,x);
        strcat(a,b);
        return a;
        break;
    case '*':
        strcat(a,x);
        strcat(a,b);
        return a;
        break;
    default:
        return 0.0;

    }
}


/*


/***
            recebe infixado e  retorna fixado

            infixado            pos fixado
            (A+B*C)               ABC*+
        (A*(B+C)/D-E)	        ABC+*D/E-
***/
/*
unsigned resolve (unsigned char x[])
{
    unsigned *pt;
    unsigned num;
    No1 * n2, *n2, *pilha_lista=NULL;
    pt=strtok(x,"(",);
    while(pt)
    {
        if(pt[0]=='+'||pt[0]=='-'||pt[0]=='/'||pt[0]=='*')
        {
            n1=desempilhar(&pilha_lista);
            n2=desempilhar(&pilha_lista);

            num =operation(n2->valor, n1->valor, pt[0]) ;
            pilha_lista = empilhar(pilha_lista, num);
            free(n1);
            free(n2);
        }
        else{
            printf("Faz algo\n");
            pilha_lista = empilhar(pilha_lista, num);
        }
        pt=strtok(NULL," ");
    }

 */
/******
4) Notação pos-fixa polonesa reversa (calculadora HP)
    infixa                      Pos-fixa
    (51+13*13)                  51 13 12 * +                R=207
    (5*(3+2)/4-6)               5 3 2 + * 4 / 6 -           R=0,25
*****/


/*
    4) Notação pos-fixa polonesa reversa (calculadora HP)
    infixa                      Pos-fixa
    (51+13*13)                  51 13 12 * +                R=207
    (5*(3+2)/4-6)               5 3 2 + * 4 / 6 -           R=0,25
    (5+3+2*4-6*7*1)             5 3 + 2 4 * + 6 7 * 1 * -   R= -26
    (5*(3+(2)*(4+(6*(7+1)))))   5 3 2 4 6 7 1 + * + * + *   R= 535
*/

/**             @Nome "teste"
*               @Funcao que recebe 3 string   a=vogal b=vogal e x=sinal de opereção e retorna uma
*               String com todos os 3 valores juntos
*
*/
char  *teste (char a[10],char b[10],char x[10])
{
    char *res;
    res=malloc(20*sizeof(char));



    if(strcmp(x,"+")==0)
    {

        printf("iguais\n");
        strcat(a,x);
        strcat(a,b);
        res=a;
        return res;
    }
     if(strcmp(x,"-")==0)
    {

        printf("iguais\n");
        strcat(a,x);
        strcat(a,b);
        res=a;
        return res;
    }
    if(strcmp(x,"*")==0)
    {

        printf("iguais\n");
        strcat(a,x);
        strcat(a,b);
        res=a;
        return res;
    }
    if(strcmp(x,"/")==0)
    {

        printf("iguais\n");
        strcat(a,x);
        strcat(a,b);
        res=a;
        return res;
    }


}

int main()
{


    char ex[50]= {"(A+B*C)/0"}; //= ABC*+
    unsigned *pt;
    pt=strtok(ex,"(");
    printf("pt %s\n",pt);
    printf("ex %s\n",ex);

    char a[30]="A";
    char b[36]="B";
    char x[2]="/";
    char l[30];

    printf("%s\n",teste(a,b,x));

    // printf("%s\n",operation(a,b,x));





    system("pause");

    return 0;

}















