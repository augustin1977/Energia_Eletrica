#include "energia_eletrica_funcoes_v2.h"
void imprime_pilha(int p[k], int n){ // fun��o que imprime a pilha (somente para debug)
	int i; // declara contador
	for (i=1;i<n;i++){ // percorre todos os elementos da pilha
		printf("%d ",p[i]); // imprime elemento da pilha
	}
	printf("\n");// pula linha ao final da impress�o
}
void limpa(matriz m[k], int n){ // fun�ao de limpeza da matriz
	int i,j;// declara��o das variaveis contadoras
	for(i=1;i<n+1;i++){ // percorre todas a linhas
	m[i].energia=0; // zera a energia
		for(j=0;j<n;j++){ // percorre todas as colunas
			m[i].conexao[j]=0; // zera a conex�o	
		}
	}
}
int push(int p[k], int i, int t){// fun��o que coloca item na pilha
	p[i]=t;// aloca o intero t na pilha
	i++;// incrementa contador da pilha
	return i;// retorna valor nivel da pilha
}
int pop(int p[k], int i){// fun��o que tira item da pilha
	i--;// decrementa contador da pilha 
	return i;// retorna nivel da pilha
}
void limpa_energia(matriz m[k], int p[k], int n){

	int i,j; // declara os contadores
	for(i=0;i<n;i++){ // percorre todas a colunas
 		m[i].energia=0; // zera a energia para fazer a analise do zero
		p[i]=-1; // coloca valor negativo na pilha para indicar n�o existencia de dados
	}
	m[1].energia=1;// a energia chega no elemento 1

}

void busca_energia(matriz m[k], int n){
	int i,j=1,l=1; // declara os contadores
	int p[k]; // declara a lista onde ser�o armazenados os n�s a serem percorridos
	limpa_energia(m,p,n); // limpa pilha para evitar lixo
	for (i=1;i<n;i++){ // percorre todas a linhas
		if (m[l].conexao[i]==1 && m[i].energia==0 && m[l].energia>=1){ // vefifica se ha conex�o e so o ponto ja est� sem enrgia (se ja estiver energizado por outro caminho segue para o proximo ponto)
			m[i].energia++; // caso positivo conta o numero de conex�es com energia
			j=push(p,j,i);	// empurra itens na pilha	
		}			
	}
	while(j>1){ // emquanto pilha n�o vazia
		j=pop(p,j);// retira item da pilha

		l=p[j]; //atribui valor tirado a variavel l
		for (i=1;i<n;i++){ // percorre todas a linhas
			if (m[l].conexao[i]==1 && m[i].energia==0 && m[l].energia>=1){ // vefifica se ha conex�o e so o ponto ja est� sem enrgia (se ja estiver energizado por outro caminho segue para o proximo ponto)
				m[i].energia++; // caso positivo conta o numero de conex�es com energia
				j=push(p,j,i); // empilha novos pontos encontrados
			}
		}
	}
}
int abre_arquivo(matriz m[k]){ // carrega os dados
	FILE *f; // declara o ponteiro para aqurivo
	char nome[100];
	int n,i,l,c,max,opcao; // declsara as variaveis contadoras e auxiliares
	printf("Deseja carregar o arquivo:\n(1)\"dados.txt\" \n(2)Outro Arquivo \n");
	scanf("%d",&opcao);
	if (opcao==2){
		printf("Digite o nome do arquivo que deseja carregar:\n");
		scanf("%s",&nome);
	} else strcpy(nome,"dados.txt");
	f=fopen(nome,"r"); // abre o arquivo
	fscanf(f,"%d,%d\n",&n,&max); // l� primeira linha o est� o numero de registros e o numero de n�s
	limpa(m,max); // chama a fun��o limpeza, ainda tem um erro aqui... limpando at� n e tem que limpar at� max
	for(i=1;i<n;i++){ // percorre o arquivo at� a linha n
		fscanf(f,"%d,%d",&l,&c); // le acada linha
		m[l].conexao[c]=1; // marca na matriz a conexao da linha e coluna
	}
	fclose(f);
	return max+1; // retorna o numero do maior vertice
}
void imprime_matriz(matriz m[k], int n){ // imprime a matriz
	int i,j; // declara contadores
	for (i=0;i<n;i++){ // percorre todas as colunas
		if (i==0) printf("   ");// deixa em branco o espa�o 0
		else printf("%2d ",i);// imprime indice de colunas
	}
	printf("\n"); // pula linha
	for(i=1;i<n;i++){ // percorre linhas
 	    printf("%2d ",i); // imprime indice de linhas
		for(j=1;j<n;j++){ // percorre colunas
			printf("%2d ",m[i].conexao[j]);	 // imprime colunas		
		}
		printf("\n");// pula para proxima linha
	}
}
void imprime_energia( matriz m[k], int n){ // imprime vetor de energia
	int i;// declara variavel contadora
	//energia(m,n);// verifica status de energia de todos os nos
	busca_energia(m,n);
	
	for (i=1;i<n;i++){ // corre todos os n�s
		printf("%2d ",i); // imprime indice de n�s
	}	
	printf("\n"); //salta linha
	for (i=1;i<n;i++){// corre todos os n�s
		printf("%2d ",m[i].energia); //// imprime status de n�s
	}
	printf("\n");//salta linha
}
void desconexao(matriz m[k]){
	int l,c; // declara variaveis
	printf("Digite a conex�o que deseja desligar no formado [origem],[destino]\nexemplo: 1,2  -  desliga n� 1 do n� 2\n:"); // informa como fazer a digita��o
	scanf("%d,%d",&l,&c); // recebe a digita��o do usu�rios
	m[l].conexao[c]=0; // faz a conex�o
}
void conexao(matriz m[k]){
	int l,c; // declara variaveis
	printf("Digite a conex�o deseja ligar no formado [origem],[destino]\nexemplo: 1,2  -  liga n� 1 no n� 2\n:"); // informa como fazer a digita��o
	scanf("%d,%d",&l,&c); // recebe a digita��o do usu�rio
	m[l].conexao[c]=1; // faz a desconex�o
}
int menu(){
	int opcao=0;// inicializa a variavel op��o
	while(opcao<1 || (opcao>4 && opcao !=9)){ // faz a verifica��o se a op��o � v�lida
		printf("------------Menu------------\n"); // imprime menu
		printf("|1)Indicar nova conex�o    |\n"); // imprime menu
		printf("|2)Indicar desconex�o      |\n"); // imprime menu
		printf("|3)imprimir matriz conex�es|\n"); // imprime menu
		printf("|4)imprimir status energia |\n"); // imprime menu
		printf("|9)Sair                    |\n"); // imprime menu
		printf("----------------------------\n"); // imprime menu
		scanf("%d",&opcao); // recebe a op��o
		printf("Op��o selecionada:%d\n",opcao);
	}
	return opcao; // retorna a op��o digitada
}
