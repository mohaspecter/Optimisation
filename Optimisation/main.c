#include "modele.h"

int main(int argc, char* argv[])
{
	if (argc != 3) {
		printf("nombre d'argument incorrect\n");
		return 0;
	}
	printf("\n --- \t Modelisation \t ---\n\n");
	char* fichier_instance = argv[1]; /*"C:\\Users\\athan\\Desktop\\ECOLE\\2eme année\\Optimisation - LABOURDETTE - LE BERRE\\TP\\Optimisation-master\\inst41.txt"*/
	char* fichier_lp = argv[2]; /*"C:\\Users\\athan\\Desktop\\ECOLE\\2eme année\\Optimisation - LABOURDETTE - LE BERRE\\TP\\Optimisation-master\\inst.lp"*/
	createLP(fichier_instance, fichier_lp);
	system("pause");
	return 0;
}
