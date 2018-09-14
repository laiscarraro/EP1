// chcp 65001 
// cd C:\Users\USP\Desktop\CEx\EP1
// gcc EP1V4Sera.c -o EP1V4.exe
// EP1V4.exe

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include <locale.h>
#define true 1
#define false 0

char* nroUSP1();
char* nroUSP2();
char* grupo();

char* grupo() {
	return "14";
}

char* nroUSP1() {
	return "10391184";
}

char* nroUSP2() {
	return "10687638";
}

//INICIO DO EP

//struct NO
typedef struct s {
	char letra;
	struct s* prox;
} NO;

//Para transformar a string recebida (vetor) numa LISTA LIGADA DE CHAR dinamica de ate 500 elem (Esse eh o limite da string)
void fraseParaLista(NO* *inicio, char frase[]) {
	NO* novo;
	int i;
	for(i = strlen(frase)-1; i >= 0; i--) {
		novo = (NO*) malloc(sizeof(NO));
		novo->letra = frase[i];
		novo->prox = *inicio;
		*inicio = novo;
	}
}

//imprimir
void exibir(NO* inicio) {
	NO* p = inicio;
	if(!inicio) printf("Lista vazia :/ \n");
	while(p) {
		printf("%c", p->letra);
		p = p->prox;
	}
}


		//ispunct(a) && isalnum(a)){
int ehVogal(char a) {
	a = toupper(a);
	printf("%c ",a);
	if ((a !='B'&& a !='C'&& a !='D'&& a !='F'&& a !='G'&& a !='H'&& a !='J'&& a !='K'&& a !='L'&& a !='M'&& a !='N'&& 
		a !='P'&& a !='Q'&& a !='R'&& a !='S'&& a !='T'&& a !='V'&& a !='X'&& a !='Y'&& a !='Z'&& a !='W') && 
		isalpha(a) && a != ' '){//Testa pra ver se é um numero ou ponto
		printf("Vogal\n");
		return true;
	} else {
		printf("Não vogal\n");
		return false;
	}
}

void passo1V2(NO* n) {
	printf("Iniciou o passo1V2 \n");
	NO* x = n->prox;
	NO* p = x->prox;
	NO* t = p->prox;
	while(!ehVogal(t->letra) && t->prox){ //invertendo as parada tudo
		p->prox = x;
		x = p;
		p = t;
		t = t->prox;
	}
	p->prox = x;
	n->prox->prox = t;
	n->prox = p;
}


NO* codificar(NO* frase) {
	NO* vogal1 = frase;

	NO* j = vogal1->prox;
	int andou=0;
	int ultima=0;
	if (!ehVogal(vogal1->letra)){//Se comeca com consoante
		andou++;
	}
	do {
		while(!ehVogal(j->letra) && andou<2){
			j=j->prox;
			andou++;
			printf("Procurando o espaço de 2 :: %i\n",andou);
		}
		if(andou==2){
			passo1V2(vogal1);
			j=j->prox->prox;

			andou=0;
			exibir(frase);
			printf("\nInverteu %i\n", andou);
			printf("*********\n" );
			printf("Famosa Frase\n");
			exibir(frase);
			printf("\n*********\n" );
		}else{
			vogal1=j;
			j=j->prox;
			andou=0;
			printf("\nNada mudou %i\n",andou);
		} 
	}while(j);
	return frase;
}


int main() {
	NO* p = NULL;
	char frase[500];
	setlocale(LC_ALL,"pt_BR.UTF-8");
	strcpy(frase, "estrvkluturas E DADOS e guito LEGAL.a");
	fraseParaLista(&p, frase);

	exibir(p);
	printf("\n");
	exibir(codificar(p));
	printf("\n");
}

// -------------------------------------------Famoso lixo----------------------------------------------------

/*int encontraVogal(){
	if(!ehVogal(vogal1->letra)){
		NO* p = passo1(vogal1, vogal2, &fim);
		if(inicio) inicio->prox = p;
		inicio = p;
	}
}*/
/*//Inverter a frase inteira, q seria o passo 2
NO* passo2(NO* frase, NO* *ult) {
	NO* inicio = NULL;
	NO* p = frase;
	while(p) {
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->letra = p->letra;
		novo->prox = inicio;
		if(!inicio) *ult = novo;
		inicio = novo;
		p = p->prox;
	}
	return inicio;
}*/

/*NO* passo1(NO* vogal1prox, NO* vogal2, NO* *ultimo) {
	NO* resp = NULL;

	if(vogal1prox == vogal2) return NULL;

	while(vogal1prox != vogal2){
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->letra = vogal1prox->letra;
		novo->prox = resp;
		if(!resp) *ultimo = novo;
		resp = novo;
		vogal1prox = vogal1prox->prox;
	}
	return resp;
}*/
/*if (j->prox->prox && ultima == 0)
{
	printf("pqqqqqq %s\n",j->prox->prox);
	ultima=1;
}*/
