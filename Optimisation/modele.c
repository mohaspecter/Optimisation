#include "modele.h"

void createLP(char* nomFichier){
	int M, N, i;

	FILE* fichier = NULL;
	fichier = fopen(nomFichier, "r");

	if (!fichier) {
		printf("Impossible d'ouvrir le fichier %s, abandon...\n", nomFichier);
		return NULL;
	}
	else
		printf("fichier ouvert \n");

	fscanf(fichier, "%d %d\n", &(M), &(N));
	printf("M=%d \t N=%d \n", &(M), &(N));

	int** tab = (int**)malloc(N * sizeof(int*));

	for (i = 0; i < N; i++)
	{
		tab[i] = (int**)malloc(2 * sizeof(int*));
	}

	FILE* fichierLP = NULL;
	char* nomFichierLP = "inst.lp";
	fichier = fopen(nomFichierLP, "r");

	system("pause");

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

