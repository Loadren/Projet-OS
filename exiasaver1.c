#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "/home/cesi/Desktop/PROJET/pbm.h"
#include <time.h>

int main(int argc, char *argv[])
{	
	int choixecran=1; // Choix de l'écran (fixe, dynamique...)
	int choixdefiniexia1=0; // Un Exiasaver spécifique (1) a été lancé ou pas

	if (argv[1]!=NULL)
	{
		if (strcmp(argv[1],"ex1.pbm")==0)
		{
			choixdefiniexia1=1;
		}
		if (strcmp(argv[1],"ex2.pbm")==0)
		{
			choixdefiniexia1=2;
		}
		if (strcmp(argv[1],"ex3.pbm")==0)
		{
			choixdefiniexia1=3;
		}
		if (strcmp(argv[1],"ex4.pbm")==0)
		{
			choixdefiniexia1=4;
		}
		if (strcmp(argv[1],"ex5.pbm")==0)
		{
			choixdefiniexia1=5;
		}
		
	}

	FILE* stdin;
	char a=NULL; //on déclare une variable char
	
	imagefixe(choixecran, choixdefiniexia1);

    a = getch(); //grâce à getch l'ordinateur attend que l'utilisateur appuie sur une touche
				 //sans avoir à appuyer sur entrée

		return 0;

}
