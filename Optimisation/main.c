#include "modele.h"

int main(int argc, char* argv[])
{
	printf("\n --- \t Modelisation \t ---\n");
	char* path = "D:\\VS\\mohaspecter\\Optimisation\\Optimisation\\inst41.txt";
	createLP(path);
	system("pause");
	return 0;
}
