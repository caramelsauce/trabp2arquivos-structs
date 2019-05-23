#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Humanos{
	char nome[100];
	float str;//strength = força
};

struct Anjos{
	char nome[100];
	float capacidade_de_voo;
	float peso;
	float altura;	
};

struct Demonios{
	char nome[100];
	float darkness;
	float visao;
};


struct cidadeHumanos{
	char nome_Cidade[100];
	struct Humanos *humano;
};

struct cidadeAnjos{
	char nome_Cidade[100];
	struct Anjos *anjo;
};

struct cidadeDemonios{
	char nome_Cidade[100];
	struct Demonios *demonio;
};


void f_demonios(struct cidadeDemonios ** cidades){
	FILE * fp;
	struct cidadeDemonios *cidades_aux;
	
	fp = fopen("demonios.txt", "r");
	int i, j, num_cidades = 0, num_demonios = 0;
	fscanf(fp, "%d", &num_cidades);
	cidades_aux=(struct cidadeDemonios *) calloc(num_cidades, sizeof(struct cidadeDemonios));
	
	for(i=0; i<num_cidades; i++){
		fscanf(fp, "%s %d", cidades_aux[i].nome_Cidade, &num_demonios);
		cidades_aux[i].demonio = (struct Demonios *) calloc(num_demonios, sizeof(struct Demonios));
		for(j=0;j<num_demonios; j++){
			fscanf(fp, "%s %f %f", cidades_aux[i].demonio[j].nome,
									&cidades_aux[i].demonio[j].darkness,
									&cidades_aux[i].demonio[j].visao);
		}
	}
	*cidades = cidades_aux;
	fclose(fp);
}

void f_anjos(struct cidadeAnjos ** cidades){
	FILE * fp;
	struct cidadeAnjos *cidades_aux;
	
	fp = fopen("anjos.txt", "r");
	int i, j, num_cidades = 0, num_anjos = 0;
	fscanf(fp, "%d", &num_cidades);
	cidades_aux=(struct cidadeAnjos *) calloc(num_cidades, sizeof(struct cidadeAnjos));
	
	for(i=0; i<num_cidades; i++){
		fscanf(fp, "%s %d", cidades_aux[i].nome_Cidade, &num_anjos);
		cidades_aux[i].anjo = (struct Anjos *) calloc(num_anjos, sizeof(struct Anjos));
		for(j=0;j<num_anjos; j++){
			fscanf(fp, "%s %f %f %f", cidades_aux[i].anjo[j].nome,
								&cidades_aux[i].anjo[j].capacidade_de_voo,
								&cidades_aux[i].anjo[j].peso,
								&cidades_aux[i].anjo[j].altura);
		}
	}
	*cidades = cidades_aux;
	fclose(fp);
}

void f_humanos(struct cidadeHumanos ** cidades){
	FILE * fp;
	struct cidadeHumanos *cidades_aux;
	
	fp = fopen("humanos.txt", "r");
	int i, j, num_cidades = 0, num_humanos = 0;
	fscanf(fp, "%d", &num_cidades);
	cidades_aux = (struct cidadeHumanos *) calloc(num_cidades, sizeof(struct cidadeHumanos));
	
    for(i=0; i<num_cidades; i++){
    	fscanf(fp, "%s %d", cidades_aux[i].nome_Cidade, &num_humanos);
    	cidades_aux[i].humano = (struct Humanos *) calloc(num_humanos, sizeof(struct Humanos));
		for(j=0; j<num_humanos; j++){
			fscanf(fp, "%s %f", cidades_aux[i].humano[j].nome, 
			                    &cidades_aux[i].humano[j].str);
		}
	}
	*cidades = cidades_aux;
	fclose(fp);
}

int main(int argc, char ** argv){
	setlocale(LC_ALL, "Portuguese");
	
	struct cidadeHumanos * cidades_Humanos;
	f_humanos(&cidades_Humanos);
	struct cidadeAnjos * cidades_Anjos;
	f_anjos(&cidades_Anjos);
	struct cidadeDemonios * cidades_Demonios;
	f_demonios(&cidades_Demonios);
	
	
	printf("\n%s", cidades_Humanos[0].nome_Cidade);
	printf("\n %s\n", cidades_Humanos[0].humano[0].nome);
	
	printf("\n%s", cidades_Anjos[0].nome_Cidade);
	printf("\n %s\n", cidades_Anjos[0].anjo[0].nome);
	
	printf("\n%s", cidades_Demonios[0].nome_Cidade);
	printf("\n %s\n", cidades_Demonios[0].demonio[0].nome);
	
	return(0);
}