#include <stdio.h>
#include <string.h>
#include <locale.h>
#define k 200 // tamanho maximo da matriz de adjacencias

typedef struct matriz{ // definição da struct
	int energia; // está energigado
	int conexao[k]; // conexão do nó
} matriz;
void imprime_pilha(int p[k], int n); // função que imprime a pilha (somente para debug)
// pre: recebe a pilha e um inteiro com o tamanho da pilha
// pos: imprime todos os elementos da pilha
void busca_energia(matriz m[k] ,int n);
// pre: recebe a matriz com as conexões e o inteiro com o numero de conexoes;
// pos: altera o status de energizado de cada nó
int push(int p[k], int i, int t); // função que coloca item na pilha
// pre: recebe a pilha um inteiro com o nivel da pilha e o item que deseja empilhar
// pos: faz o empilhamento e retorna o novo nivel da pilha
int pop(int p[k], int n); // função que tira item da pilha
// pre: recebe a pilha e o tamanho da pilha
// pos: faz o desempilhamento e retorna o novo nivel da pilha
void limpa(matriz m[k], int n); // funçao de limpeza da matriz
// pre: funçao de limpeza da matriz recebe a matria e o numero de nós
// pos: recebe a matriz e limpa todos os campos
void energia(matriz m[k], int n);// verificar energia
// pre: função de verificação de nós energizados, recebe a matria e o numero de nós
// pós: recebe a matriz e retorna altera o status de energizado de cada nó
int abre_arquivo(matriz m[k]); // carrega os dados
// pre: recebe a matriz e os dados do arquivo dados.txt
// pós: carrega todos os dados do arquivo dados.txt nos nós montando a matriz de adjacencias e retorna o numero de nós
void imprime_matriz(matriz m[k], int n); // imprime a matriz
// pre: recebe a matriz e o numero de nós
// pós: imprime na tela a matriz de adjacencias
void imprime_energia( matriz m[k], int n); // imprime vetor de energia
// pre: recebe a matriz e o numero de nós
// pós: imprime o vetor de nós com seus respectivos conexaões de energia;
void desconexao(matriz m[k]); // faz desconexão
// pre: recebe a matriz
// pós: recebe do teclado qual o aresta será escluida e faz a exclusão da matriz de adjacencias
void conexao(matriz m[k]); // faz nova conexão
// pre: recebe a matriz
// pós: recebe do teclado qual o aresta será incluida e faz a inclusão na matriz de adjacencias
int menu(); // imprime menu
// pre: não recebe nenhum paramentro
// pós: imprime o menu, recebe o teclado a opção do usuário e retorna a opção digitada
