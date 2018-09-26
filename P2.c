/* P2.c */
/* Antonio Augusto Ananias Oliveira */
/* 11811EEL013 */
#include <stdio.h>
int basebin()
{	int  bin1[100], i, j=0, n=1, soma=0, x=0;
	char bin[100];
	printf("Digite um numero Binario:");
	scanf("%s", bin);
	for(i=0; bin[i] != '\0'; i++);
	i--;
	x=i;
	do
	{	if(bin[i] == '0') {bin1[i] = 0; }
		else if(bin[i] == '1') {bin1[i] = 1;}
		i--;
	}while(i>=0);
	i = x;
	do
	{	for(x=0; x<j; x++)
		{	n*=2;	}
		soma += bin1[i]*n;
		n=1;
		i--;
		j++;
	}while(i>=0);
	printf("\n%d", soma);
	return soma;}
int basehex()
{	int  bin1[100], i, j=0, n=1, soma=0, x=0;
	char bin[100];
	printf("Digite um numero Binario:");
	scanf("%s", bin);
	for(i=0; bin[i] != '\0'; i++);
	i--;
	x=i;
	do
	{	if(bin[i] == '0') {bin1[i] = 0; }
		else if(bin[i] == '1') {bin1[i] = 1;}
		i--;
	}while(i>=0);
	i = x;
	do
	{	for(x=0; x<j; x++)
		{	n*=2;	}
		soma += bin1[i]*n;
		n=1;
		i--;
		j++;
	}while(i>=0);
	return soma;
}
int basedec()
{	int dec[100], num, i, base=2;
	printf("Digite um numero Decimal:");
	scanf("%d", &num);
	for(i=0; num >= base; i++)
	{	dec[i] = num%base;
		num = num/base;
		if(num < base)
		{	i++;
			dec[i] = num;	}
	} 
	i--;
	do
	{	printf("%d", dec[i]);
		i--;	
	}while(i>=0); 
	return dec[i];
}
void hextobin()
{	char hex[100];
	int  num, i, j=0, n=1, temp, soma=0, k=0, base=2;
	printf("\nDigite um numero Hexadecimal: ");
	scanf("%s", hex);
	for(i=0; hex[i] != '\0'; i++);
	i--;
	temp = i;
	k=i;
	do
	{	if(hex[i] == 'A' || hex[i] == 'a') 
		hex[i] = 10;
		else if(hex[i] == 'B' || hex[i] == 'b') 
		hex[i] = 11;
		else if(hex[i] == 'C' || hex[i] == 'c') 
		hex[i] = 12;
		else if(hex[i] == 'D' || hex[i] == 'd') 
		hex[i] = 13;
		else if(hex[i] == 'E' || hex[i] == 'e') 
		hex[i] = 14;
		else if(hex[i] == 'F' || hex[i] == 'f') 
		hex[i] = 15;
		else hex[i] -= 48;
		i--;						
	}while(i>=0);
	i = temp;
	do
	{	for(k=0; k<j; k++)
		{	n*=16;	}
		soma += hex[i]*n;
		n=1;	i--;	j++;
	}while(i>=0);
	if(base == 2)
	{	for(i=0; soma >= base; i++)
		{	hex[i] = soma%base;
			soma = soma/base;
			if(soma < base)
			{	i++;
				hex[i] = soma;		}
		} i--;
		printf("\n");
		do{	
			printf("%d", hex[i]);
			i--;	
		}while(i>=0); 	}
}
int main()
{	int opcao, dec, hex, oct, num_bin, num_dec;
	char bin;
	printf("Escolha uma opcao:\n\n 1 - Binario para Decimal.\n 2 - Binario para Hexadecimal.");
	printf("\n 3 - Hexadecimal para Decimal.\n 4 - Hexadecimal Para Binario.");
	printf("\n 5 - Decimal para Binario.\n 6 - Decimal para Hexadecimal.");
	printf("\n 7 - Octal para Decimal.\n 8 - Decimal para Octal.\n");
	scanf("%d", &opcao);
	switch(opcao)
	{	case 1:
			num_bin=basebin();
			break;
		case 2:
			num_bin=basehex();
			printf("\n%x",num_bin);
			break;
		case 3:
			printf("Digite um numero Hexadecimal:");
			scanf("%x", &hex);
			printf("\n%d",hex);
			break;
		case 4:
			hextobin();
			break;
		case 5:
			num_dec=basedec();		
			break;
		case 6:
			printf("Digite um numero Decimal:");
			scanf("%d", &dec);
			printf("\n%x",dec);
			break;
		case 7:
			printf("Digite um numero Octal:");
			scanf("%o", &oct);
			printf("\n%d",oct);				
			break;
		case 8:
			printf("Digite um numero Decimal:");
			scanf("%d", &dec);
			printf("\n%o",dec);			
			break;
		default:
			if(opcao <1 || opcao>8)
			{	printf("Opcao invalida.");}}
	return 0;
}
