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
NO* passo2(NO* frase) {
	NO* inicio = NULL;
	NO* p = frase;
	while(p) {
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->letra = p->letra;
		novo->prox = inicio;
		inicio = novo;
		p = p->prox;
	}
	return inicio;
}

NO* passo1(NO* vogal1prox, NO* vogal2, NO* *ultimo) {
	NO* resp = NULL;
	NO* ult = NULL;

	if(vogal1prox == vogal2) return NULL;

	while(vogal1prox != vogal2){
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->letra = vogal1prox->letra;
		novo->prox = NULL;
		if(!resp) resp = novo;
		else ult->prox = novo;
		ult = novo;
		vogal1prox = vogal1prox->prox;
	}
	*ultimo = ult;
	return resp;
}

int ehVogal(char a) {
	if(a != 'a' && a != 'e' && a != 'i' && a != 'o' && a != 'u' && a != 'A' && a != 'E' && a != 'I' && a != 'O' && a != 'U'){
		return true;
	} else {
		return false;
	}
}


NO* codificar(NO* frase) {
	NO* resp = NULL;

	NO* vogal1 = frase;
	NO* vogal2 = frase;

	if(!ehVogal(vogal1->letra) && vogal1 == frase){
		while(!ehVogal(vogal2->letra) && vogal2) vogal2 = vogal2->prox;
		NO* ultimo = NULL;
		resp = passo2(vogal1, vogal2, ultimo);
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->letra = vogal2->letra;
		novo->prox = NULL;
		ultimo->prox = novo;

	} else if(ehVogal(vogal1->letra) && vogal1 == frase){
		vogal2 = vogal2->prox;
		while(!ehVogal(vogal2->letra) && vogal2) vogal2 = vogal2->prox;
		NO* ultimo = NULL;
		NO* novo1 = (NO*) malloc(sizeof(NO));
		novo1->letra = vogal1->letra;
		novo1->prox = passo2(vogal1->prox, vogal2, ultimo);
		if(!novo1->prox) ultimo = novo1;
		resp = novo1;
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->letra = vogal2->letra;
		novo->prox = NULL;
		ultimo->prox = novo;
	}
	return resp;
}

int main() {
	NO* p = NULL;
	char frase[500];
	strcpy(frase, "ESTRUTURA DE DADOS E MUITO LEGAL.");
	fraseParaLista(&p, frase);

	NO* teste = p;
	NO* vogal1 = teste->prox->prox;
	NO* vogal2 = teste->prox->prox->prox->prox->prox;

	exibir(p);
	printf("\n");
	exibir(passo1(vogal1->prox, vogal2));
	printf("\n");
}
