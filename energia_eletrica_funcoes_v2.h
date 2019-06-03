#include <stdio.h>
#include <string.h>
#include <locale.h>
#define k 200 // tamanho maximo da matriz de adjacencias

typedef struct matriz{ // defini��o da struct
	int energia; // est� energigado
	int conexao[k]; // conex�o do n�
} matriz;
void imprime_pilha(int p[k], int n); // fun��o que imprime a pilha (somente para debug)
// pre: recebe a pilha e um inteiro com o tamanho da pilha
// pos: imprime todos os elementos da pilha
void busca_energia(matriz m[k] ,int n);
// pre: recebe a matriz com as conex�es e o inteiro com o numero de conexoes;
// pos: altera o status de energizado de cada n�
int push(int p[k], int i, int t); // fun��o que coloca item na pilha
// pre: recebe a pilha um inteiro com o nivel da pilha e o item que deseja empilhar
// pos: faz o empilhamento e retorna o novo nivel da pilha
int pop(int p[k], int n); // fun��o que tira item da pilha
// pre: recebe a pilha e o tamanho da pilha
// pos: faz o desempilhamento e retorna o novo nivel da pilha
void limpa(matriz m[k], int n); // fun�ao de limpeza da matriz
// pre: fun�ao de limpeza da matriz recebe a matria e o numero de n�s
// pos: recebe a matriz e limpa todos os campos
void energia(matriz m[k], int n);// verificar energia
// pre: fun��o de verifica��o de n�s energizados, recebe a matria e o numero de n�s
// p�s: recebe a matriz e retorna altera o status de energizado de cada n�
int abre_arquivo(matriz m[k]); // carrega os dados
// pre: recebe a matriz e os dados do arquivo dados.txt
// p�s: carrega todos os dados do arquivo dados.txt nos n�s montando a matriz de adjacencias e retorna o numero de n�s
void imprime_matriz(matriz m[k], int n); // imprime a matriz
// pre: recebe a matriz e o numero de n�s
// p�s: imprime na tela a matriz de adjacencias
void imprime_energia( matriz m[k], int n); // imprime vetor de energia
// pre: recebe a matriz e o numero de n�s
// p�s: imprime o vetor de n�s com seus respectivos conexa�es de energia;
void desconexao(matriz m[k]); // faz desconex�o
// pre: recebe a matriz
// p�s: recebe do teclado qual o aresta ser� escluida e faz a exclus�o da matriz de adjacencias
void conexao(matriz m[k]); // faz nova conex�o
// pre: recebe a matriz
// p�s: recebe do teclado qual o aresta ser� incluida e faz a inclus�o na matriz de adjacencias
int menu(); // imprime menu
// pre: n�o recebe nenhum paramentro
// p�s: imprime o menu, recebe o teclado a op��o do usu�rio e retorna a op��o digitada
