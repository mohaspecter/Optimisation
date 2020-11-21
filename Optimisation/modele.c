#define _CRT_SECURE_NO_WARNINGS

#include "modele.h"

void createLP(char* nomFichier_inst, char* nomFichier_lp) {
	int M, N;

	FILE* fichier = NULL;
	fichier = fopen(nomFichier_inst, "r");

	if (!fichier) {
		printf("Impossible d'ouvrir le fichier %s, abandon...\n", fichier);
		return NULL;
	}
	else
		printf("fichier instance ouvert en lecture \n");

	fscanf(fichier, "%d %d\n", &(M), &(N));
	printf("M=%d \t N=%d \n", M, N);


	FILE* fichierLP = NULL;
	char* nomFichierLP = nomFichier_lp;
	fichierLP = fopen(nomFichierLP, "w+");

	if (!fichierLP) {
		printf("Impossible d'ouvrir le fichier %s, abandon...\n", nomFichierLP);
		return NULL;
	}
	else
		printf("fichier LP ouvert en ecriture \n");

	//si 0 on minimise si 1 maximum
	int minmax = 0;
	if (minmax == 0)
	{
		fputs("Minimize\n", fichierLP);
	}
	if (minmax == 1)
	{
		fputs("Maximize\n", fichierLP);
	}

	fputs("z: ", fichierLP);
	printf("z copie\n");

	//tab qui va contenir les N couts 
	int* tab_cout_capteur = (int*)malloc(N * sizeof(int));
	//on récupère tous les couts du fichier 
	for (int x = 0; x < N; x++) {
		fscanf(fichier, "%d", &tab_cout_capteur[x]);
	}

	//variable qui correspon au numéro binaire des variable 
	int valeur_x = 1;
	//On écrit les N-1 couts du tableau dans le fichier lp 
	for (int x = 0; x < N - 1; x++) {
		fprintf(fichierLP, "%d x%d + ", tab_cout_capteur[x], valeur_x);
		valeur_x++;
	}
	//On ecrit le dernier cout du tableau
	fprintf(fichierLP, "%d x%d", tab_cout_capteur[N - 1], valeur_x);

	fputs("\nSubject To\n", fichierLP);
	//
	for (int i = 0; i < M; i++) {
		//Variable qui contient le nombre de capteur lié a une cible
		int nbr_capteur_pour_cible;
		//On récupère la valeur 
		fscanf(fichier, "%d", &nbr_capteur_pour_cible);

		//tableau qui va contenir la liste des capteurs lié à la cible
		int* liste_capteur_pour_cible = (int*)malloc(nbr_capteur_pour_cible * sizeof(int));
		//on récupère tous les numéros des capteurs 
		for (int x = 0; x < nbr_capteur_pour_cible; x++) {
			fscanf(fichier, "%d", &liste_capteur_pour_cible[x]);
		}
		//on écrit tous les numéros des capteurs lié à la cible
		for (int x = 0; x < nbr_capteur_pour_cible - 1; x++) {
			fprintf(fichierLP, "x%d + ", liste_capteur_pour_cible[x]);
		}
		fprintf(fichierLP, "x%d >=1\n", liste_capteur_pour_cible[nbr_capteur_pour_cible - 1]);

	}

	fputs("Binaries\n", fichierLP);
	//On écrit les N variables binaires
	for (int i = 1; i <= N; i++)
	{
		fprintf(fichierLP, "x%d\n", i);
	}
	printf("subject to copié\n");

	fclose(fichier);
	fclose(fichierLP);
}

