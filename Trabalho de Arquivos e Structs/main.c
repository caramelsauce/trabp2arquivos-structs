#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Humanos{
	char nome[100];
	float str;//strength = força
};

struct cidadeHumanos{
	char nome_Cidade[100];
	struct Humanos *humano;
};

void f_humanos(struct cidadeHumanos ** cidades){
	FILE * fp;
	fp = fopen("humanos.txt", "r");
	int i, j, num_cidades = 0, num_humanos = 0;
	fscanf(fp, "%d", &num_cidades);
	*cidades = (struct cidadeHumanos *) calloc(num_cidades, 
	                                          sizeof(struct cidadeHumanos));
    for(i=0; i<num_cidades; i++){
    	fscanf(fp, "%s %d", cidades[i]->nome_Cidade, &num_humanos);
    	cidades[i]->humano = (struct Humanos *) calloc(num_humanos, 
		                                              sizeof(struct Humanos));
		for(j=0; j<num_humanos; j++){
			fscanf(fp, "%s %f", cidades[i]->humano[j].nome, 
			                    &cidades[i]->humano[j].str);
		}
	}
	fclose(fp);
}

int main(int argc, char ** argv){
	setlocale(LC_ALL, "Portuguese");
	struct cidadeHumanos * cidades_Humanos;
	f_humanos(&cidades_Humanos);
	printf("%s", cidades_Humanos[0].nome_Cidade);
	printf("\n %s", cidades_Humanos[0].humano[0].nome);
	return(0);
}