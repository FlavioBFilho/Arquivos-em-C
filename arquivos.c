#include <stdio.h>
#include <string.h>

int checkOpen(FILE *arq){
	if(arq==NULL){
		printf("\nErro ao abrir o arquivo\nTente novamente...\n");
		return 0;
	}
	else{
		printf("\nArquivo aberto com sucesso\n");
		return 1;
	}
}

void insertName(char name[]){
	printf("Insira o nome do arquivo a ser aberto: ");
	scanf("%s", name);
}

int main(void){
	FILE *arq;
	char s[20], n[20], c, r;
	int op;
	
	printf("Seja bem vindo!");
	do{
		printf("\n\nVoce deseja:\n1 - Ler um arquivo\n2 - Gravar nova informacao em um arquivo\n3 - Criar novo arquivo\n4 - Consultar seus arquivos\n5 - Encerrar\n->");
		scanf("%d", &op);
		system("cls");
		switch(op){
			case 1:
				insertName(n);
				arq = fopen(strcat(n, ".txt"), "r");
				if(checkOpen(arq)){
					printf("\nSegue o conteudo do arquivo:\n");
					while(fgets(s, 20, arq)!=NULL){
						printf("%s", s);
					}
				}
				fclose(arq);
				printf("\n\n");
				system("pause");
				system("cls");
			break;
			case 2:
				insertName(n);
				arq = fopen(strcat(n, ".txt"), "r");
				if(checkOpen(arq)){
					fclose(arq);
					arq = fopen(n, "a");
					do{
						printf("Digite o conteudo a ser gravado no arquivo:\n->");
						getchar();
						scanf("%[^\n]s", s);
						fprintf(arq, "\n%s", s);
						printf("Continuar?[S/N]\n->");
						getchar();
						scanf("%c", &r);
						system("cls"); 
					}while(r!='N');
				}
				fclose(arq);
				printf("\n");
				system("pause");
				system("cls");	
			break;
			case 3:
				printf("De um nome ao seu arquivo: ");
				scanf("%s", n);
				arq = fopen("lista_arquivos.txt", "a");
				fprintf(arq, "%s\n", n);
				fclose(arq);
				arq = fopen(strcat(n, ".txt"), "w");
				printf("De um titulo ao seu arquivo: ");
				getchar();
				scanf("%[^\n]s", s);
				fprintf(arq, "%s", s);
				fclose(arq);
				printf("\n");
				system("pause");
				system("cls");
			break;
			case 4:
				arq = fopen("lista_arquivos.txt", "r");
				if(checkOpen(arq)){
					printf("\nSegue lista de arquivos:\n");
					while(fgets(s, 20, arq)!=NULL){
						printf("%s", s);
					}
				}
				else{
					printf("\nVoce nao tem arquivos criados\n");
				}
				fclose(arq);
				printf("\n");
				system("pause");
				system("cls");					
			break;
			case 5:
				printf("\nAte mais...\n");
			break;
			default:
				printf("Comando invalido\nTente novamente...");
			break;
		}
	}while(op!=5);
	return 0;
}
