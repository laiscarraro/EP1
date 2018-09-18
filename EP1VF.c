// chcp 65001 
// cd C:\Users\USP\Desktop\CEx\EP1
// gcc EP1VF.c -o EP1VF.exe
// EP1VF.exe

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
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

void fraseParaLista(NO* *inicio, char frase[]) {//Transforma a string recebida em um lista dinamica de char
	NO* novo;
	int i;
	for(i = strlen(frase)-1; i >= 0; i--) {
		novo = (NO*) malloc(sizeof(NO));
		novo->letra = frase[i];
		novo->prox = *inicio;
		*inicio = novo;
	}
}

void exibir(NO* inicio) {//imprimir
	NO* p = inicio;
	if(!inicio) printf("Lista vazia :/ \n");
	while(p) {
		printf("%c", p->letra);
		p = p->prox;
	}
}

int ehVogal(char a) {
	a = toupper(a);
	if ((a !='B'&& a !='C'&& a !='D'&& a !='F'&& a !='G'&& a !='H'&& a !='J'&& a !='K'&& a !='L'&& a !='M'&& a !='N'&& 
		a !='P'&& a !='Q'&& a !='R'&& a !='S'&& a !='T'&& a !='V'&& a !='X'&& a !='Y'&& a !='Z'&& a !='W') && 
		isalpha(a) && a != ' '){//Testa pra ver se e uma letra, um numero ou um ponto.
		return true;
	} else {
		return false;
	}
}

NO* passo1Vogal(NO* n) {
	NO* x = n->prox;
	NO* p = x->prox;
	NO* t = p->prox;
	if(!t) return p;
	while(!ehVogal(t->letra)&&t->prox){ //Inverte as consoantes
		p->prox = x;
		x = p;
		p = t;
		t = t->prox;
	}
	    p->prox = x;
    	n->prox->prox = t;
	    n->prox = p;
	return t;//Retorna a frase invertida
}

NO* inverteTudo(NO* n) { //Inverte toda a frase
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

	if(!vogal1->prox) return frase; //So uma letra
	while(ehVogal(vogal1->letra)&&!ehVogal(b->letra)&&b->prox)b=b->prox;//Avanca na frase ate encontrar uma vogal
	
	int andou = 0; //controle para ver quantas nao vogais existem entre as vogais
	int primeira = 0; //controle para ver se eh a primeira parte da frase

	if (!ehVogal(vogal1->letra)){ //Se comeca com nao vogal
	 	andou++;
	 	primeira = 1; //indica que ja passamos pelo comeco da frase
	}

	do {
		while(j && (!ehVogal(j->letra) && andou<2)){//Consulta pra ver se tem pelo menos 2 nao vogais seguidas
			j = j->prox;
			andou++;
		}
		if(andou == 2){ //Se existem pelo menos duas nao vogais entre a primeira letra e a ultima
			if(!ehVogal(vogal1->letra) && primeira == 1) { //Se comeca com nao vogal e ja passamos pelo comeco da frase
				while(b && !ehVogal(b->letra)) b = b->prox; //Anda ate achar uma vogal, server pra consultar se existe vogal mais pra frente
				if (!b) return inverteTudo(frase); //Sem vogal na frase, um monte de nao vogal, so inverte tudo
			    while(j->prox && !ehVogal(j->letra)) j = j->prox; //Prepara a frase para sem invertida
			    NO* ult = vogal1;
			    while(ult->prox->prox != j && !ehVogal(ult->letra)) ult = ult->prox; //Prepara a frase para sem invertida
			    frase = ult->prox;
			    frase->prox = vogal1;
			    ult->prox = j;
			    vogal1 = frase;
			    primeira = 0;
		    }
		    if(ehVogal(vogal1->letra) && ((!ehVogal(b->letra) && !b->prox) || !j)){//Começa com vogal e termina com nao vogal
		    	if(j) {
		    	    vogal1=vogal1->prox;
		    	    frase->prox=inverteTudo(vogal1);
		    	} else {
		    	    vogal1->prox = inverteTudo(vogal1->prox);
		    	}
		    	return inverteTudo(frase);
		    }
		    
			j = passo1Vogal(vogal1);
			andou = 0;

		} else {//Quando tem só uma consoante entre 2 vogais
			vogal1 = j;
			if(j) j = j->prox;
			andou = 0;
		} 
	} while(j); //executa j+1 vezes
	return inverteTudo(frase);
}

int main() {
	NO* p = NULL;
	char frase[500];
	setlocale(LC_ALL,"pt_BR.UTF-8");
	strcpy(frase, "ESTRUTURAS DE DADOS E MUITO LEGAL.");

	fraseParaLista(&p, frase);
	printf("Frase original: ");
    exibir(p);
    printf("\n");
    printf("Apos o passo 1: ");
	exibir(codificar(p));
	printf("\n");
}
