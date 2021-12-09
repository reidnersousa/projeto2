#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include "projeto2.h"

typedef struct no1{
        float valor;
        struct no*proximo;
}No1;

No1 * empilhar(No1*pilha_lista , float num){
    No1*novo=malloc(sizeof(No1));

    if(novo){
        novo->valor=num;
        novo->proximo=pilha_lista;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria! \n");
    return NULL;

}

No1 * desempilhar(No1**pilha_lista){
    No1*remover=NULL;

    if(*pilha_lista){
        remover=*pilha_lista;
        *pilha_lista=remover->proximo;
    }
    else
        printf("\tPilha vazia \n");
    return remover;
}


float operacao(float a , float b , char x)
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


float resolver_expressao(char x[]){
    char *pt;
    float  num;
    No1 * n1, *n2 ,*pilha_lista=NULL;
    pt=strtok(x," ");
    while(pt){
        if(pt[0]=='+'||pt[0]=='-'||pt[0]=='/'||pt[0]=='*'){
            n1=desempilhar(&pilha_lista);
            n2=desempilhar(&pilha_lista);
            num =operacao(n2->valor , n1->valor , pt[0]) ;
            pilha_lista = empilhar(pilha_lista , num);
            free(n1);
            free(n2);
        }
        else{
            num= strtol(pt,NULL , 10);
            pilha_lista = empilhar(pilha_lista , num);
        }
        pt=strtok(NULL ," ");
    }
    n1 = desempilhar(&pilha_lista);
    num = n1->valor;
    free(n1);
    return num;
}

/*
    4) Notação pos-fixa polonesa reversa (calculadora HP)
    infixa                      Pos-fixa
    (51+13*13)                  51 13 12 * +                R=207
    (5*(3+2)/4-6)               5 3 2 + * 4 / 6 -           R=0,25
    (5+3+2*4-6*7*1)             5 3 + 2 4 * + 6 7 * 1 * -   R= -26
    (5*(3+(2)*(4+(6*(7+1)))))   5 3 2 4 6 7 1 + * + * + *   R= 535
*/
int main()
{
    //char exp [50]={"51 13 12 * +"};
    //char exp [50]={"5 3 2 + * 4 / 6 -"};
    char exp [50]={"5 3 2 4 6 7 1 + * + * + *"};

    printf("Resultado de %s :\t", exp);
    printf("%f \n",resolver_expressao(exp));
    /*
    Pilha_lista*p=cria_lista();
    push_lista(p,2);
    imprime_lista(p);
    push_lista(p,3);
    */

    /*
    char c;
    float v;
    Calc* calc;
    // cria calculadora com precisão de impressão de duas casas decimais
    printf("Digite  q para sair do loop\n");
    printf("Digite o numero \n");

    calc = cria_calc("%.2f\n");
    do
    {
        // le proximo caractere nao branco
        scanf(" %c",&c);
        // verifica se e' operador valido
        if (c=='+' || c=='-' || c=='*' || c=='/')
        {
            operador(calc,c);
        }
        // devolve caractere lido e tenta ler número
        else
        {
            ungetc(c,stdin);
            if (scanf("%f",&v) == 1)
                operando(calc,v);
        }
    }
    while (c!='q');
    libera_calc(calc);

    */

    system("pause");

    return 0;

}















