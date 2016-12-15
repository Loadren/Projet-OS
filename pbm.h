#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "/home/cesi/Desktop/PROJET/structure.h"
#include <time.h>
#include <sys/ioctl.h>
#include <unistd.h>   //_getch
#include <termios.h>  //_getch

	struct image tableau;

void affichage(	char* NomDuFichier, int j, int i, int k, char lettre, char* pointeur, char* parcours, FILE* fp)
{
	fp=fopen(NomDuFichier,"r"); // On ouvre le PBM
	
	fgets(parcours,BUFSIZ,fp);
	fgets(parcours,BUFSIZ,fp);
	
	tableau.largeur=strtol(strtok(parcours," "), &pointeur, 0);
	tableau.hauteur=strtol(strtok(NULL," "), &pointeur, 0);
	
	tableau.tab = malloc(tableau.hauteur * sizeof(*tableau.tab));

	for(i=0 ; i < tableau.hauteur ; i++){
		tableau.tab[i] = malloc(tableau.largeur * sizeof(**tableau.tab)); 
	}

	i=0;
	
	lettre=fgetc(fp);
	
	while(lettre!=EOF)
	{
		if(lettre==' ')
		{
			lettre=fgetc(fp);
		}
		if(lettre=='\r')
		{
			lettre=fgetc(fp);
		}
		if(lettre != ' ' && lettre!='\n')
		{
			k=lettre-48;
			tableau.tab[j][i]=k;
			i++;
		}
		if(lettre=='\n')
		{		
			j++;
			i=0;
		}
		lettre=fgetc(fp);
	}
}

void imagefixe(int choixecran, int choixdefini)
{
	char* NomDuFichier;
	int j=0; // compteur 1
	int i=0; // compteur 2
	int k=0; // 0 ou 1 dans le programme
	char lettre;
	char* pointeur;
	char* parcours;
	FILE* fp;
	int x;
	parcours=(char*)malloc((BUFSIZ)*sizeof(char));
	
	srand(time(NULL));
	choixecran=rand()%(6-1)+1;
	
	if(choixdefini!=0)
	{
		choixecran=choixdefini;
	}
	
	if(choixecran==1)
	{
		NomDuFichier=strcat(getenv("EXIASAVER1_PBM"),"ex1.pbm");
	}
	if(choixecran==2)
	{
		NomDuFichier=strcat(getenv("EXIASAVER1_PBM"),"ex2.pbm");
	}
	if(choixecran==3)
	{
		NomDuFichier=strcat(getenv("EXIASAVER1_PBM"),"ex3.pbm");
	}
	if(choixecran==4)
	{
		NomDuFichier=strcat(getenv("EXIASAVER1_PBM"),"ex4.pbm");
	}
	if(choixecran==5)
	{
		NomDuFichier=strcat(getenv("EXIASAVER1_PBM"),"ex5.pbm");
	}
		
	affichage(NomDuFichier, j, i, k, lettre, pointeur, parcours, fp);
	
	j=0;
	i=0;

	system("clear");

	struct winsize w;  
    
	ioctl(0, TIOCGWINSZ, &w);

	w.ws_row=(w.ws_row-tableau.hauteur)/2;
	w.ws_col=(w.ws_col-tableau.largeur)/2;
	
	for(i;i<w.ws_row;i++)
    {
		printf("\n");
	}
	i=0;
	k=0;
	
	for(j;j<tableau.hauteur;j++)
	{
		for(k;k<w.ws_col;k++)
			{
				printf(" ");
			}
			k=0;
		for(i;i<tableau.largeur;i++)
		{
			if(tableau.tab[j][i]==0)
			{
				printf(" ");
			}
			if(tableau.tab[j][i]==1)
			{
				printf("\u2588");
			}
		}
		printf("\n");
		i=0;
	}
}

void imagedynamique()
{
	char* NomDuFichier;
	int j=0; // compteur 1
	int i=0; // compteur 2
	int l=8; // compteur 3
	int m=0; // compteur 4
	int k=0; // 0 ou 1 dans le programme
	char lettre;
	char* pointeur;
	char* parcours;
	FILE* fp;
	time_t temps;
	struct tm date;
	int x;
	char heure[7];
	struct winsize w;  

	time(&temps);
	date=*localtime(&temps);

	heure[0] = (date.tm_hour /10) + 48;
	heure[1] = (date.tm_hour %10) + 48;
	heure[2] = ':';
	heure[3] = (date.tm_min /10) + 48;
	heure[4] = (date.tm_min %10) + 48;
	heure[5] = ':';
	heure[6] = (date.tm_sec /10) + 48;
	heure[7] = (date.tm_sec %10) + 48;
	
	parcours=(char*)malloc((BUFSIZ)*sizeof(char));
	
	NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/0.pbm";

    fp=fopen(NomDuFichier,"r"); // On ouvre le PBM
	
	fgets(parcours,BUFSIZ,fp);
	fgets(parcours,BUFSIZ,fp);
	
	tableau.largeur=(strtol(strtok(parcours," "), &pointeur, 0))*11;
	tableau.hauteur=strtol(strtok(NULL," "), &pointeur, 0);
	
	tableau.tab = malloc(tableau.hauteur * sizeof(*tableau.tab));

	for(i=0 ; i < tableau.hauteur ; i++)
	{
		tableau.tab[i] = malloc(tableau.largeur * sizeof(**tableau.tab)); 
	}
	i=0;
	
	for(j;j<tableau.hauteur;j++)
		{
			for(i;i<tableau.largeur;i++)
			{
				tableau.tab[j][i]=0;
			}
			printf("\n");
			i=0;
		} 
	
	fclose(fp);

	i=0;
	j=0;


	for(l=0;l<8;l++)
	{
		if(heure[l]=='0')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/0.pbm";
		}
		if(heure[l]=='1')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/1.pbm";
		}
		if(heure[l]=='2')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/2.pbm";
		}
		if(heure[l]=='3')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/3.pbm";
		}
		if(heure[l]=='4')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/4.pbm";
		}
		if(heure[l]=='5')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/5.pbm";
		}
		if(heure[l]=='6')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/6.pbm";
		}
		if(heure[l]=='7')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/7.pbm";
		}
		if(heure[l]=='8')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/8.pbm";
		}
		if(heure[l]=='9')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/9.pbm";
		}
		if(heure[l]==':')
		{
			NomDuFichier="/home/cesi/Desktop/PROJET/PBM2/deuxpoints.pbm";
		}
		
		fp=fopen(NomDuFichier,"r"); // On ouvre le PBM
	
		fgets(parcours,BUFSIZ,fp);
		fgets(parcours,BUFSIZ,fp);
		lettre=fgetc(fp);
		while(lettre!=EOF)
		{
			if(lettre==' ')
			{
				lettre=fgetc(fp);
			}
			if(lettre=='\r')
			{
				lettre=fgetc(fp);
			}
			if(lettre != ' ' && lettre!='\n')
			{
				k=lettre-48;
				tableau.tab[j][i]=k;
				i++;
			}
			if(lettre=='\n')
			{		
				j++;
				x=i+1;
				i=m;
			}
			lettre=fgetc(fp);
		}
		i=x;
		m=m+4;
		j=0;
		fclose(fp);
	}

	j=0;
	i=0;
	x=0;

	system("clear");
    
	ioctl(0, TIOCGWINSZ, &w);

	w.ws_row=((w.ws_row-tableau.hauteur)/2);
	w.ws_col=((w.ws_col-tableau.largeur)/2);
	
	for(i;i<w.ws_row;i++)
    {
		printf("\n");
	}
	i=0;
	k=0;
	
	for(j;j<tableau.hauteur;j++)
	{
		for(k;k<w.ws_col;k++)
			{
				printf(" ");
			}
			k=0;
		for(i;i<tableau.largeur;i++)
		{
			if(tableau.tab[j][i]==0)
			{
				printf(" ");
			}
			if(tableau.tab[j][i]==1)
			{
				printf("\u2588");
			}
		}
		printf("\n");
		i=0;
	} 
	ioctl(0, TIOCGWINSZ, &w);
	
	w.ws_row=((w.ws_row-tableau.hauteur)/2);
	w.ws_col=((w.ws_col-tableau.largeur)/2);
}

void imagefixee()
{
	char* NomDuFichier;
	int choixecran;
	int j=0; // compteur 1
	int i=0; // compteur 2
	int k=0; // 0 ou 1 dans le programme
	char lettre;
	char* pointeur;
	char* parcours;
	FILE* fp;
	parcours=(char*)malloc((BUFSIZ)*sizeof(char));
	
	srand(time(NULL));
	choixecran=rand()%(6-1)+1;
	
	if(choixecran==1)
	{
		NomDuFichier="PBM/ex2.pbm";
	}
	if(choixecran==2)
	{
		NomDuFichier="PBM/ex3.pbm";
	}
	if(choixecran==3)
	{
		NomDuFichier="PBM/doublepee.pbm";
	}
	if(choixecran==4)
	{
		NomDuFichier="PBM/logo.pbm";
	}
	if(choixecran==5)
	{
		NomDuFichier="PBM/coeur.pbm";
	}
		
	fp=fopen(NomDuFichier,"r"); // On ouvre le PBM
	
	fgets(parcours,BUFSIZ,fp);
	fgets(parcours,BUFSIZ,fp);
	
	tableau.largeur=strtol(strtok(parcours," "), &pointeur, 0);
	tableau.hauteur=strtol(strtok(NULL," "), &pointeur, 0);
	
	tableau.tab = malloc(tableau.hauteur * sizeof(*tableau.tab));

	for(i=0 ; i < tableau.hauteur ; i++){
		tableau.tab[i] = malloc(tableau.largeur * sizeof(**tableau.tab)); 
	}

	i=0;
	
	lettre=fgetc(fp);

	while(lettre!=EOF)
	{
		if(lettre==' ')
		{
			lettre=fgetc(fp);
		}
		if(lettre=='\r')
		{
			lettre=fgetc(fp);
		}
		if(lettre != ' ' && lettre!='\n')
		{
			k=lettre-48;
			tableau.tab[j][i]=k;
			i++;
		}
		if(lettre=='\n')
		{		
			j++;
			i=0;
		}
		lettre=fgetc(fp);
	}	
	j=0;
	i=0;

	system("clear");

	struct winsize w;  
    
	ioctl(0, TIOCGWINSZ, &w);

	w.ws_row=(w.ws_row-tableau.hauteur)/2;
	w.ws_col=(w.ws_col-tableau.largeur)/2;
	
	for(i;i<w.ws_row;i++)
    {
		printf("\n");
	}
	i=0;
	k=0;
	
	for(j;j<tableau.hauteur;j++)
	{
		for(k;k<w.ws_col;k++)
			{
				printf(" ");
			}
			k=0;
		for(i;i<tableau.largeur;i++)
		{
			if(tableau.tab[j][i]==0)
			{
				printf(" ");
			}
			if(tableau.tab[j][i]==1)
			{
				printf("\u2588");
			}
		}
		printf("\n");
		i=0;
	}

}

char getch()
{
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
 }
