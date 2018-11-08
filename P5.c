/* P5.c */
/* Antonio Augusto Ananias Oliveira */
/* 11811EEL013 */

#include <stdio.h>

typedef
	unsigned long long int
	Bytes8;
	
typedef
	struct LCG { Bytes8 a, c, m, rand_max, atual; }
	LCG;

void semente(LCG * r, Bytes8 seed) {
	// constantes do POSIX [de]rand48, glibc [de]rand48[_r]
	// ULL transforma a constante ’int’ em ’unsigned long long int’
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r){
	r->atual = (r->a * r->atual + r->c) % r->m;
	return r->atual;
 }
 
double lcg_rand_01(LCG * r){
	return ((double) lcg_rand(r))/(r->rand_max);
 }
 
void gera_numeros(float * vetor, int tam, float min, float max, LCG * r) {
	int i;
	for(i = 0; i < tam; i++)
		vetor[i] = (max-min)*lcg_rand_01(r) + min;
}
		
float soma(float *end_inicio, float *end_fim){
 	while(end_fim > end_inicio)
 		return *end_fim + soma(end_inicio, end_fim - 1);
	if(end_fim == end_inicio)
		return *end_inicio;
}
 
float produto(float *end_inicio, float *end_fim) {
	while(end_fim > end_inicio)
 		return *end_fim * produto(end_inicio, end_fim - 1);
	if(end_fim == end_inicio)
		return *end_inicio;
 }		
int main()
{
	LCG random;
    semente(&random,123456);
    float vetor[50]; int x; float *end_fim, *end_inicio;
    printf("\nEscolha uma opcao, por favor:  1)Somatorio  2)Produtorio\n");
    scanf("%d", &x);
    getchar();
    gera_numeros(vetor, 50, 0.5, 1.5, &random);
    end_inicio=&vetor[0];
    end_fim=&vetor[49];
    if(x == 1)
    	printf("\nSomatorio de 50 numeros aleatorios = %f ",soma(end_inicio,end_fim));
	if(x == 2)
    	printf("\nProdutorio de 50 numeros aleatorios = %f ",produto(end_inicio,end_fim));
    if(x!=1 && x!=2)	
    	printf("ERRO 404");
    return 0;
}
