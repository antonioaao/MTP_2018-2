/* P6.c */
/* Antonio Augusto Ananias Oliveira */
/* 11811EEL013 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

int main() 
{
    int n;
    ponto *p;
    printf("Quantas divisoes vossa senhoria deseja repartir a circunferencia? :  \n");
    scanf("%d",&n); 
	getchar();
    p = partir_esfera(n);
    mostrar_pontos(p,p+n);
    free(p);
    return 0;
}
