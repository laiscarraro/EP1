#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 50

/*

LISTAS LINEARES
- Uma lista linear eh uma serie de elementos ordenados em que todos os elementos (menos o primeiro) possui um
(e apenas um) antecessor, e todos os elementos (menos o ultimo) possui um (e apenas um) sucessor.

TODAS AS COMBINACOES DE LISTAS LINEARES:
1 - Lista linear sequencial (normal)
2 - Lista linear sequencial (com sentinela)
3 - Lista linear sequencial (com cabeca)
4 - Lista linear sequencial (com sentinela e com cabeca)
5 - Lista ligada estatica (normal)
6 - Lista ligada estatica (duplamente ligada)
7 - Lista ligada estatica (circular)
8 - Lista ligada estatica (duplamente ligada e circular)
9 - Lista ligada estatica (normal com sentinela)
10 - Lista ligada estatica (normal com cabeca)
11 - Lista ligada estatica (normal com cabeca e com sentinela)
12 - Lista ligada estatica (duplamente ligada com sentinela)
13 - Lista ligada estatica (duplamente ligada com cabeca)
14 - Lista ligada estatica (duplamente ligada com cabeca e com sentinela)
15 - Lista ligada estatica (circular com sentinela)
16 - Lista ligada estatica (circular com cabeca)
17 - Lista ligada estatica (circular com cabeca e com sentinela)
18 - Lista ligada estatica (duplamente ligada e circular com sentinela)
19 - Lista ligada estatica (duplamente ligada e circular com cabeca)
20 - Lista ligada estatica (duplamente ligada e circular com cabeca e com sentinela)
21 - Lista ligada dinamica (normal)
22 - Lista ligada dinamica (duplamente ligada)
23 - Lista ligada dinamica (circular)
24 - Lista ligada dinamica (duplamente ligada e circular)
25 - Lista ligada dinamica (normal com sentinela)
26 - Lista ligada dinamica (normal com cabeca)
27 - Lista ligada dinamica (normal com cabeca e com sentinela)
28 - Lista ligada dinamica (duplamente ligada com sentinela)
29 - Lista ligada dinamica (duplamente ligada com cabeca)
30 - Lista ligada dinamica (duplamente ligada com cabeca e com sentinela)
31 - Lista ligada dinamica (circular com sentinela)
32 - Lista ligada dinamica (circular com cabeca)
33 - Lista ligada dinamica (circular com cabeca e com sentinela)
34 - Lista ligada dinamica (duplamente ligada e circular com sentinela)
35 - Lista ligada dinamica (duplamente ligada e circular com cabeca)
36 - Lista ligada dinamica (duplamente ligada e circular com cabeca e com sentinela)

FUNCOES BASICAS DE LISTAS (na ordem de implementacao):
1 - Inicializacao
2 - Exibicao (percorrer)
3 - Busca (sequencial em todas e binaria na lista sequencial)
4 - Exclusao
5 - Insercao

CASOS DE TESTE PARA AS FUNCOES DA LISTA:
1 - Lista vazia
2 - Com 1 elemento
3 - Com n elementos
4 - No primeiro elemento
5 - No ultimo elemento
6 - No elemento n
7 - Lista cheia

LISTA LINEAR SEQUENCIAL
- Uma lista linear sequencial eh uma lista linear na qual a ordem logica dos elementos eh igual aa ordem fisica
(ou seja, implementada utilizando um vetor).

- VANTAGENS:
- Eh possivel acessar diretamente um elemento de indice n, sem a necessidade de percorrer a lista do primeiro elemento ate n.
No entanto, na maioria das aplicacoes, o indice do elemento nao eh uma informacao conhecida, o que praticamente anula a vantagem.
- Numa lista seq. ordenada, eh possivel realizar a busca binaria por um elemento de chave ch, que possui a eficiencia O(log n).

- DESVANTAGENS:
- A insercao e exclusao de elementos envolve movimentacao de dados. No pior caso, quando se exclui/inclui um elemento na primeira
posicao da lista, ha a movimentacao de todos os dados, ou seja, O(n), o que eh mto ineficiente com uma grande quant. de dados.
- A implementacao da lista exige que o programador estabeleca um numero maximo fixo de posicoes no vetor, o que pode limitar
muito aplicacoes praticas para essa estutura.

IMPLEMENTACAO DA LISTA LINEAR SEQUENCIAL:

*/

typedef struct {
	int chave;
} REG_SEQ;

typedef struct {
	REG_SEQ A[MAX];
	int nroElem;
} LISTA_SEQ;

void inicializar(LISTA_SEQ l) {
	l.nroElem = 0;
}

void exibir(LISTA_SEQ l) {
	int i = 0;
	while(i < l.nroElem) {
		printf("%i\n", l.A[i].chave);
		i++;
	}
}
