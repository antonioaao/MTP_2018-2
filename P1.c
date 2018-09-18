/* P1.c */
/* Antonio Augusto Ananias Oliveira */
/* 11811EEL013 */
#include <stdio.h>
int main()
{
	int estado=0, x=0;
	char bits[256];
	printf("\nDigite uma sequencia binaria, meu consagrado!\n");
	scanf("%s",&bits);
	while(bits[x]!= '\0')
	{
		if(estado==0 && bits[x]== '0')
		estado=0;
		else if(estado==0 && bits[x]=='1')
		estado=1;
		else if(estado==1 && bits[x]=='0')
		estado=2;
		else if(estado==1 && bits[x]=='1')
		estado=0;
		else if(estado==2 && bits[x]=='0')
		estado=1;
		else if(estado==2 && bits[x]=='1')
		estado=2;
		x++;
	}
	if(estado==0) printf("\n\"%s\" e multiplo de 3", bits);
	else printf("\n\"%s\" nao e", bits);
	return 0;
}
