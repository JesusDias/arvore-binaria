#include<stdio.h>
#include<stdlib.h>

struct ponto{
	int valor;
	struct ponto *esq;
	struct ponto *dir;
};

typedef struct ponto Ponto;
	
Ponto* criarArvore(int valor){
	Ponto *p = (Ponto*) malloc(sizeof(Ponto));
	p->valor = valor;
	p->esq = NULL;
	p->esq = NULL;
	return p;
}

Ponto *raiz;
void insere(Ponto *ponteiro, int valor){
	if(raiz == NULL){
		raiz = criarArvore(valor);
		} else {
			if (valor < ponteiro->valor){
				if(ponteiro->esq == NULL){
					ponteiro->esq = criarArvore(valor);
			} else {
				insere(ponteiro->esq, valor);
			}
			} else {
				if(ponteiro->dir == NULL){
				ponteiro->dir = criarArvore(valor);
			} else {
			insere(ponteiro->dir, valor);
			}
		}
	}
}

void teste(Ponto *ponteiro){
	void mostraArvore(Ponto *ponteiro);
	if (ponteiro == NULL)
		printf("Arvore vazia\n\n");
	mostraArvore(raiz);
}

void mostraArvore(Ponto *ponteiro){
	if(ponteiro != NULL){
		printf("[%d]\n", ponteiro->valor);
		mostraArvore(ponteiro->esq);
		mostraArvore(ponteiro->dir);
	}
}

void apaga(Ponto *ponteiro, int valor){
	if (raiz == NULL){
		printf("Arvore está vazia\n");
	} else {
			Ponto *filho = ponteiro;
	Ponto *pai;
	do 
	{
		pai = filho;
		if(valor < filho->valor){
			filho = filho->esq;
	} else if (valor > filho->valor){
		filho = filho->dir;
		}
	} while(filho != NULL && filho->valor != valor);
	
	if (filho == NULL){
		printf("Valor não existe na árvore! \n");
	}
	if(filho != NULL){
		
		if(filho->esq == NULL && filho->dir == NULL){
			if(pai->esq == filho){
				pai->esq = NULL;
			}
			if(pai->dir == filho){
				pai->dir = NULL;
			}
			} else if(filho->esq != NULL && filho->dir == NULL){
				if (pai->esq == filho){
					pai->esq = filho->esq;
				} if (pai->dir == filho) {
				pai->dir = filho->esq;
				}
			} else if(filho->dir != NULL && filho->esq == NULL){
				if (pai->esq == filho){
					pai->esq = filho->dir;
				} if (pai->dir == filho) {
					pai->dir = filho->dir;
				}
			} else if (filho->dir != NULL && filho->esq != NULL){
				if (filho->esq->dir == NULL){
					filho->valor = filho->esq->valor;
				} else {
					Ponto *p = filho->esq;
					Ponto *aux = p;
				
					while (p->dir != NULL){
						aux = p;
						p = p->dir;
					}
					aux->dir = NULL;
					filho->valor = p->valor;
				}
			}
		}
	}
}

//busca binária em Arvore
void pesquisa(Ponto *ponteiro, int valor){
	if(ponteiro == NULL){
		printf("Valor não encontrado na Arvore\n");
	} else {
		if (ponteiro->valor == valor){
			printf("Valor %d encontrado\n", valor);
		} else {
			if (valor < ponteiro->valor){
				return pesquisa(ponteiro->esq, valor);
			} else {
				return pesquisa(ponteiro->dir, valor);
			}
		}
	}
}

void mostraMenu(){
	printf("1 MOSTRAR ARVORE\n2 INSERIR NA ARVORE\n3 REMOVER DA ARVORE\n4 BUSCA UM VALOR\n escolha: ");
}
	
main(){
	int escolha, valor;
	
	do 
	{
		mostraMenu();
		scanf("%d", &escolha);
	
		switch (escolha)
		{
			case 1:
				teste(raiz);
			break;
			case 2:
				printf("Informe valor a inserir. "); 
				scanf("%d", &valor);
				insere(raiz, valor);
				printf("\n");
			break;
			case 3:
				printf("Informe valor a apagar. "); 
				scanf("%d", &valor);
				apaga(raiz, valor);
			break;
			case 4:
				printf("Informe valor a ser encontrado. "); 
				scanf("%d", &valor);
				pesquisa(raiz, valor);
		}
	}while (escolha != 0);
}
