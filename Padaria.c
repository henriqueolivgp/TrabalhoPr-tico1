#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Implementa��es:
1.	Referencia de venda;
2.	Identifica��o de cliente; com referencia nueraria ex: cliente N�1...
4.	Quantidades
5. 	Categorias de produtos ex(gelados, bebidas, confeitarias e padaria....)
-----------------------------------------------------------------------------
Requesitos e funcionalidades
1.	Introduzir a informa��o sobre uma venda;
2.	Listar informa��es sobre todas as vendas de um cliente;
3.	Modificar o pre�o e/ou quantidade de vendas de um dado cliente;
4.	Listar categorias, selecionar categoria e ver as vendas de cada categoria;
5.	Calcualr quantidade de vendas e total ganho em vendas de uma determinada categoria selecionada;
6.	Calcular a media dos pre�os das vendasd da padaria;
7.	Apresentar a informa��o da(s) venda(s) pre�o mais baixo;
Observa��o:
No final do ano a empresa deve pagar um imposto de 15% sobre todas as vendas
com custo inferior a 12�, e 19% sobre as restantes.
8.	Para cada categoria com vendas feitas apresentar:
	- A quantidade de vendas;
	- O total gerado por essas vendas;
	- O total de imoposto(15%) a pagar dessa categoria;
	- O total de imposto (19%) a pagar dessa categoria;
	* Apresentar os totais da informa��o apresentada acerca de cada categoria.
*/
void menu(){
	system("cls");
	int escolha=0;
	while(1){
		printf("---------Menu--------");
		printf("\nPrima 1 para ver historico de vendas.");
		printf("\nPrima 2 para ver as categorias e stock de produtos.");
		printf("\nPrima 3 para executar uma venda.");
		printf("\nEscolha: ");
		scanf("%i",&escolha);
		switch(escolha){
			case 1:
				ref_vend();
			break;
			
			case 2:
				qnt_prod();
			break;
			
			default:
				printf("\nOpera��o invalida ;-;");
			break;
		}
	}
}
int ref_vend(){
	system("cls");
	int ref=0;
	printf("insira o seu numero de cliente: ");
	scanf("%i",&ref);
	return 0;
}
int qnt_prod(){
	system("cls");
	int escolha=0;
	printf("\nExistem %i de produtos de padaria.");
	printf("\nExistem %i de produtos de bebidas.");
	printf("\nExistem %i de produtos de gelados.");
	printf("\nExistem %i de produtos de confeitaria.");
	
}
void main(){
	setlocale(LC_ALL, "portuguese");
	printf("Bem Vindo a padaria P90\n");//mensagem de boas vindas
	menu();
}


