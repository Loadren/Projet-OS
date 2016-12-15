#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "/home/cesi/Desktop/PROJET/pbm.h"
#include <time.h>
#define TAILLE_MAX 100

int main(int argc, char *argv[])
{	
	int choixecran; // Choix de l'écran (fixe, dynamique...)
	int choixdefini=0;
	char* NomEcran;
	int i;
	char* pointeur;
	char chaine[TAILLE_MAX] = "";
	FILE* Historique = NULL;
	char ligne; // On initialise le tableau de caractère et on le remplit d'espace
	int choixstat;
	
	Historique=fopen("Historique.txt","r+");

	if (argv[1]!=NULL)
	{
		if (strcmp(argv[1],"-stat")==0)
		{
			  printf("1 : Statistique\n2 : Historique\n"); //On affiche le menu
			  scanf("%d", &choixstat); //On prend le choix de l'utilisateur

			  if (choixstat==1)
			  {
				printf("Pas de statistique\n");
			  }
			  if (choixstat==2)
			  {
				while(fgets(chaine, TAILLE_MAX, Historique) !=NULL)
				{
					printf("%s",chaine);
				}
			  }
			fclose(Historique); 
			return 0;
		}
	}
	
	srand(time(NULL));
	choixecran=rand()%(3-1)+1;
	
	// TEST
	
	time_t temps;
	struct tm date;
	time(&temps);
	date = *localtime(&temps);
	
	char* message;
	int ann = date.tm_year + 1900;
	int mois =  date.tm_mon + 1;
	int jour =  date.tm_mday;
	int heur = date.tm_hour;
	int minute = date.tm_min;
	int seconde =  date.tm_sec;

	FILE* fichier = NULL;
	fichier = fopen("Historique.txt","r+"); 

	if (fichier !=NULL)
	{
		if(choixecran==1)
			{
				NomEcran="fixe";
			}
		else
			{
				NomEcran="dynamique";
			}
		fseek(fichier,0,SEEK_END);
		fprintf(fichier,"L'écran %s a été lancé le %d/%d/%d à %d:%d:%d.\n\0",NomEcran, jour, mois, ann, heur, minute, seconde);
		fclose(fichier);
	}
	
	// TEST
	
	FILE* stdin;
	char a=NULL; //on déclare une variable char
	
	if(choixecran==1)
	{
		imagefixe(choixecran, choixdefini);
	}
	
	if(choixecran==2)
	{
		while(1)
		{
			imagedynamique();
			sleep(1);
		}
	}
	
    a = getch(); //grâce à getch l'ordinateur attend que l'utilisateur appuie sur une touche
				 //sans avoir à appuyer sur entrée
    
	if (a=!NULL && choixecran==1)
	{
		return 0;
	}
}
