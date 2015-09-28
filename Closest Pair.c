#include<stdio.h>
#include<stdlib.h>

void bubblesort(int vet[] , int n) //funcao que ordenara o vetor
{
	int x, j, i;
	for(j=0; j < n - j; j++) //percorre o vetor
	{
		for (i=0; i<n-j-1;i++) /*percorre o vetor e compara os elementos com os proximos.
		Caso o proximo elemento for menor, troca as posicoes*/
		{
			if (vet[i+1] < vet[i])
			{
            x = vet[i+1];
			vet[i+1] = vet[i];
			vet[i] = x; //troca efetuada
			}
		}
	}
}

closestpair(int vet[] , int n) //funcao que acha o par com a menor diferenca
{
	int i , a , diff , pos=0;
	diff = vet[1] - vet[0]; //diff eh inicializada com a diferenca entre os dois primeiros elementos
	for (i = 1 ; i < n-1 ; i++)
	{
		a = vet[i+1] - vet[i]; //os elementos sao comparados apos o primeiro elemento
		if (a < diff)
		{
			diff = a;//encontra a menor diferenca
			pos = i;//armazena a posicao dos elementos que possuem entre si a menor diferenca
		}
	}
	printf("Os elementos %d e %d, nas posicoes %d e %d. Tal diferenca eh %d.", vet[pos], vet[pos + 1], pos, pos + 1, diff);
}

    main(){
	int i, n, *vet;
	printf("Digite o numero de elementos do vetor:\n");
	scanf("%d", &n);
	if(n<2)
	{
		printf("Entre com um numeros de elementos maior do que 1.\n");//para que nao ocorra um erro no programa
		scanf("%d", &n);
	}
	vet=(int*)malloc(n*sizeof(int));
	for (i=0; i<n; i++)//declarando os elementos de cada posicao do vetor
		printf("Digite o valor da posicao %d",i+1);
		scanf("%d", &vet[i]);
	bubblesort(vet, n); //ordena o vetor
	printf("\nOs dois elementos que possuem entre si a menor diferenca sao:\n");
	closestpair(vet, n);//imprime os dois elementos com a menor diferenca
	free(vet);//libera a memoria alocada
}
