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
}

NO* passo1(NO* vogal1prox, NO* vogal2, NO* *ultimo) {
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
}

int ehVogal(char a) {
	if(a != 'a' && a != 'e' && a != 'i' && a != 'o' && a != 'u' && a != 'A' && a != 'E' && a != 'I' && a != 'O' && a != 'U'){
		return false;
	} else {
		return true;
	}
}


NO* codificar(NO* frase) {
	NO* resp = NULL;
	NO* final = NULL;

	NO* sla = frase;

	while(sla) {
		NO* vogal1 = sla;
		NO* vogal2 = sla;
		NO* inicio = final;
		NO* fim = NULL;
		if(!ehVogal(vogal1->letra)){
			while(vogal2 && vogal2->prox && !ehVogal(vogal2->letra)) vogal2 = vogal2->prox;
			NO* p = passo1(vogal1, vogal2, &fim);
			if(inicio) inicio->prox = p;
			inicio = p;
		} else {
			vogal2 = vogal2->prox;
			while(vogal2 && vogal2->prox && !ehVogal(vogal2->letra)) vogal2 = vogal2->prox;
			NO* novo1 = (NO*) malloc(sizeof(NO));
			novo1->letra = vogal1->letra;
			novo1->prox = passo1(vogal1->prox, vogal2, &fim);
			if(!novo1->prox) fim = novo1;
			inicio = novo1;
		}
		if(vogal2) {
			NO* novo = (NO*) malloc(sizeof(NO));
			novo->letra = vogal2->letra;
			novo->prox = NULL;
			fim->prox = novo;
			fim = novo;
		}
		if(!resp) resp = inicio;
		final = fim;
		if(vogal2) sla = vogal2->prox;
		else sla = vogal2;
	}
	return resp;
}

int main() {
	NO* p = NULL;
	char frase[500];
	strcpy(frase, "ESTRUTURA DE DADOS.");
	fraseParaLista(&p, frase);

	exibir(p);
	printf("\n");
	exibir(codificar(p));
	printf("\n");
}
