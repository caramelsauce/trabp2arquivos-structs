#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
struct Humanos{
	char nome[100];
	float str;//strength = forï¿½a
};

struct Anjos{
	char nome[100];
	float capacidade_de_voo;
	float peso;
	float altura;
	float str;	
};

struct Demonios{
	char nome[100];
	float darkness;
	float visao;
	float str;
};


struct cidadeHumanos{
	char nome_Cidade[100];
	struct Humanos *humano;
	int num_humanos;
	float str;
};

struct cidadeAnjos{
	char nome_Cidade[100];
	struct Anjos *anjo;
	int num_anjos;
	float str;
};

struct cidadeDemonios{
	char nome_Cidade[100];
	struct Demonios *demonio;
	int num_demonios;
	float str;
};

struct foo{
	char nome[100];
	float str;
};


void f_demonios(struct cidadeDemonios ** cidades, int * num_cidades)
{
	FILE * fp;
	struct cidadeDemonios *cidades_aux;
	
	fp = fopen("demonios.txt", "r");
	int i, j;
	fscanf(fp, "%d", num_cidades);
	cidades_aux=(struct cidadeDemonios *) calloc(*num_cidades, sizeof(struct cidadeDemonios));
	
	for(i=0; i<*num_cidades; i++){
		fscanf(fp, "%s %d", cidades_aux[i].nome_Cidade, &cidades_aux[i].num_demonios);
		cidades_aux[i].demonio = (struct Demonios *) calloc(cidades_aux[i].num_demonios, sizeof(struct Demonios));
		for(j=0;j<cidades_aux[i].num_demonios; j++){
			fscanf(fp, "%s %f %f", cidades_aux[i].demonio[j].nome,
									&cidades_aux[i].demonio[j].darkness,
									&cidades_aux[i].demonio[j].visao);
           cidades_aux[i].demonio[j].str = pow((
                                     cidades_aux[i].demonio[j].darkness -
                                    (cidades_aux[i].demonio[j].visao/2))
									,2);
		}
	}
	*cidades = cidades_aux;
	fclose(fp);
}

void f_anjos(struct cidadeAnjos ** cidades, int * num_cidades)
{
	FILE * fp;
	struct cidadeAnjos *cidades_aux;
	
	fp = fopen("anjos.txt", "r");
	int i, j;
	fscanf(fp, "%d", num_cidades);
	cidades_aux=(struct cidadeAnjos *) calloc(*num_cidades, sizeof(struct cidadeAnjos));
	
	for(i=0; i<*num_cidades; i++){
		fscanf(fp, "%s %d", cidades_aux[i].nome_Cidade, &cidades_aux[i].num_anjos);
		cidades_aux[i].anjo = (struct Anjos *) calloc(cidades_aux[i].num_anjos, sizeof(struct Anjos));
		for(j=0;j<cidades_aux[i].num_anjos; j++){
			fscanf(fp, "%s %f %f %f", cidades_aux[i].anjo[j].nome,
								&cidades_aux[i].anjo[j].capacidade_de_voo,
								&cidades_aux[i].anjo[j].peso,
								&cidades_aux[i].anjo[j].altura);
			cidades_aux[i].anjo[j].str = (
                                (cidades_aux[i].anjo[j].capacidade_de_voo) *
								(pow(cidades_aux[i].anjo[j].altura, 2)) *
								(cidades_aux[i].anjo[j].peso) 	);				
		}
	}
	*cidades = cidades_aux;
	fclose(fp);
}

void f_humanos(struct cidadeHumanos ** cidades, int * num_cidades)
{
	FILE * fp;
	struct cidadeHumanos *cidades_aux;
	
	fp = fopen("humanos.txt", "r");
	int i, j;
	fscanf(fp, "%d", num_cidades);
	cidades_aux = (struct cidadeHumanos *) calloc(*num_cidades, sizeof(struct cidadeHumanos));
	
    for(i=0; i<*num_cidades; i++){
    	fscanf(fp, "%s %d", cidades_aux[i].nome_Cidade, &cidades_aux[i].num_humanos);
    	cidades_aux[i].humano = (struct Humanos *) calloc(cidades_aux[i].num_humanos, sizeof(struct Humanos));
		for(j=0; j<cidades_aux[i].num_humanos; j++){
			fscanf(fp, "%s %f", cidades_aux[i].humano[j].nome, 
			                    &cidades_aux[i].humano[j].str);
		}
	}
	*cidades = cidades_aux;
	fclose(fp);
}

void totalizarCidadesStrHumanos(struct cidadeHumanos ** cidades, int num_cidades)
{
	int i, j;
	struct cidadeHumanos *cidades_aux = *cidades;
	for(i=0; i<num_cidades; i++)
		for(j=0; j<cidades_aux[i].num_humanos; j++)
			cidades_aux[i].str += cidades_aux[i].humano[j].str;
	*cidades = cidades_aux;	
}		

void totalizarCidadesStrAnjos(struct cidadeAnjos ** cidades, int num_cidades)
{
	int i, j;
	struct cidadeAnjos *cidades_aux = *cidades;
	for(i=0; i<num_cidades; i++)
		for(j=0; j<cidades_aux[i].num_anjos; j++)
			cidades_aux[i].str += cidades_aux[i].anjo[j].str;
	*cidades = cidades_aux;	
}

void totalizarCidadesStrDemonios(struct cidadeDemonios ** cidades, int num_cidades)
{
	int i, j;
	struct cidadeDemonios *cidades_aux = *cidades;
	for(i=0; i<num_cidades; i++)
		for(j=0; j<cidades_aux[i].num_demonios; j++)
			cidades_aux[i].str += cidades_aux[i].demonio[j].str;
	*cidades = cidades_aux;	
}

float somaAAHumanos(struct cidadeHumanos *cidades, int num_cidades)
{
	int i, j, k, t, cont=0;
	float soma = 0;

    for(i=0;i<num_cidades;i++){
		for(j=0;j<cidades[i].num_humanos;j++){
			t = strlen(cidades[i].humano[j].nome);
			for(k=0;k<t;k++){
				if(cidades[i].humano[j].nome[k] == 'a')
				    cont++;
			}
			if(cont == 2)
			    soma += cidades[i].humano[j].str;
				cont = 0; 
		}
	}

	return soma;
}

float somaAAAnjos(struct cidadeAnjos *cidades, int num_cidades)
{
	int i, j, k, t, cont=0;
	float soma = 0;

    for(i=0;i<num_cidades;i++){
		for(j=0;j<cidades[i].num_anjos;j++){
			t = strlen(cidades[i].anjo[j].nome);
			for(k=0;k<t;k++){
				if(cidades[i].anjo[j].nome[k] == 'a')
				    cont++;
			}
			if(cont == 2)
			    soma += cidades[i].anjo[j].str;
				cont = 0; 
		}
	}

	return soma;
}

float somaAADemonios(struct cidadeDemonios *cidades, int num_cidades)
{
	int i, j, k, t, cont=0;
	float soma = 0;

    for(i=0;i<num_cidades;i++){
		for(j=0;j<cidades[i].num_demonios;j++){
			t = strlen(cidades[i].demonio[j].nome);
			for(k=0;k<t;k++){
				if(cidades[i].demonio[j].nome[k] == 'a')
				    cont++;
			}
			if(cont == 2)
			    soma += cidades[i].demonio[j].str;
				cont = 0; 
		}
	}

	return soma;
}

void printStrCidadesAnjos(struct cidadeAnjos *cidades, int num_cidades)
{
	int i;
	printf("Anjos:\n\n");
	for(i=0;i<num_cidades;i++){
		printf("   %s tem forï¿½a %.2f\n\n",cidades[i].nome_Cidade, cidades[i].str);
	}
	printf("\n\n");
}

void printStrCidadesHumanos(struct cidadeHumanos *cidades, int num_cidades)
{
    int i;
	printf("Humanos:\n\n");
	for(i=0;i<num_cidades;i++){
		printf("   %s tem forï¿½a %.2f\n\n",cidades[i].nome_Cidade, cidades[i].str);
	}
	printf("\n\n");
}

void printStrCidadesDemonios(struct cidadeDemonios *cidades, int num_cidades)
{
	int i;
	printf("Demonios:\n\n");
	for(i=0;i<num_cidades;i++){
		printf("   %s tem forï¿½a %.2f\n\n",cidades[i].nome_Cidade, cidades[i].str);
	}
	printf("\n\n");
}

void insertionSort(struct foo *vetor, int n)
{
	int i, j;
	struct foo temp;
	for(i=1; i<n; i++){
		temp = vetor[i];
		j = i - 1;
		while(j >= 0 && (vetor[j].str > temp.str)){
			vetor[j+1] = vetor[j];
			j = j - 1;
		}
		vetor[j+1] = temp;
	}
}

void printMenor(struct foo *vetor)
{
	int i = 1, j;
	if(vetor[0].str < vetor[1].str)
		printf("O ser mais fraco é: %s\n\n", vetor[0].nome);
	else{
	    while(vetor[i].str == vetor[i+1].str)
	    	i++;
	    printf("Os seres mais fracos são:");
	    for(j=0; j<=i; j++)
	    	printf(" %s,", vetor[j].nome);
	}
    printf("\n\n");
}

void printMaior(struct foo *vetor, int n)
{
	int i = n - 2, j;
	if(vetor[n-1].str > vetor[i].str)
		printf("O ser mais forte é: %s\n\n", vetor[n-1].nome);
	else{
		while(vetor[i].str == vetor[i-1].str)
			i--;
		printf("Os seres mais fracos são:");
		for(j=n-1; j>=i; j--)
			printf(" %s,",vetor[j].nome);
	}
	printf("\n\n");
}

void filipe(struct cidadeHumanos * cidades_Humanos, struct cidadeAnjos * cidades_Anjos, struct cidadeDemonios * cidades_Demonios, int num_cidadesHumanos, int num_cidadesAnjos, int num_cidadesDemonios)
{
	int i, j, k=0, p=0;
	struct foo * geral;
	
	for(i=0;i<num_cidadesHumanos;i++){
		p+=cidades_Humanos[i].num_humanos;
	}
	for(i=0;i<num_cidadesAnjos;i++){
		p+=cidades_Anjos[i].num_anjos;
	}
	for(i=0;i<num_cidadesDemonios;i++){
		p+=cidades_Demonios[i].num_demonios;
	}
	
	geral = (struct foo *) calloc(p, sizeof(struct foo));
	
	for(i=0;i<num_cidadesHumanos;i++){
		for(j=0;j<cidades_Humanos[i].num_humanos;j++){
			strcpy(geral[k].nome,cidades_Humanos[i].humano[j].nome);
			geral[k].str=cidades_Humanos[i].humano[j].str;
			k++;
		}
	}
	
	for(i=0;i<num_cidadesAnjos;i++){
		for(j=0;j<cidades_Anjos[i].num_anjos;j++){
			strcpy(geral[k].nome,cidades_Anjos[i].anjo[j].nome);
			geral[k].str=cidades_Anjos[i].anjo[j].str;
			k++;
		}
	}
	
	for(i=0;i<num_cidadesDemonios;i++){
		for(j=0;j<cidades_Demonios[i].num_demonios;j++){
			strcpy(geral[k].nome,cidades_Demonios[i].demonio[j].nome);
			geral[k].str=cidades_Demonios[i].demonio[j].str;
			k++;
		}
	}
	
	insertionSort(geral, p);
	printMenor(geral);
	printMaior(geral, p);

}

float totalizarStrHumanos(struct cidadeHumanos *cidades, int num_cidades)
{
	int i;
	float soma = 0;
	for(i=0; i<num_cidades; i++)
		soma += cidades[i].str;
	return soma;
}

float totalizarStrAnjos(struct cidadeAnjos *cidades, int num_cidades)
{
	int i;
	float soma = 0;
	for(i=0; i<num_cidades; i++)
		soma += cidades[i].str;
	return soma;
}

float totalizarStrDemonios(struct cidadeDemonios *cidades, int num_cidades)
{
	int i;
	float soma = 0;
	for(i=0; i<num_cidades; i++)
		soma += cidades[i].str;
	return soma;
}

void printOrdem(float humanos, float anjos, float demonios)
{
	printf("\n\nAs raças ordenadas por força: ");
	if(humanos < anjos && anjos < demonios)
		printf("Humanos, Anjos, Demonios.\n\n");
	else if(humanos < demonios && demonios < anjos)
		printf("Humanos, Demonios, Anjos.\n\n");
	else if(anjos < humanos && humanos < demonios)
		printf("Anjos, Humanos, Demonios.\n\n");
	else if(anjos < demonios && demonios < humanos)
		printf("Anjos, Demonios, Humanos.\n\n");
	else if(demonios < humanos && humanos < anjos)
		printf("Demonios, Humanos, Anjos.\n\n");
	else if(demonios < anjos && anjos < humanos)
		printf("Demonios, Anjos, Humanos.\n\n");
}

int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int num_cidadesHumanos, num_cidadesAnjos, num_cidadesDemonios;
	float soma2a, humanos_str, anjos_str, demonios_str;

//ler arquivos	

	struct cidadeHumanos * cidades_Humanos;
	f_humanos(&cidades_Humanos, &num_cidadesHumanos);
	struct cidadeAnjos * cidades_Anjos;
	f_anjos(&cidades_Anjos, &num_cidadesAnjos);
	struct cidadeDemonios * cidades_Demonios;
	f_demonios(&cidades_Demonios, &num_cidadesDemonios);
	
	
//totalizar forï¿½a das cidades

	totalizarCidadesStrHumanos(&cidades_Humanos, num_cidadesHumanos);
	totalizarCidadesStrAnjos(&cidades_Anjos, num_cidadesAnjos);
	totalizarCidadesStrDemonios(&cidades_Demonios, num_cidadesDemonios);

//soma das forï¿½as do indivï¿½duos com 2 letra 'a' no nome

	soma2a = somaAAHumanos(cidades_Humanos, num_cidadesHumanos) + somaAAAnjos(cidades_Anjos, num_cidadesAnjos) + somaAADemonios(cidades_Demonios, num_cidadesDemonios);

    humanos_str = totalizarStrHumanos(cidades_Humanos, num_cidadesHumanos);
    anjos_str = totalizarStrAnjos(cidades_Anjos, num_cidadesAnjos);
    demonios_str = totalizarStrDemonios(cidades_Demonios, num_cidadesDemonios);

//printar no console

    printStrCidadesAnjos(cidades_Anjos, num_cidadesAnjos);
	printStrCidadesHumanos(cidades_Humanos, num_cidadesHumanos);
	printStrCidadesDemonios(cidades_Demonios, num_cidadesDemonios);
    printf("A soma das forças dos indivíduos com letras 'a' no nome é: %.2f \n\n\n\n", soma2a);
	filipe(cidades_Humanos, cidades_Anjos, cidades_Demonios, num_cidadesHumanos, num_cidadesAnjos, num_cidadesDemonios);
	printOrdem(humanos_str, anjos_str, demonios_str);


	return(0);
}