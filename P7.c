/* P7.c */
/* Antonio Augusto Ananias Oliveira */
/* 11811EEL013 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
	float x,y;
}ponto;

ponto *partir_esfera(int n)
{
    ponto *p =(ponto*)calloc(n,sizeof(ponto));
    int i;
    for (i=0;i<n;i++)
    {
        p[i].x = cos(i*2.0*M_PI/(n-1));
        p[i].y = sin(i*2.0*M_PI/(n-1));
    }
    return p;
}

void mostrar_pontos(ponto *ponto_inicial, ponto *ponto_final) 
{
    if(ponto_inicial < ponto_final)
	{
        printf("(%.3lf, %.3lf) ", ponto_inicial->x, ponto_inicial->y);
        mostrar_pontos(ponto_inicial+1,ponto_final);
    }
}

void grava_bin(ponto * ponto_inicial, int n) 
{
    FILE * arquivo;
    arquivo = fopen("pontos.dat", "wb");
    fwrite(ponto_inicial, n, sizeof(ponto), arquivo);
    fclose(arquivo);
}

ponto * le_bin (unsigned int * pn) 
{
    ponto * p = (ponto *) malloc(sizeof(ponto));
    unsigned int n = 0;
    FILE * arquivo;
    arquivo = fopen("pontos.dat", "rb");
    while(1) {
        fread(p, 1, sizeof(ponto), arquivo);
        if(feof(arquivo)) 
		break;
        n++;
    }
    rewind(arquivo);
    p = (ponto *) realloc(p, n*sizeof(ponto));
    fread(p, n, sizeof(ponto), arquivo);
    fclose(arquivo);
    *pn = n;
    return p;
}

int main() 
{
    int n,opcao;
    ponto *p;
    char fn[] = "Pontos.bin";
    printf("1 - Gravar arquivo: ; 2 - Ler arquivo: ");
    scanf("%d", &opcao);
    getchar();
    if(opcao==1)
    {
    	printf("Quantas divisoes vossa senhoria deseja repartir a circunferencia? :  \n");
        scanf("%d",&n); 
		getchar();
        p = partir_esfera(n);
        grava_bin(p,n);
        printf("Arquivo gravado!");
	}
	else 
	{
       p = le_bin(&n);
    	mostrar_pontos(p,p+n);
	}
    free(p);
    return 0;
}
