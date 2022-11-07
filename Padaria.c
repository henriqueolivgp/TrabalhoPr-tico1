#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 30

//Variaveis utilizadas no stock e preços
int g = 1000; //Categoria Gelados
int c = 1000; //Categoria Confeitaria
int p = 1000; //Categoria Padaria
int b = 1000; //Categoria Bebidas

//Variaveis dos preços das categorias
float p_g = 2.00; //Preço dos gelados
float p_c = 3.00; //Preço das confeitarias
float p_p = 0.50; //Preço do pão
float p_b = 2.00; //reço das bebidas

//Valor de Produtos vendidos em cada categoria
int p_v_g = 0; //Quantidade de produtos vendidos na categoria Gelados
int p_v_c = 0; //Quantidade de produtos vendidos na categoria Confeitaria
int p_v_p = 0; //Quantidade de produtos vendidos na categoria Padaria
int p_v_b = 0; //Quantidade de produtos vendidos na categoria Bebida

//Totais de compras
int tot_de_compras=0; //Numero total de copras feitas
int tot_de_comp_inf_12=0; //Numero total de compras feitas inferiorres a 12€
int tot_de_comp_sup_12=0; //Numero total de compras superiores a 12€

//Variaveis para medias 
float val_tot_comp=0; //Valor total pago em todas as compras
float val_tot_com_inf=0; //Valor total pago em todas as compras inferiores a 12€
float val_tot_sup=0; //Valor total pago em todas as compras superiores a 12€

//arrays
int cliente[max]; //Guarda o numero do cartão de cliente de cada cliente
int	num_vend[max]; //Guarda o numero de venda
int	qnt_prod_vend[max];//Quantidade de produtos vendidos em cada compra
float val_venda[max];//Valor de venda de cada venda executada
char categ[max];//Categoria da qual foi feita a compra
int i=0;//indice das vareaveis



void menu(void);
void compra_finalizada(void);

//menu de alteração de stock
int prog_categ(){
	char categoria;
	char alterar='\0',certa;
	int x = 0,cert;
	printf("\nQual é a categoria que deseja alterar o stock:");
	printf("\n|\'g'/|-Gelados-|");
	printf("\n|\'b'/|-Bebidas-|");
	printf("\n|\'p'/|-Padaria-|");
	printf("\n|\'c'/|-Confeitaria-|");
	printf("\n|\'m'/|-Return Menu-|");
	scanf(" %c",&categoria);
	switch(categoria){
		//mudança ade stok da categoria dos gelados
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
				c=c-x;
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
			printf("\nAgora tem %i no stock de calças",b);
			printf("\nDeseja fazer mais alguma alteração numa outra categoria?");			
			printf("\n|1 = SIM|0 = NÃO|\nEscolha: ");
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
				printf("\nDeseja fazer mais alguma alteração numa outra categoria?");
				
				printf("\n|1 = SIM|0 = NÃO|\nEscolha: ");
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
	printf("\n|Qual a categoria de produto que deseja comprar?|");
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
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f",preco_final);
				printf("\nPasse o cartão");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				g=g-qnt_produtos;
				p_v_g=p_v_g+qnt_produtos;
				tot_de_compras++;
				tot_de_comp_inf_12++;
				val_tot_com_inf=val_tot_com_inf+preco_final;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}else if(preco>12){
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f",preco_final);
				printf("\nPasse o cartão");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				g=g-qnt_produtos;
				p_v_g=p_v_g+qnt_produtos;
				tot_de_compras++;
				val_tot_sup=val_tot_sup+preco_final;
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
				printf("\nPasse o cartão");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				p_v_c=p_v_c+qnt_produtos;
				tot_de_comp_inf_12++;
				val_tot_com_inf=val_tot_com_inf+preco_final;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}else if(preco>12){
				c=c-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f",preco_final);
				printf("\nPasse o cartão");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				p_v_c=p_v_c+qnt_produtos;
				tot_de_comp_sup_12++;
				val_tot_sup=val_tot_sup+preco_final;
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
				printf("\nPasse o cartão");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				p_v_b=p_v_b+qnt_produtos;
				tot_de_comp_inf_12++;
				val_venda[i]=preco_final;
				val_tot_com_inf=val_tot_com_inf+preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}else if(preco>12){
				b=b-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f");
				printf("\nPasse o cartão");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				p_v_b=p_v_b+qnt_produtos;
				tot_de_comp_sup_12++;
				val_tot_sup=val_tot_sup+preco_final;
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
				printf("\nPasse o cartão");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				p_v_p=p_v_p+qnt_produtos;
				tot_de_comp_inf_12++;
				val_tot_com_inf=val_tot_com_inf+preco_final;
				val_venda[i]=preco_final;
				qnt_prod_vend[i]=qnt_produtos;
				compra_finalizada();
			}else if(preco>12){
				p=p-qnt_produtos;
				preco_final=p_g*qnt_produtos;
				printf("\nA sua compra ficou em %.2f");
				printf("\nPasse o cartão");
				printf("\nInsira o pin:\n");
				scanf("%i",&pin);
				printf("\nCompra aprovada");
				tot_de_compras++;
				p_v_p=p_v_p+qnt_produtos;
				val_tot_sup=val_tot_sup+preco_final;
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
	float p_temp=0.0;//preço temporario
	printf("\n|Qual a categoria que deseja mudar de preço?|");
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
			printf("\nO preço atual dos gelados é de %.2f", p_g);
			printf("\nQual é o preço que deseja que seja?");
			printf("\nValor: ");
			scanf("%f",&p_temp);
			printf("\nO preço que antes era %.2f euros vai passar a ser %.2f euros",p_g,p_temp);
			printf("\nDeseja mesmo fazer a alteração?");
			printf("\n|1 = SIM|0 = NÃO|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				p_g=p_temp;
			}else{
				printf("\nOs valores não foram alterados o preço dos gelados continua %i",p_g);
				printf("\nDeseja voltar ao meni inicial ou quer mudar o preçario de alguma categoria?");
				printf("\n1 -> Voltar ao menu inicial");
				printf("\n2 -> Mudar preçario de alguma categoria");
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
			printf("\nO preço atual das bebidas é de %.2f", p_b);
			printf("\nQual é o preço que deseja que seja?");
			printf("\nValor: ");
			scanf("%f",&p_temp);
			printf("\nO preço que antes era %.2f euros vai passar a ser %.2f euros",p_b,p_temp);
			printf("\nDeseja mesmo fazer a alteração?");
			printf("\n|1 = SIM|0 = NÃO|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				p_b=p_temp;
			}else{
				printf("\nOs valores não foram alterados o preço dos gelados continua %i",p_b);
				printf("\nDeseja voltar ao meni inicial ou quer mudar o preçario de alguma categoria?");
				printf("\n1 -> Voltar ao menu inicial");
				printf("\n2 -> Mudar preçario de alguma categoria");
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
			printf("\nO preço atual dos gelados é de %.2f", p_c);
			printf("\nQual é o preço que deseja que seja?");
			printf("\nValor: ");
			scanf("%f",&p_temp);
			printf("\nO preço que antes era %.2f euros vai passar a ser %.2f euros",p_c);
			printf("\nDeseja mesmo fazer a alteração?");
			printf("\n|1 = SIM|0 = NÃO|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				p_c=p_temp;
			}else{
				printf("\nOs valores não foram alterados o preço dos gelados continua %i",p_c);
				printf("\nDeseja voltar ao meni inicial ou quer mudar o preçario de alguma categoria?");
				printf("\n1 -> Voltar ao menu inicial");
				printf("\n2 -> Mudar preçario de alguma categoria");
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
			printf("\nO preço atual dos produtos de padaraia é de %.2f", p_p);
			printf("\nQual é o preço que deseja que seja?");
			printf("\nValor: ");
			scanf("%f",&p_temp);
			printf("\nO preço que antes era %.2f euros vai passar a ser %.2f euros",p_p,p_temp);
			printf("\nDeseja mesmo fazer a alteração?");
			printf("\n|1 = SIM|0 = NÃO|\nEscolha: ");
			scanf("%i",&cert);
			if(cert==1){
				p_p=p_temp;
			}else{
				printf("\nOs valores não foram alterados o preço dos gelados continua %i",p_p);
				printf("\nDeseja voltar ao meni inicial ou quer mudar o preçario de alguma categoria?");
				printf("\n1 -> Voltar ao menu inicial");
				printf("\n2 -> Mudar preçario de alguma categoria");
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
		printf("\nCompra numero %i com o numero de cliente %i comprou %i na categoria %c e pagou %.2f.",x,cliente[x],qnt_prod_vend[x],categ[x],val_venda[x]);
	}
	printf("\nPara voltar para o menu inicial digite 1\n");
	scanf("%i",&ce);
}


void prog_impostos(){
	float imp_compras_men_12=0;
	float imp_compras_sup_12=0;
	float media_preco=0, media_prod=0;
	float imp_15=0.15;
	float imp_19=0.19;
	int escolha=0;
	imp_compras_men_12 = val_tot_com_inf*imp_15;
	imp_compras_sup_12 = val_tot_sup*imp_19;
	media_preco= val_tot_comp / tot_de_compras;
	Printf("\nCom um total de %i de vendas inferiores a 12euros.");
	printf("\nVai pagar %.2f de imposto das vendas com valor inferior a 12euros.",imp_compras_men_12);
	printf("\nCom um total de %i de vendas superiores a 12euros.");
	printf("\nVai pagar %.2f de imposto das vendas com valor superior a 12euros.",imp_compras_sup_12);
	printf("\nA media de valor de vendas é de %.2f.",media_preco);
	printf("\nA media de produtos vendidos é %.2f.",media_prod);
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
	printf("\n4 -> Alterar Preçario");
	printf("\n5 -> Ver os impostos e médias");
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
	setlocale(LC_ALL, "portuguese");
	while(1){
	printf("----Vendas de uma Padaria----");
	menu();
	}
}
