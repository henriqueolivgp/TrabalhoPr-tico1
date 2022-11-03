#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#define Clientes [15]

int g /*gelados*/ = 78, c /*confeiaria*/ = 35, p /*padaria*/ = 65, b /*bebidas*/ = 30; //define as variaveis que representa as categorias.
float p_g = 1.5, p_c = , p_p = 0, p_b = 0; //define as variaveis globais que vao armazenar o preço das categorias.
int tot_de_compras=0, tot_de_comp_inf_12=0, tot_comp_sup_12=0;//total de diferentes tipos de compras
float val_tot_comp=0;val_tot_com_inf=0,val_tot_sup=0;//valor total de dinheiro gasto em tipos
float media=0, imp_menor=0, imp_maior=0;//medias e impostos

int prog_categ(){
	char categoria;
	char alterar='\0',certa;
	int x = 0,cert;
	printf("\nQual é a categoria que deseja alterar o stock:");
	printf("\n|\'g'/|-Gelados-|");
	printf("\n|\'b'/|-Bebidas-|");
	printf("\n|\'p'/|-Padaria-|");
	printf("\n|\'c'/|-Confeitaria-|");
	scanf(" %c",&categoria);
	switch(categoria){
		
		case 'g':
			system("cls");
			printf("\n|\ Gelados /|.");
			printf("\nTem %i no stock de gelados",g);
			printf("\nDeseja adicionar ou retirar?\n");
			printf("\\|+|/|Adicionar|");
			printf("\\|-|/|retirar|\n");
			printf("Escolha: ");
			scanf(" %c", &alterar);
			if(alterar == '-'){
				printf("\nQuantidade a retirar: ");
				scanf("%i", &x);
				g=g-x;
			}if(alterar == '+'){
				printf("\nQuantidade a adicionar: ");
				scanf("%i",&x);
				g=g+x;
			}
			system("cls");
			printf("\nAgora tem %i no stock de gelados",s);
			printf("\nDeseja fazer mais alguma alteração numa outra categoria?");
			printf("\n|1 = SIM|0 = NÃO|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				prog_categ();
			}else{
				main();
			}

		break;
		
		case 'c':
			system("cls");
			printf("\nConfeitaria.");
			printf("\nTem %i no stock de confeitaria",c);
			printf("\nDeseja adicionar ou retirar?");
			printf("\\|+|/|Adicionar|");
			printf("\\|-|/|retirar|\n");
			printf("Escolha: ");
			scanf(" %c", &alterar);
			if(alterar == '-'){
				printf("\nQuantidade a retirar: ");
				scanf("%i", &x);
				c=c
				
				-x;
			}if(alterar == '+'){
				printf("\nQuantidade a adicionar: ");
				scanf("%i",&x);
				c=c+x;
			}
			system("cls");
			printf("\nAgora tem %i no stock de confeitaria",c);
			printf("\nDeseja fazer mais alguma alteração numa outra categoria?");
			printf("\n|1 = SIM|0 = NÃO|");
			printf("\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				prog_categ();
			}else{
				main();
			}
		break;
		
		case 'b':
			system("cls");
			printf("\nBebidas");
			printf("\nTem %i no stock de Bebidas",d);
			printf("\nDeseja adicionar ou retirar?");
			printf("\n\|+|/|Adicionar|");
			printf("\n\|-|/|retirar|\n");
			prinf("\nEscolha")
			scanf(" %c", &alterar);
			if(alterar == '-'){
				printf("\nQuantidade a retirar: ");
				scanf("%i", &x);
				d=d-x;
			}if(alterar == '+'){
				printf("\nQuantidade a adicionar: ");
				scanf("%i",&x);
				d=d+x;
			}
			system("cls");
			printf("\nAgora tem %i no stock de calças",d);
			printf("\nDeseja fazer mais alguma alteração numa outra categoria?");
			
			printf("\n|1 = SIM|0 = NÃO|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				prog_categ();
			}else{
				main();
			}
		break;
		case 'p':
				system("cls");
				printf("\nPadaria.");
				printf("\nTem %i no stock de padaria",a);
				printf("\nDeseja adicionar ou retirar?\nAdicionar: ----===+===----\nRetirar: ----===-===---- \nEscolha: ");
				scanf(" %c", &alterar);
				if(alterar == '-'){
					printf("\nQuantidade a retirar: ");
					scanf("%i", &x);
					a=a-x;
				}if(alterar == '+'){
					printf("\nQuantidade a adicionar: ");
					scanf("%i",&x);
					a=a+x;
				}
				system("cls");
				printf("\nAgora tem %i no stock de padaria",a);
				printf("\nDeseja fazer mais alguma alteração numa outra categoria?");
				
				printf("\n|1 = SIM|0 = NÃO|\nEscolha: ");
				scanf("%i",&cert);
				if(cert==1){
					prog_categ();
				}else{
					main();
				}
			break;
	}
}

int menu_ven(){//menu de venda
	char categ;
	printf("\nSelecione a categoria:");
	
	scanf(" %c", &categoria);
	switch(categoria){
		
		case 's':
			printf("\nGelados.");
			printf("\nEm stock temos %i.", g);
			printf("\nQuantos P");
			
		break;
		
		case 'c':
			printf("\nConfeitaria.");
			printf("\nEm stock temos %i.", c);
		break;
		
		case 'd':
			printf("\nBebidas.");
			printf("\nEm stock temos %i.", b);
		break;
		
		case 'a':
			printf("\nPadaria.");
			printf("\nEm stock temos %i.", p);
		break;
	}
}

int prog_hist_vend(){
}



int prog_cliente(){
}

void menu(){
	
	int op = 0;
	
	printf("\n     	     Menu	    ");
	printf("\nPor favor escolha a opcao que deseja com numeros");
	printf("\n\n1 -> Introduzir uma nova venda");
	printf("\n2 -> Listar a informacao de todas as vendas");
	printf("\n3 -> Ver stock/Aterar stock");
	printf("\n4 -> Introduzir uma venda(maneira simples sem referencia)");
	printf("\n5 -> Ver os impostos e médias");
	printf("\nOp: ");
	scanf("%i", &op);
	
	switch(op){
		
		case 1:
			novaVenda();
			menu()<
		break;
		
		
		case 2:
			
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

void categorias(){
	//mudar o stock de cada categoria
}
	
	
//Main function
void main() {
	
	printf("----Vendas de uma Padaria----");
	
	
	menu();
	
}
