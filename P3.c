/* P3.c */
/* Antonio Augusto Ananias Oliveira */
/* 11811EEL013 */
#include <stdio.h>
int main ()
{	
	char numero[256];
	int numero_final[256], i, j, k=0;
	numero_final[0]=0;
	printf("Manda a frase ai companheiro! ");
	scanf("%s", numero);
	for(i=0; numero[i] != '\0'; i++)
	{	
		if(numero[i] >= 48 && numero[i] <= 57)
		{
			numero_final[k] = numero[i] - 48;
			k++;	
		}
	}
	printf("Valor numerico = ");
	if (k==0)
		k=1;
	for(j=0;j<k;j++)	
		printf("%d", numero_final[j]);
	return 0;
}
