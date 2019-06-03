#include "energia_eletrica_funcoes_v2.h"
int main(){
	setlocale(LC_ALL,"");// define o conjuntos de caracteres do SO para poder usar acentos e outros caracteres da lingua local
	int i,j,n,o; // declara variaveis
	matriz m[k]; // declara a matriz de adjacencias
	n=abre_arquivo(m); // carrega o arquino na matriz
	while(o!=9){ // verifica se foi escolhida a opção saida
		o=menu(); // imprime o menu e recebe a opção escolhida pelo usuário
		if (o==1) conexao(m); // chama a função de nova conexão
		else if (o==2) desconexao(m); // chama a função de desconexao
		else if (o==3) {
			imprime_matriz(m,n); // imprime a vetor energia	
		}
		else if (o==4) {
		    imprime_energia(m,n); // imprime a matriz	
		}
		else printf("------Finalizando programa----"); // imprime mensagem de saida
	}
	return 0;
}
