#include "modele.h"

int main(int argc, char* argv[])
{
	printf("--- \t Modelisation \t ---");
	char* path = "D:\\VS\\mohaspecter\\Optimisation\\Optimisation\\inst41.txt";
	createLP(path);
	system("pause");
	return 0;
}
