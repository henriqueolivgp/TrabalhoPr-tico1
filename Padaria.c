#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#define max 30

//Variaveis utilizadas no stock e pre�os
int g = 78; //Categoria Gelados
int c = 35; //Categoria Confeitaria
int p = 65; //Categoria Padaria
int b = 30; //Categoria Bebidas

//Variaveis dos pre�os das categorias
float p_g = 2.00; //Pre�o dos gelados
float p_c = 3.00; //Pre�o das confeitarias
float p_p = 0.50; //Pre�o do p�o
float p_b = 2.00; //re�o das bebidas


//Totais de compras
int tot_de_compras=0; //Numero total de copras feitas
int tot_de_comp_inf_12=0; //Numero total de compras feitas inferiorres a 12�
int tot_de_comp_sup_12=0; //Numero total de compras superiores a 12�

//Variaveis para medias 
float val_tot_comp=0; //Valor total pago em todas as compras
float val_tot_com_inf=0; //Valor total pago em todas as compras inferiores a 12�
float val_tot_sup=0; //Valor total pago em todas as compras superiores a 12�

//arrays
int cliente[max] //Guarda o numero do cart�o de cliente de cada cliente
int	num_vend[max] //Guarda o numero de venda
int	qnt_prod_vend[max];//Quantidade de produtos vendidos em cada compra
float val_venda[max];//Valor de venda de cada venda executada
char categ[max];//Categoria da qual foi feita a compra
int i=0;//indice das vareaveis



void menu(void);

//menu de altera��o de stock
int prog_categ(){
	char categoria;
	char alterar='\0',certa;
	int x = 0,cert;
	printf("\nQual � a categoria que deseja alterar o stock:");
	printf("\n|\'g'/|-Gelados-|");
	printf("\n|\'b'/|-Bebidas-|");
	printf("\n|\'p'/|-Padaria-|");
	printf("\n|\'c'/|-Confeitaria-|");
	printf("\n|\'m'/|-Return Menu-|");
	scanf(" %c",&categoria);
	switch(categoria){
		//mudan�a ade stok da categoria dos gelados
		case 'g':
			system("cls");
			printf("\n Gelados /|");
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
			printf("\nAgora tem %i no stock de gelados",g);
			printf("\nDeseja fazer mais alguma altera��o numa outra categoria?");
			printf("\n|1 = SIM|0 = N�O|\nEscolha: ");
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
				c=c-x;
			}if(alterar == '+'){
				printf("\nQuantidade a adicionar: ");
				scanf("%i",&x);
				c=c+x;
			}
			system("cls");
			printf("\nAgora tem %i no stock de confeitaria",c);
			printf("\nDeseja fazer mais alguma altera��o numa outra categoria?");
			printf("\n|1 = SIM|0 = N�O|");
			printf("\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				prog_categ();
			}else{
				menu();
			}
		break;
		
		case 'b':
			system("cls");
			printf("\nBebidas");
			printf("\nTem %i no stock de Bebidas",b);
			printf("\nDeseja adicionar ou retirar?");
			printf("\n|+|/|Adicionar|");
			printf("\n|-|/|retirar|\n");
			printf("\nEscolha");
			scanf(" %c", &alterar);
			if(alterar == '-'){
				printf("\nQuantidade a retirar: ");
				scanf("%i", &x);
				b=b-x;
			}if(alterar == '+'){
				printf("\nQuantidade a adicionar: ");
				scanf("%i",&x);
				b=b+x;
			}
			system("cls");
			printf("\nAgora tem %i no stock de cal�as",b);
			printf("\nDeseja fazer mais alguma altera��o numa outra categoria?");			
			printf("\n|1 = SIM|0 = N�O|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				prog_categ();
			}else{
				menu();
			}
		break;
		case 'p':
				system("cls");
				printf("\nPadaria.");
				printf("\nTem %i no stock de padaria",p);
				printf("\nDeseja adicionar ou retirar?\nAdicionar: ----===+===----\nRetirar: ----===-===---- \nEscolha: ");
				scanf(" %c", &alterar);
				if(alterar == '-'){
					printf("\nQuantidade a retirar: ");
					scanf("%i", &x);
					p=p-x;
				}if(alterar == '+'){
					printf("\nQuantidade a adicionar: ");
					scanf("%i",&x);
					p=p+x;
				}
				system("cls");
				printf("\nAgora tem %i no stock de padaria",p);
				printf("\nDeseja fazer mais alguma altera��o numa outra categoria?");
				
				printf("\n|1 = SIM|0 = N�O|\nEscolha: ");
				scanf("%i",&cert);
				if(cert==1){
					prog_categ();
				}else{
					menu();
				}
			break;
			case 'm':
				menu();
			break;
	}
}

//menu de venda
int menu_venda(){
	int qnt_produtos=0,pin=0;
	float preco_final=0,preco=0;
	printf("\n|Qual a categoria que deseja mudar de pre�o?|");
	printf("\n|\'g'/|-Gelados-|");
	printf("\n|\'b'/|-Bebidas-|");
	printf("\n|\'p'/|-Padaria-|");
	printf("\n|\'c'/|-Confeitaria-|");
	printf("\n|-Escolha-| ");
	scanf(" %c",&categ[i]);
	switch(categ[i]){
		case 'g':
			printf("\nGelados.");
			printf("\nEm stock temos %i.", g);
			printf("\nQuantos deseja comprar?");
			scanf("%i",&qnt_produtos);
			preco=p_g*qnt_produtos;
			if(preco<12){
				g=g-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f",preco_final);
				printf("\nPasse o cart�o");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				tot_de_comp_inf_12++;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}else if(preco>12){
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f",preco_final);
				printf("\nPasse o cart�o");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				g=g-qnt_produtos;
				tot_de_compras++;
				tot_de_comp_sup_12++;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;	
				compra_finalizada();
			}
			
		break;
		
		case 'c':
			printf("\nConfeitaria.");
			printf("\nEm stock temos %i.", c);
			printf("\nQuantos deseja comprar?");
			scanf("%i",&qnt_produtos);
			preco=p_c*qnt_produtos;
			if(preco<12){
				c=c-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f",preco_final);
				printf("\nPasse o cart�o");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				tot_de_comp_inf_12++;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}else if(preco>12){
				c=c-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f",preco_final);
				printf("\nPasse o cart�o");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				tot_de_comp_sup_12++;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}
		break;
		
		case 'b':
			printf("\nBebidas.");
			printf("\nEm stock temos %i.", b);
			printf("\nQuantos deseja comprar?");
			scanf("%i",&qnt_produtos);
			preco=p_b*qnt_produtos;
			if(preco<12){
				b=b-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f");
				printf("\nPasse o cart�o");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				tot_de_comp_inf_12++;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}else if(preco>12){
				b=b-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f");
				printf("\nPasse o cart�o");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				tot_de_comp_sup_12++;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}
		break;
		
		case 'p':
			printf("\nPadaria.");
			printf("\nEm stock temos %i.", p);
			printf("\nQuantos deseja comprar?");
			scanf("%i",&qnt_produtos);
			preco=p_p*qnt_produtos;
			if(preco<12){
				p=p-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f");
				printf("\nPasse o cart�o");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				tot_de_comp_inf_12++;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}else if(preco>12){
				p=p-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f");
				printf("\nPasse o cart�o");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				tot_de_comp_sup_12++;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
		break;
		}
	}
}

void compra_finalizada(){
	i++;
	menu();
}

void prog_precario(){
	char escolha=0;
	int esc;
	int cert=0;
	float p_temp=0.0;//pre�o temporario
	printf("\n|Qual a categoria que deseja mudar de pre�o?|");
	printf("\n|\'g'/|-Gelados-|");
	printf("\n|\'b'/|-Bebidas-|");
	printf("\n|\'p'/|-Padaria-|");
	printf("\n|\'c'/|-Confeitaria-|");
	printf("\n|-Escolha-| ");
	scanf(" %c",&escolha);
	switch(escolha){
		case 'g':
			system("cls");
			printf("\nSelecionou a categoria gelados.");
			printf("\nO pre�o atual dos gelados � de %.2f", p_g);
			printf("\nQual � o pre�o que deseja que seja?");
			printf("\nValor: ");
			scanf("%f",&p_temp);
			printf("\nO pre�o que antes era %.2f euros vai passar a ser %.2f euros",p_g,p_temp);
			printf("\nDeseja mesmo fazer a altera��o?");
			printf("\n|1 = SIM|0 = N�O|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				p_g=p_temp;
			}else{
				printf("\nOs valores n�o foram alterados o pre�o dos gelados continua %i",p_g);
				printf("\nDeseja voltar ao meni inicial ou quer mudar o pre�ario de alguma categoria?");
				printf("\n1 -> Voltar ao menu inicial");
				printf("\n2 -> Mudar pre�ario de alguma categoria");
				scanf("%i",&esc);
				switch(esc){
					case 1:
						menu();
					break;
					
					case 2:
						prog_precario();
					break;
				}
			}
		case 'b':
			system("cls");
			printf("\nSelecionou a categoria bebidas.");
			printf("\nO pre�o atual das bebidas � de %.2f", p_b);
			printf("\nQual � o pre�o que deseja que seja?");
			printf("\nValor: ");
			scanf("%f",&p_temp);
			printf("\nO pre�o que antes era %.2f euros vai passar a ser %.2f euros",p_b,p_temp);
			printf("\nDeseja mesmo fazer a altera��o?");
			printf("\n|1 = SIM|0 = N�O|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				p_b=p_temp;
			}else{
				printf("\nOs valores n�o foram alterados o pre�o dos gelados continua %i",p_b);
				printf("\nDeseja voltar ao meni inicial ou quer mudar o pre�ario de alguma categoria?");
				printf("\n1 -> Voltar ao menu inicial");
				printf("\n2 -> Mudar pre�ario de alguma categoria");
				scanf("%i",&esc);
				switch(esc){
					case 1:
						menu();
					break;
					
					case 2:
						prog_precario();
					break;
				}
			}
		break;
		
		case 'c':
			system("cls");
			printf("\nSelecionou a categoria confeitaria.");
			printf("\nO pre�o atual dos gelados � de %.2f", p_c);
			printf("\nQual � o pre�o que deseja que seja?");
			printf("\nValor: ");
			scanf("%f",&p_temp);
			printf("\nO pre�o que antes era %.2f euros vai passar a ser %.2f euros",p_c);
			printf("\nDeseja mesmo fazer a altera��o?");
			printf("\n|1 = SIM|0 = N�O|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				p_c=p_temp;
			}else{
				printf("\nOs valores n�o foram alterados o pre�o dos gelados continua %i",p_c);
				printf("\nDeseja voltar ao meni inicial ou quer mudar o pre�ario de alguma categoria?");
				printf("\n1 -> Voltar ao menu inicial");
				printf("\n2 -> Mudar pre�ario de alguma categoria");
				scanf("%i",&esc);
				switch(esc){
					case 1:
						menu();
					break;
					
					case 2:
						prog_precario();
					break;
				}
			}
		case 'p':
			system("cls");
			printf("\nSelecionou a categoria padaria.");
			printf("\nO pre�o atual dos produtos de padaraia � de %.2f", p_p);
			printf("\nQual � o pre�o que deseja que seja?");
			printf("\nValor: ");
			scanf("%f",&p_temp);
			printf("\nO pre�o que antes era %.2f euros vai passar a ser %.2f euros",p_p,p_temp);
			printf("\nDeseja mesmo fazer a altera��o?");
			printf("\n|1 = SIM|0 = N�O|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				p_p=p_temp;
			}else{
				printf("\nOs valores n�o foram alterados o pre�o dos gelados continua %i",p_p);
				printf("\nDeseja voltar ao meni inicial ou quer mudar o pre�ario de alguma categoria?");
				printf("\n1 -> Voltar ao menu inicial");
				printf("\n2 -> Mudar pre�ario de alguma categoria");
				scanf("%i",&esc);
				switch(esc){
					case 1:
						menu();
					break;
					
					case 2:
						prog_precario();
					break;
				}
			}
	}
}



int prog_hist_vend(){
	system("cls");
	int x=0,ce=0;
	for(x=0;x<tot_de_compras;x++){
		printf("\nCompra numero %i com o numero de cliente %i comprou %i na categoria %c e pagou %.2f.", i,cliente[x],qnt_prod_vend[x],categ[x],val_venda[x]);
	}
	printf("\nPara voltar para o menu inicial digite 1\n");
	scanf("%i",&ce);
}


void prog_impostos(){
//int tot_de_compras=0, tot_de_comp_inf_12=0, tot_de_comp_sup_12=0;//total de diferentes tipos de compras
//float val_tot_comp=0,val_tot_com_inf=0,val_tot_sup=0;//valor total de dinheiro gasto em tipos
	float imp_compras_men_12=0;
	float imp_compras_sup_12=0;
	float media_preco=0, media_prod=0;
	int escolha
	imp_compas_men_12 = val_tot_com_inf*0.15;
	imp_compras_sup_12 = val_top_sup*0.19;
	printf("\nVai pagar %.2f de imposto das vendas com valor inferior a 12�.");
	printf("\nVai pagar %.2f de imposto das vendas com valor superior a 12�.");
	printf("\nA media de produtos vendidos � %.2f.");
	printf("\nA media de valor de vendas � de %.2f");
	printf("\n\n\n\n\nPara voltar ao menu inicial insira 1");
	scanf("%i",&escolha);
	if(escolha==1){
		main();
	}
	
}

void novaVenda(){
	//Define Variables
	printf("\nIntroduza uma nova venda");
	printf("\nInsira a sua referencia: ");
	scanf("%i",&cliente[i]);
	menu_venda();
	
}

void menu(){
	int op = 0;
	printf("\n     	     Menu	    ");
	printf("\nPor favor escolha a opcao que deseja com numeros");
	printf("\n\n1 -> Introduzir uma nova venda");
	printf("\n2 -> Listar a informacao de todas as vendas");
	printf("\n3 -> Ver stock/Aterar stock");
	printf("\n4 -> Alterar Pre�ario");
	printf("\n5 -> Ver os impostos e m�dias");
	printf("\nOp: ");
	scanf("%i", &op);
	
	switch(op){
		
		case 1:
			novaVenda();
			menu();
		break;

		case 2:
			prog_hist_vend();
		break;
		
		case 3:
			prog_categ();
		break;
		case 4:
			prog_precario();
		break;
		case 5:
			prog_impostos();
		break;

		}
	}
	
	
//Main function
int main(){
	while(1){
	printf("----Vendas de uma Padaria----");
	menu();
	}
}
