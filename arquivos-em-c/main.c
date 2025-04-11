#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

/*Implementar um Algoritmo que possa simular um pedido de venda, devera ser informado:
codigo do produto, descricao, quantidade, valor unitario, valor total. O algoritmo devera
permitir o armazenamento em arquivo de texto*/

int i, quantidade, codigoProduto;
float valorUnitario, valorTotal;
char descricao[80];

FILE* arquivo;
void criarArquivo() {
	arquivo = fopen("C://temp//VendaProduto.txt", "w+");
	if (arquivo == NULL) {
		printf("Erro ao criar o arquivo. Verifique se o diretorio existe\n");

	}
	else {
		printf("Arquivo criado com sucesso!!\n");
	}
}

void VendaProduto() {
	printf("Digite o codigo: \n");
	scanf("%i", &codigoProduto);
	printf("Digite o nome do produto: \n");
	scanf("%s", &descricao);
	printf("Digite a quantidade: \n");
	scanf("%i", &quantidade);
	printf("Informe o valor: \n");
	scanf("%f", &valorUnitario);
	valorTotal = quantidade * valorUnitario;
}

void EmitirCupom() {
	fprintf(arquivo, "+==================================+\n");
	fprintf(arquivo, "|          CUPOM FISCAL            |\n");
	fprintf(arquivo, "|----------------------------------|\n");
	fprintf(arquivo, "|Codigo...............:%i|\n", codigoProduto);
	fprintf(arquivo, "|Descricao............:%s|\n", descricao);
	fprintf(arquivo, "|Quantidade...........:%i|\n", quantidade);
	fprintf(arquivo, "|Valor Unitario.......:%f|\n", valorUnitario);
	fprintf(arquivo, "|----------------------------------|\n");
	fprintf(arquivo, "|       Valor Total R$:%.2f        |\n", valorTotal);
	fprintf(arquivo, "+==================================+\n");
	fprintf(arquivo, "|            Num Cupom:%i|\n", i);
	fprintf(arquivo, "+==================================+\n");
}

main() {
	setlocale(LC_ALL, "");
	criarArquivo();
	while (i <= 3) {
		i++;
		VendaProduto();
		EmitirCupom();
	}
	printf("Venda realizada com sucesso. Verifique o arquivo VendaProduto.txt");
	fclose(arquivo);
}