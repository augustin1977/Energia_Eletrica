#include <stdio.h>
#include <string.h>
#include <locale.h>
#define k 100 // tamanho maximo da matriz de adjacencias
typedef struct matriz{ // definição da struct
	int energia; // está energigado
	int conexao; // conexão do nó
} matriz;

void limpa(matriz m[k][k], int n){ // funçao de limpeza da matriz
	int i,j;// declaração das variaveis contadoras
	for(i=0;i<n;i++){ // percorre todas a linhas
		for(j=0;j<n;j++){ // percorre todas as colunas
			m[i][j].conexao=0; // zera a conexão
			m[i][j].energia=0; // zera a energia
		}
	}
}
void energia(matriz m[k][k], int n){
	int i,j,r=0,in=0;
	for(i=0;i<n;i++){ // percorre todas a colunas
			m[0][i].energia=0; // zera a energia para fazer a analise do zero
		}
	m[0][1].energia=1;
	while(r==0){
		r=1;
		in++;
		for (i=1;i<n;i++){ // percorre todas a linhas
			for (j=0;j<n;j++){ // percorre todas as colunas
				//printf("m[%d][%d]=%d m[0][%d]=%d m[0][%d]=%d\n",i,j,m[i][j].conexao,j,m[0][j].energia,i,m[0][i].energia);
				if (m[i][j].conexao==1 && m[0][j].energia==0 && m[0][i].energia==1){ // vefifica se ha conexão e so o ponto ja está sem enrgia (se ja estiver energizado por outro caminho segue para o proximo ponto)
					m[0][j].energia=1; // caso positivo coloca o status da linha na coluna (transfere energia da conexao)
					r=0;
					//printf("conectei energia em m[0][%d]=%d\n",j,m[0][j].energia);
				}
				
			}
		}
	}
	printf("\n%d iterações\n",in);
}
int abre_arquivo(matriz m[k][k]){ // carrega os dados
	FILE *f; // declara o ponteiro para aqurivo
	int n,i,l,c,max; // declsara as variaveis contadoras e auxiliares
	f=fopen("dados.txt","r"); // abre o arquivo
	fscanf(f,"%d,%d\n",&n,&max); // lê primeira linha o está o numero de registros e o numero de nós
	limpa(m,max); // chama a função limpeza, ainda tem um erro aqui... limpando até n e tem que limpar até max
	for(i=1;i<n;i++){ // percorre o arquivo até a linha n
		fscanf(f,"%d,%d",&l,&c); // le acada linha
		m[l][c].conexao=1; // marca na matriz a conexao da linha e coluna
	}
	return max+1; // retorna o numero do maior vertice
}
void imprime_matriz(matriz m[k][k], int n){ // imprime a matriz
	int i,j; // declara contadores
	for (i=0;i<n;i++){ // percorre todas as colunas
		if (i==0) printf("   ");// deixa em branco o espaço 0
		else printf("%2d ",i);// imprime indice de colunas
	}
	printf("\n"); // pula linha
	for(i=1;i<n;i++){ // percorre linhas
 	    printf("%2d ",i); // imprime indice de linhas
		for(j=1;j<n;j++){ // percorre colunas
			printf("%2d ",m[i][j].conexao);	 // imprime colunas		
		}
		printf("\n");// pula para proxima linha
	}
}
void imprime_energia( matriz m[k][k], int n){
	int i;
	energia(m,n);
	for (i=1;i<n;i++){ // 
		printf("%2d ",i); // imprime indice de colunas
	}	
	printf("\n");
	for (i=1;i<n;i++){
		printf("%2d ",m[0][i].energia);
	}
	printf("\n");
}
void desconexao(matriz m[k][k]){
	int l,c; // declara variaveis
	printf("Digite a conexão que deseja desligar no formado [origem],[destino]\nexemplo: 1,2  -  desliga nó 1 do nó 2\n:"); // informa como fazer a digitação
	scanf("%d,%d",&l,&c); // recebe a digitação do usuários
	m[l][c].conexao=0; // faz a desconexão
}
void conexao(matriz m[k][k]){
	int l,c; // declara variaveis
	printf("Digite a conexão deseja ligar no formado [origem],[destino]\nexemplo: 1,2  -  liga nó 1 no nó 2\n:"); // informa como fazer a digitação
	scanf("%d,%d",&l,&c); // recebe a digitação do usuário
	m[l][c].conexao=1; // faz a desconexão
}
int menu(){
	int opcao=0;
	while(opcao<1 || (opcao>4 && opcao !=9)){ // faz a verificação se a opção é válida
		printf("------------Menu------------\n"); // imprime menu
		printf("|1)Indicar nova conexão    |\n"); // imprime menu
		printf("|2)Indicar desconexão      |\n"); // imprime menu
		printf("|3)imprimir matriz conexões|\n"); // imprime menu
		printf("|4)imprimir status energia |\n"); // imprime menu
		printf("|9)Sair                    |\n"); // imprime menu
		printf("----------------------------\n"); // imprime menu
		scanf("%d",&opcao); // recebe a opção
	}
	return opcao; // retorna a opção digitada
}
int main(){
	setlocale(LC_ALL,"");// define o conjuntos de caracteres do SO para poder usar acentos e outros caracteres da lingua local
	int i,j,n,o; // declara variaveis
	matriz m[k][k]; // declara a matriz de adjacencias
	n=abre_arquivo(m); // carrega o arquino na matriz
	while(o!=9){ // verifica se foi escolhida a opção saida
		o=menu(); // imprime o menu e recebe a opção escolhida pelo usuário
		if (o==1) conexao(m); // chama a função de nova conexão
		else if (o==2) desconexao(m); // chama a função de desconexao
		else if (o==3) imprime_matriz(m,n); // imprime a vetor energia	
		else if (o==4) imprime_energia(m,n); // imprime a matriz	
		else printf("------Finalizando programa----"); // imprime mensagem de saida
	}
	return 0;
}
