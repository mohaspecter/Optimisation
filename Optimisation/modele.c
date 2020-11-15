#define _CRT_SECURE_NO_WARNINGS

#include "modele.h"

void createLP(char* nomFichier){
	int M, N, i, j, minmax, cpt, cpt2, cpt3, put;

	FILE* fichier = NULL;
	fichier = fopen(nomFichier, "r");

	if (!fichier) {
		printf("Impossible d'ouvrir le fichier %s, abandon...\n", nomFichier);
		return NULL;
	}
	else
		printf("fichier instance ouvert en lecture \n");

	fscanf(fichier, "%d %d\n", &(M), &(N));
	printf("M=%d \t N=%d \n", M, N);

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
		tab[i][0] = i+1;
	}

	//cout
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
	int b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12;
	int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11;


	//si la ligne est complète on rempli le tableau avec les données de la ligne
	while (cpt > 12)
	{
		fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11, &a12);
		b1 = N - cpt;
		b2 = N - cpt + 1;
		b3 = N - cpt + 2;
		b4 = N - cpt + 3;
		b5 = N - cpt + 4;
		b6 = N - cpt + 5;
		b7 = N - cpt + 6;
		b8 = N - cpt + 7;
		b9 = N - cpt + 8;
		b10 = N - cpt + 9;
		b11 = N - cpt + 10;
		b12 = N - cpt + 11;

		tab[b1][1] = a1;
		tab[b2][1] = a2;
		tab[b3][1] = a3;
		tab[b4][1] = a4;
		tab[b5][1] = a5;
		tab[b6][1] = a6;
		tab[b7][1] = a7;
		tab[b8][1] = a8;
		tab[b9][1] = a9;
		tab[b10][1] = a10;
		tab[b11][1] = a11;
		tab[b12][1] = a12;

		cpt -= 12;
	}
	if (cpt > 0)
	{
		if (cpt == 11)
		{
			fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			b3 = N - cpt + 2;
			b4 = N - cpt + 3;
			b5 = N - cpt + 4;
			b6 = N - cpt + 5;
			b7 = N - cpt + 6;
			b8 = N - cpt + 7;
			b9 = N - cpt + 8;
			b10 = N - cpt + 9;
			b11 = N - cpt + 10;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			tab[b3][1] = a3;
			tab[b4][1] = a4;
			tab[b5][1] = a5;
			tab[b6][1] = a6;
			tab[b7][1] = a7;
			tab[b8][1] = a8;
			tab[b9][1] = a9;
			tab[b10][1] = a10;
			tab[b11][1] = a11;
			cpt -= 11;
		}
		if (cpt == 10)
		{
			fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			b3 = N - cpt + 2;
			b4 = N - cpt + 3;
			b5 = N - cpt + 4;
			b6 = N - cpt + 5;
			b7 = N - cpt + 6;
			b8 = N - cpt + 7;
			b9 = N - cpt + 8;
			b10 = N - cpt + 9;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			tab[b3][1] = a3;
			tab[b4][1] = a4;
			tab[b5][1] = a5;
			tab[b6][1] = a6;
			tab[b7][1] = a7;
			tab[b8][1] = a8;
			tab[b9][1] = a9;
			tab[b10][1] = a10;
			cpt -= 10;
		}
		if (cpt == 9)
		{
			fscanf(fichier, "%d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			b3 = N - cpt + 2;
			b4 = N - cpt + 3;
			b5 = N - cpt + 4;
			b6 = N - cpt + 5;
			b7 = N - cpt + 6;
			b8 = N - cpt + 7;
			b9 = N - cpt + 8;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			tab[b3][1] = a3;
			tab[b4][1] = a4;
			tab[b5][1] = a5;
			tab[b6][1] = a6;
			tab[b7][1] = a7;
			tab[b8][1] = a8;
			tab[b9][1] = a9;
			cpt -= 9;
		}
		if (cpt == 8)
		{
			fscanf(fichier, "%d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			b3 = N - cpt + 2;
			b4 = N - cpt + 3;
			b5 = N - cpt + 4;
			b6 = N - cpt + 5;
			b7 = N - cpt + 6;
			b8 = N - cpt + 7;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			tab[b3][1] = a3;
			tab[b4][1] = a4;
			tab[b5][1] = a5;
			tab[b6][1] = a6;
			tab[b7][1] = a7;
			tab[b8][1] = a8;
			cpt -= 8;
		}
		if (cpt == 7)
		{
			fscanf(fichier, "%d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			b3 = N - cpt + 2;
			b4 = N - cpt + 3;
			b5 = N - cpt + 4;
			b6 = N - cpt + 5;
			b7 = N - cpt + 6;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			tab[b3][1] = a3;
			tab[b4][1] = a4;
			tab[b5][1] = a5;
			tab[b6][1] = a6;
			tab[b7][1] = a7;
			cpt -= 7;
		}
		if (cpt == 6)
		{
			fscanf(fichier, "%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			b3 = N - cpt + 2;
			b4 = N - cpt + 3;
			b5 = N - cpt + 4;
			b6 = N - cpt + 5;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			tab[b3][1] = a3;
			tab[b4][1] = a4;
			tab[b5][1] = a5;
			tab[b6][1] = a6;
			cpt -= 6;
		}
		if (cpt == 5)
		{
			fscanf(fichier, "%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			b3 = N - cpt + 2;
			b4 = N - cpt + 3;
			b5 = N - cpt + 4;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			tab[b3][1] = a3;
			tab[b4][1] = a4;
			tab[b5][1] = a5;
			cpt -= 5;
		}
		if (cpt == 4)
		{
			fscanf(fichier, "%d %d %d %d", &a1, &a2, &a3, &a4);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			b3 = N - cpt + 2;
			b4 = N - cpt + 3;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			tab[b3][1] = a3;
			tab[b4][1] = a4;
			cpt -= 4;
		}
		if (cpt == 3)
		{
			fscanf(fichier, "%d %d %d", &a1, &a2, &a3);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			b3 = N - cpt + 2;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			tab[b3][1] = a3;
			cpt -= 3;
		}
		if (cpt == 2)
		{
			fscanf(fichier, "%d %d", &a1, &a2);
			b1 = N - cpt;
			b2 = N - cpt + 1;
			tab[b1][1] = a1;
			tab[b2][1] = a2;
			cpt -= 2;
		}
		if (cpt == 1)
		{
			fscanf(fichier, "%d", &a1);
			b1 = N - cpt;
			tab[b1][1] = a1;
			cpt -= 1;
		}
	}
	fputs("z: ", fichierLP);
	printf("z copie\n");
	//----------------
	for (i = 0; i < N; i++)
	{
		put = (tab[i][0]);
		if (i == (N - 1))
		{
			fprintf(fichierLP,"1 X%d\n", put);
		}

		else
		{
			fprintf(fichierLP,"1 X%d + ", put);
		}
	}

	fputs("\nSubject To\n", fichierLP);
	cpt2 = M;
	while (cpt2 > 0)
	{
		fscanf(fichier, "%d", &cpt3);
		while (cpt3 > 0)
		{
			fprintf(fichierLP, "poids: ");

			if (cpt3 >= 12)
			{
				fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11, &a12);
				b1 = tab[a1][1];
				b2 = tab[a2][1];
				b3 = tab[a3][1];
				b4 = tab[a4][1];
				b5 = tab[a5][1];
				b6 = tab[a6][1];
				b7 = tab[a7][1];
				b8 = tab[a8][1];
				b9 = tab[a9][1];
				b10 = tab[a10][1];
				b11 = tab[a11][1];
				b12 = tab[a12][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d", b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12);
				cpt3 -= 12;
			}
			if (cpt3 == 11)
			{
				fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				c3 = tab[a3][1];
				c4 = tab[a4][1];
				c5 = tab[a5][1];
				c6 = tab[a6][1];
				c7 = tab[a7][1];
				c8 = tab[a8][1];
				c9 = tab[a9][1];
				c10 = tab[a10][1];
				c11 = tab[a11][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11);
				cpt3 -= 11;
			}

			if (cpt3 == 10)
			{
				fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				c3 = tab[a3][1];
				c4 = tab[a4][1];
				c5 = tab[a5][1];
				c6 = tab[a6][1];
				c7 = tab[a7][1];
				c8 = tab[a8][1];
				c9 = tab[a9][1];
				c10 = tab[a10][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10);
				cpt3 -= 10;
			}

			if (cpt3 == 9)
			{
				fscanf(fichier, "%d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				c3 = tab[a3][1];
				c4 = tab[a4][1];
				c5 = tab[a5][1];
				c6 = tab[a6][1];
				c7 = tab[a7][1];
				c8 = tab[a8][1];
				c9 = tab[a9][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d", c1, c2, c3, c4, c5, c6, c7, c8, c9);
				cpt3 -= 9;
			}

			if (cpt3 == 8)
			{
				fscanf(fichier, "%d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				c3 = tab[a3][1];
				c4 = tab[a4][1];
				c5 = tab[a5][1];
				c6 = tab[a6][1];
				c7 = tab[a7][1];
				c8 = tab[a8][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d", c1, c2, c3, c4, c5, c6, c7, c8);
				cpt3 -= 8;
			}

			if (cpt3 == 7)
			{
				fscanf(fichier, "%d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				c3 = tab[a3][1];
				c4 = tab[a4][1];
				c5 = tab[a5][1];
				c6 = tab[a6][1];
				c7 = tab[a7][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d", c1, c2, c3, c4, c5, c6, c7);
				cpt3 -= 7;
			}
			if (cpt3 == 6)
			{
				fscanf(fichier, "%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				c3 = tab[a3][1];
				c4 = tab[a4][1];
				c5 = tab[a5][1];
				c6 = tab[a6][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d", c1, c2, c3, c4, c5, c6);
				cpt3 -= 6;
			}
			if (cpt3 == 5)
			{
				fscanf(fichier, "%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				c3 = tab[a3][1];
				c4 = tab[a4][1];
				c5 = tab[a5][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d + 1 X%d + 1 X%d", c1, c2, c3, c4, c5);
				cpt3 -= 5;
			}

			if (cpt3 == 4)
			{
				fscanf(fichier, "%d %d %d %d", &a1, &a2, &a3, &a4);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				c3 = tab[a3][1];
				c4 = tab[a4][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d + 1 X%d", c1, c2, c3, c4);
				cpt3 -= 4;
			}
			if (cpt3 == 3)
			{
				fscanf(fichier, "%d %d %d", &a1, &a2, &a3);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				c3 = tab[a3][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d + 1 X%d", c1, c2, c3);
				cpt3 -= 3;
			}
			if (cpt3 == 2)
			{
				fscanf(fichier, "%d %d", &a1, &a2);
				c1 = tab[a1][1];
				c2 = tab[a2][1];
				fprintf(fichierLP, "+ 1 X%d + 1 X%d", c1, c2);
				cpt3 -= 2;
			}
			if (cpt3 == 1)
			{
				fscanf(fichier, "%d", &a1);
				c1 = tab[a1][1];
				fprintf(fichierLP, "+ 1 X%d", c1);
				cpt3 -= 1;
			}
		}
		fprintf(fichierLP, "\n");
		cpt2--;
	}

	fputs("\nBinaries\n", fichierLP);

	for (i = 0; i < N; i++)
	{
		put = (tab[i][0]);
		fprintf(fichierLP, "X%d\n", put);
	}
	printf("subject to copié\n");

	/*printf("--------------test tableau------------------------\n");
	for (i = 0; i < N; i++)
		printf("%d\t%d\n", (tab[i][0]), (tab[i][1]));*/

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

