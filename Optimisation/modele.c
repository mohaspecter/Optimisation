#include "modele.h"

void createLP(char* nomFichier){
	int M, N, i, minmax, cpt;

	FILE* fichier = NULL;
	fichier = fopen(nomFichier, "r");

	if (!fichier) {
		printf("Impossible d'ouvrir le fichier %s, abandon...\n", nomFichier);
		return NULL;
	}
	else
		printf("fichier instance ouvert en lecture \n");

	fscanf(fichier, "%d %d\n", &(M), &(N));
	printf("M=%d \t N=%d \n", (M), (N));

	int** tab = (int**)malloc(N * sizeof(int*));

	for (i = 0; i < N; i++)
	{
		tab[i] = (int**)malloc(2 * sizeof(int*));
	}

	FILE* fichierLP = NULL;
	char* nomFichierLP = "D:\\VS\\mohaspecter\\Optimisation\\Optimisation\\inst.lp";
	fichierLP = fopen(nomFichierLP, "w+");

	if (!fichierLP) {
		printf("Impossible d'ouvrir le fichier %s, abandon...\n", nomFichierLP);
		return NULL;
	}
	else
		printf("fichier LP ouvert en ecriture \n");

	//si 0 on minimise si 1 maximum
	minmax = 0;
	if (minmax == 0)
	{
		fputs("Minimize\n", fichierLP);
	}

	if (minmax == 1)
	{
		fputs("Maximize\n", fichierLP);
	} 

	cpt = N;

	//on rempli le tableau avec une valeur et son cout 
	//valeurs
	for (i = 0; i < N; i++)
	{
		tab[i][0] = i;
	}

	//cout
	while (cpt != 0)
	{
		cpt--;
	}

	fclose(fichier);
	fclose(fichierLP);
}

/*
Modele* chargerModele(char* nomFichier) {
	FILE* fichier = NULL;
	fichier = fopen(nomFichier, "r");

	if (!fichier) {
		printf("Impossible d'ouvrir le fichier %s, abandon...\n", nomFichier);
		return NULL;
	}

	Modele* modele = (Modele*)calloc(1, sizeof(Modele));
	if (!modele) {
		printf("Impossible d'allouer de modele, abandon...\n");
		fclose(fichier);
	}


	fscanf(fichier, "%d %d\n", &(modele->M), &(modele->N);
	int M = modele->M;
	int N = modele->N;

	char buffer[4096];
	char* tok = strtok(buffer, " ");

	modele->z = (float*)calloc(modele->N, sizeof(float));
	modele->type = 1; //minimiser

	if (modele->type)
		printf("Minimiser z = ");

	for (int i = 0; i < N; i++);
	{
		
	}
}

void afficherModele(Modele* modele)		//affiche le modèle tel que vu en cours
{
	return;
}

void detruireModele(Modele* modele) //nettoie la mémoire
{
	return;
}
*/

