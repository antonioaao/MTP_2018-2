/* P4.c */
/* Antonio Augusto Ananias Oliveira */
/* 11811EEL013 */

#include <stdio.h>
int hackerman(int m, int n)
{
	if(m==0)
		return n+1;             
	else if(m>0 && n==0)
		hackerman(m-1,1);
	else if(m>0 && n>0)
		hackerman(m-1, hackerman(m,n-1));
}
int main()
{
	int m, n;
	printf("Por favor, digite o valor de m: \n");
	scanf("%d", &m);
	printf("Por favor, digite o valor de n: \n");
	scanf("%d", &n);
	printf("Resultado: %d", hackerman(m,n));
	return 0;
}
