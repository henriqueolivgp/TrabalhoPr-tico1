#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#define Clientes [15]


void menu(){
	
	int op = 0;
	
	printf("\n     	     Menu	    ");
	printf("\nPor favor escolha a opcao que deseja com numeros");
	printf("\n\n1 -> Introduzir uma nova venda");
	printf("\n2 -> Listar a informacao de todas as vendas");
	
	printf("\nOp: ");
	scanf("%i", &op);
	
	switch(op){
		
		case 1:{
			novaVenda();
			menu();
			break;
		}
		
		case 2:{
			break;
		}
	}
	
}

void novaVenda(){
	
	//Define Variables
	int ref[15];
	int i;
	int cliente;//teste
	
	printf("\nIntroduza uma nova venda");
	scanf("%i", cliente);
	
	
}

//Main function
void main() {
	
	printf("----Vendas de uma Padaria----");
	
	menu();
	
}
