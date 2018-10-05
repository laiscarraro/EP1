// cd C:\Users\USP\Desktop\AED1\EP2\EP2
// gcc EP2.c -o EP2.exe
// EP2.exe

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s {
    int tipo; //1=elemento 2=sublista

    union{
        int chave;
        struct s* sublista;
    };

    struct s* prox;

} NO;

char* nroUSP1();
char* nroUSP2();
char *grupo();
void exibir(NO* p);

// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
char* grupo() {
    return("14");
}

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
// ignore os warning to compilador, se houver
char* nroUSP1() {
    return("10391184");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
// ignore os warning to compilador, se houver
char* nroUSP2() {
    return("10687638");
}

NO* tirarSublistas(NO* inicio, NO* *ult) {
    NO* subInicio = NULL;
    NO* subUltimo;
    NO* p = inicio;
    while(p && p->prox) {
        printf("While tirarSublistas\n");
        if(p->tipo == 2) { //So para quando o primeiro da lista e do tipo 2
            printf("Primeira do tipo 2\n");
            subInicio = p;
            subUltimo = subInicio;
            exibir(subInicio);
        }
        if(p->prox->tipo == 2) {
            printf("Prox e do tipo 2\n");
            if(!subInicio) {//Primeira sublista encontrada
                printf("Primeira sublista encontrada\n");
                subInicio = p->prox;
                subUltimo = subInicio;
                exibir(subInicio);
            } else {
                printf("Outras sublistas encontradas\n");
                subUltimo->prox = p->prox;
                subUltimo = subUltimo->prox;
                exibir(subInicio);
            }
            if(!p->prox->prox) {
                printf("Antes do break\n");
                p->prox = NULL;
                break;
            }
            p->prox = p->prox->prox;
        }
        p = p->prox;
    }
    *ult = p;
    return subInicio;
}

bool temSub(NO* inicio) {
    while(inicio) {
        if(inicio->tipo == 2) return true;
        inicio = inicio->prox;
    }
    return false;
}

// o EP consiste em implementar esta funcao
NO* listarChaves(NO* entrada) {
    NO* ult = NULL;
    NO* resp;
    while(temSub(entrada)) {
        printf("Entrou no temSub\n");
        resp = tirarSublistas(entrada, &ult);
        while(resp->prox) {
            printf("Reconecta\n");
            ult->prox = resp->sublista;
            while(ult->prox) ult = ult->prox;
            resp = resp->prox;
        }
        resp = tirarSublistas(entrada, &ult);
        ult->prox = resp->sublista;
        ult = ult->prox;
        ult->prox = resp->prox->sublista;
    }
    return entrada;
}

NO* novoNo(bool no, int chave) {
    NO* novo = (NO*) malloc(sizeof(NO));
    if(no) {
        novo->tipo = 1;
        novo->chave = chave;
    } else {
        novo->tipo = 2;
        novo->sublista = NULL;
    }
    novo->prox = NULL;
    return novo;
}

void exibir(NO* p) {
    while(p) {
        if(p->tipo == 1) printf("%i\n", p->chave);
        else exibir(p->sublista);
        p = p->prox;
    }
}

//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------



int main() {

    NO* p = NULL;

    // aqui vc pode incluir codigo para inserir elementos
    // de teste na sua lista apontada por p

    p = (NO*) malloc(sizeof(NO));
    p->tipo = 1;
    p->chave = 1;

    NO* inicio = p;

    p->prox = (NO*) malloc(sizeof(NO));
    p = p->prox;
    p->tipo = 2;
    NO* sub1 = p;

    p->prox = (NO*) malloc(sizeof(NO));
    p = p->prox;
    p->tipo = 1;
    p->chave = 2;

    p->prox = (NO*) malloc(sizeof(NO));
    p = p->prox;
    p->tipo = 2;
    NO* sub2 = p;

    p->prox = (NO*) malloc(sizeof(NO));
    p = p->prox;
    p->tipo = 1;
    p->chave = 3;

    p->prox = (NO*) malloc(sizeof(NO));
    p = p->prox;
    p->tipo = 2;
    NO* sub3 = p;

    p->prox = (NO*) malloc(sizeof(NO));
    p = p->prox;
    p->tipo = 1;
    p->chave = 4;

    p->prox = (NO*) malloc(sizeof(NO));
    p = p->prox;
    p->tipo = 2;
    NO* sub4 = p;

    sub1->sublista = (NO*) malloc(sizeof(NO));
    sub1 = sub1->sublista;
    sub1->tipo = 1;
    sub1->chave = 5;

    sub1->prox = (NO*) malloc(sizeof(NO));
    sub1 = sub1->prox;
    sub1->tipo = 2;
    NO* sub5 = sub1;

    sub1->prox = (NO*) malloc(sizeof(NO));
    sub1 = sub1->prox;
    sub1->tipo = 1;
    sub1->chave = 6;

    sub2->sublista = (NO*) malloc(sizeof(NO));
    sub2 = sub2->sublista;
    sub2->tipo = 1;
    sub2->chave = 7;

    sub3->sublista = (NO*) malloc(sizeof(NO));
    sub3 = sub3->sublista;
    sub3->tipo = 1;
    sub3->chave = 8;

    sub3->prox = (NO*) malloc(sizeof(NO));
    sub3 = sub3->prox;
    sub3->tipo = 2;
    NO* sub6 = sub3;  

    sub3->prox = (NO*) malloc(sizeof(NO));
    sub3 = sub3->prox;
    sub3->tipo = 1;
    sub3->chave = 9;

    sub5->sublista = (NO*) malloc(sizeof(NO));
    sub5 = sub5->sublista;
    sub5->tipo = 1;
    sub5->chave = 10;

    sub6->sublista = (NO*) malloc(sizeof(NO));
    sub6 = sub6->sublista;
    sub6->tipo = 1;
    sub6->chave = 11;

    // o EP sera testado com chamadas deste tipo
    printf("Comecou o porgrama =D\n");
    exibir(listarChaves(inicio));

    // e aqui vc deveria percorrer a lista teste para ver se ficou correta etc.

}

// por favor nao inclua nenhum código abaixo da função main()
