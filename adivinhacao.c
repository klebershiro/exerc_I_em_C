#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	
	//imprime a saudação abaixo
	printf("**********************************\n");
	printf("*Bem-vindo ao jogo da Adivinhacao*\n");
	printf("**********************************\n");

	//declaração das variáveis conforme abaixo
	int segundos = time(0);
	srand(segundos);
	int numero_grande = rand();

	int numero_secreto = numero_grande % 100;

	double pontos = 1000;
	
	int chute;

	int acertou = 0;

	int nivel;
	printf("Qual o nivel de dificuldade?\n");
	printf("(1)Facil (2)Medio (3)Dificil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	int numero_tentativas;
	switch (nivel){
		case 1: 
			numero_tentativas = 20;
			break;
		case 2: 
			numero_tentativas = 15;
			break;
		default:
			numero_tentativas = 6;
			break;
	}
	
	//pode ser declarada como abaixo
	int idade;
	idade = 20;

	int tentativas = 1;
	
	// pode ser com while como: while (1) {
	for (int i = 1; i <= numero_tentativas; i++){
		printf("Tentativa %d\n", tentativas);

		printf ("Digite um valor: ");
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);

		if (chute < 0) {
			printf("Seu chute nao pode ser negativo\n\n");

			//faz continuar o algoritmo, nao indo para baixo e indo de novo para o comeco do for. É igual ao next do Ruby
			//é um break menos bravo
			continue;
		}

		acertou = (chute == numero_secreto);
		int maior = chute > numero_secreto;

		printf ("Acertou %d\n\n", acertou);

		if (acertou) {
			break;
		}
		else if (maior) {
			printf ("O numero secreto eh menor!\n\n");
		} else {
			printf ("O numero secreto eh maior!\n\n");
		}
		tentativas = tentativas + 1;

		double pontos_perdidos = abs(chute -  numero_secreto)/(double)2;
		pontos = pontos - pontos_perdidos;
	}

	printf("\n\nFim de jogo\n");
	if (acertou) {
		printf("Voce ganhou!\n");
		printf("Voce acertou em %d tentativas.\n", tentativas);
		printf("Total de pontos %.1f \n\n", pontos);
	} else{
		printf("Voce perdeu. Tente de novo.\n\n");
	}
}