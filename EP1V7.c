// chcp 65001 
// cd C:\Users\USP\Desktop\CEx\EP1
// gcc EP1V7.c -o EP1V7.exe
// EP1V7.exe

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

NO* passo1Vogal(NO* n) {
	printf("Iniciou o passo1V2 \n");
	NO* x = n->prox;
	NO* p = x->prox;
	NO* t = p->prox;
	if(!t) return p;
	NO* g;
	g = (NO*) malloc(sizeof(NO));
	g->letra = x->letra;
	g->prox = NULL;
	int k = 0;
	while(!ehVogal(t->letra)&&t->prox){ //invertendo as parada tudo
		p->prox = x;
		x = p;
		p = t;
		t = t->prox;
	}
	    p->prox = x;
    	n->prox->prox = t;
	    n->prox = p;
	return t;
}

NO* passo1Consoante(NO* n) {
	NO* x = n->prox;
	NO* p = x->prox;
	NO* t = p->prox;
	do {
		p->prox = x;
		x = p;
		p = t;
		if(t) t = t->prox;
	} while(t);
	n->prox->prox = n;
	n->prox = NULL;
	n = x;
	return n;
}

NO* inverteTudo(NO* n) {
	NO* x = n->prox;
	NO* p;
	NO* t;
	if(x) p = x->prox;
	else return n;
	if(p) t = p->prox;
	while(p) {
		p->prox = x;
		x = p;
		p = t;
		if(t) t = t->prox;
	}
	n->prox->prox = n;
	n->prox = NULL;
	n = x;
	return n;
}

NO* codificar(NO* frase) {
	NO* vogal1 = frase;

	NO* j = vogal1->prox;
	NO* b = vogal1->prox;
	if(!vogal1->prox) return frase; //Só uma letra
	while(ehVogal(vogal1->letra)&&!ehVogal(b->letra)&&b->prox)b=b->prox;//Avança na frase até encontrar uma vogal
	
	int andou = 0;
	int primeira = 0;

	if (!ehVogal(vogal1->letra)){
		
	 	andou++;
	 	primeira = 1;//Se comeca com consoante
	}	
	do {
		while((!ehVogal(j->letra) && andou<2)){//Consulta pra ver se tem mais de 2 consoantes seguidas
			// if(!j)andou++;
			j = j->prox;
			andou++;
			printf("Procurando o espaço de 2 :: %i\n",andou);
		}
		if(andou == 2){
			printf("tururuuuu\n");
			if(!ehVogal(vogal1->letra)&&primeira == 1) { //Comeca com Consoante e termina com vogal
				if (!b->prox) return inverteTudo(frase); //Sem vogal na frase, um monte de consoante
			    while(j->prox && !ehVogal(j->letra)) j = j->prox;
			    NO* ult = vogal1;
			    while(ult->prox->prox != j && !ehVogal(ult->letra)) ult = ult->prox;
			    frase = ult->prox;
			    frase->prox = vogal1;
			    ult->prox = j;
			    vogal1 = frase;
			    primeira = 0;
		    }
		    if(ehVogal(vogal1->letra)&&!ehVogal(b->letra)&&!b->prox){//Começa com vogal e termina com consoante
		    	vogal1=vogal1->prox;
		    	frase->prox=inverteTudo(vogal1);	
		    	return frase;
		    }
		    
			j = passo1Vogal(vogal1);
			andou = 0;
			exibir(frase);
			printf("\nInverteu %i\n", andou);
			printf("*********\n" );
			printf("Famosa Frase\n");
			exibir(frase);
			printf("\n*********\n" );
		} else {//Quando tem só uma consoante entre 2 vogais
			vogal1 = j;
			j = j->prox;
			andou = 0;
			printf("\nNada mudou %i\n",andou);
		} 
	} while(j);
	return frase;
}

int main() {
	NO* p = NULL;
	char frase[500];
	setlocale(LC_ALL,"pt_BR.UTF-8");
	strcpy(frase, "ESTRUTURAS DE DADOS E MUITO LEGAL.");
	// strcpy(frase, "a12345ei");
	// strcpy(frase, "a12e");
	// strcpy(frase, "ae");
	// strcpy(frase, "12345a");
	// strcpy(frase, "123a");
	// strcpy(frase, "12a");
	// strcpy(frase, "123"); 
	// strcpy(frase, "a123456789");
	// strcpy(frase, "123456789");
	// strcpy(frase, "ai12");//nok
	// strcpy(frase, "12");	//nok
	// strcpy(frase, "a2");	//nok
	// strcpy(frase, "1");
	// strcpy(frase, "a");


	fraseParaLista(&p, frase);
	printf("\nResult dessa budega S2\n");
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
}

o segundo passo 1

	    a = n->letra;
	    n->prox->prox = n;
	    a = n->prox->letra;
	    n->prox = t;
	    a = t->letra;
	    n = p;

*/
/*NO* passo1Consoante(NO* n) {
    char a = n->letra;
	printf("Iniciou o passo1V2 \n");
	NO* x = n->prox;
	NO* p = x->prox;
	NO* t = p->prox;
	while(t != n && t->prox){ //invertendo as parada tudo
		p->prox = x;
		x = p;
		p = t;
		t = t->prox;
	}
	    p->prox = x;
    	n->prox->prox = t;
	    n->prox = p;
	return t;
}*/
		/*printf("aaaaaa\n");
		if(t->prox){

			t->prox = g;
			p->prox = x;
			x = p;
			p = t;
			break;
		}*/
