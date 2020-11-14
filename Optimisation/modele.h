#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MODELE_H
#define MODELE_H

/*
typedef struct {
	char type; //0 si <=, 1 si >=
	float* coeff; //coefficients des variables dans la contrainte, dimension N
	float constante; //partie droite de l'in�quation
} Contrainte;

typedef struct {
	char type; //0 si maximisation, 1 si minimisation
	int N; //nombre de variables
	int M; //nombre de contraintes
	float* z; //coefficients des variables dans l'objectif, dimension N
	Contrainte* contraintes; //contraintes du mod�le, dimension M
} Modele;

Modele* chargerModele(char* nomFichier); //charge le mod�le depuis le fichier sp�cifi�, retourne NULL si impossible
void afficherModele(Modele* modele); //affiche le mod�le tel que vu en cours
void detruireModele(Modele* modele); //nettoie la m�moire
*/

void createLP(char* path);


#endif
