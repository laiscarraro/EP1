#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	for(i = strlen(frase); i >= 0; i--) {
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

//Inverter a frase inteira, q seria o passo 2
NO* inverter(NO* comeco, NO* fim, NO* anterior, NO* posterior) {
	NO* inicio = NULL;
	NO* p = comeco;
	while(p != fim) {
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->letra = p->letra;
		novo->prox = inicio;
		inicio = novo;
		p = p->prox;
	}
	if(anterior) anterior->prox = inicio;
	if(posterior) fim->prox = posterior;
	free(comeco);
	free(fim);
	return inicio;
}

NO* codificar(NO* frase) {
	NO* resp = NULL;
	
	return resp;
}

int main() {
	NO* p = NULL;
	char frase[500];
	strcpy(frase, "ESTRUTURA DE DADOS E MUITO LEGAL.");
	fraseParaLista(&p, frase);

	NO* teste = p;
	NO* h = p->prox;

	exibir(p);
	printf("\n");
	exibir(inverter(h, p, NULL, NULL));
	printf("\n");
}