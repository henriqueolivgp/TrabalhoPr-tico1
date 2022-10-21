#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Implementações:
1.	Referencia de venda;
2.	Identificação de cliente; com referencia nueraria ex: cliente Nº1...
4.	Quantidades
5. 	Categorias de produtos ex(gelados, bebidas, confeitarias e padaria....)
-----------------------------------------------------------------------------
Requesitos e funcionalidades
1.	Introduzir a informação sobre uma venda;
2.	Listar informações sobre todas as vendas de um cliente;
3.	Modificar o preço e/ou quantidade de vendas de um dado cliente;
4.	Listar categorias, selecionar categoria e ver as vendas de cada categoria;
5.	Calcualr quantidade de vendas e total ganho em vendas de uma determinada categoria selecionada;
6.	Calcular a media dos preços das vendasd da padaria;
7.	Apresentar a informação da(s) venda(s) preço mais baixo;
Observação:
No final do ano a empresa deve pagar um imposto de 15% sobre todas as vendas
com custo inferior a 12€, e 19% sobre as restantes.
8.	Para cada categoria com vendas feitas apresentar:
	- A quantidade de vendas;
	- O total gerado por essas vendas;
	- O total de imoposto(15%) a pagar dessa categoria;
	- O total de imposto (19%) a pagar dessa categoria;
	* Apresentar os totais da informação apresentada acerca de cada categoria.
*/
void main(){
	setlocale(LC_ALL, "portuguese");
	printf("Bem Vindo a padaria P90\n");//mensagem de boas vindas
	printf("Insira o seu nome:");//pedir o nome da pessoa para guardar as informações
}

void menu(){
	printf("****Menu****");
	
}
