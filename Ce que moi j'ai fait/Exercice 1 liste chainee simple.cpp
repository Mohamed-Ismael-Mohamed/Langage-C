#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct candidat{
	int numero;
	char nom[70];
	char prenom[70];
	float tab[3];
	float moyenne;
	struct candidat *suivant;
}candidat;

typedef candidat liste;

liste* ajouter_element(liste *L, candidat x){
	liste *p = (liste*)malloc(sizeof(liste));
	p->numero = x.numero;
	strcpy(p->nom, x.nom);
	strcpy(p->prenom, x.prenom);
	p->tab[0] = x.tab[0];
	p->tab[1] = x.tab[1];
	p->tab[2] = x.tab[2];
	p->moyenne = x.moyenne;
	p->suivant = NULL;
	if(L == NULL){
		L=p;
		return L;
	}
	else{
		liste *c = L;
		while(c->suivant !=NULL){
			c = c->suivant;
		}
		c->suivant = p;
		return L;
	}
}

void afficher_liste(liste *L){
	if(L == NULL){
		printf("liste Vide !");
		return;
	}
	liste *c = L;
	int i=0;
	printf("Affichage de la liste au COMPLET\n");
	while(c != NULL){
		i++;
		printf("Candidat %d\n",i);
		printf("Numero : %d\n",c->numero);
		printf("Nom : %s\n",c->nom);
		printf("Prenom : %s\n",c->prenom);
		printf("Les Trois notes : %.2f\t %.2f\t %.2f\n",c->tab[0],c->tab[1],c->tab[2]);
		printf("Moyenne : %.2f\n",c->moyenne);
		printf("\n");
		c=c->suivant;
	}
}

void classement(liste *L){
	liste *c = L;
	int cpt=0;
	while(c != NULL){
		cpt++;
		c = c->suivant;
	}
	liste *tab[cpt];
	liste *a=L;
	int i,j;
	for(i=0;i<cpt;i++){
		tab[i] = a;
		a = a->suivant;
	}
	for(i=0;i<cpt-1;i++){
		for(j=i+1;j<cpt;j++){
			if(tab[j]->moyenne > tab[i]->moyenne){
				liste *temp = tab[i];
				tab[i] = tab[j];
				tab[j]=temp;
			}
		}
	}
	printf("Classement de tous les Candidat\n");
	int h;
	for(h=0;h<cpt;h++){
		printf("Candidat %d\n",h+1);
		printf("Numero : %d\n",tab[h]->numero);
		printf("Nom : %s\n",tab[h]->nom);
		printf("Prenom : %s\n",tab[h]->prenom);
		printf("Les Trois notes : %.2f\t %.2f\t %.2f\n",tab[h]->tab[0],tab[h]->tab[1],tab[h]->tab[2]);
		printf("Moyenne : %.2f\n",tab[h]->moyenne);
		printf("\n");
	}
}

int main(){
	liste *ma_liste = NULL;
	candidat e1 = {1,"Mohamed","Ismael",{10,11,12},11};
	candidat e2 = {2,"Ahmed","Ismael",{13,14,15},14};
	candidat e3 = {3,"Mohamed","Abdi",{16,17,18},17};
	candidat e4 = {4,"LASSA","HASSAN",{9,8,7},8};
	candidat e5 = {5,"Khaled","Aden",{5,6,4},6};
	ma_liste = ajouter_element(ma_liste,e1);
	ma_liste = ajouter_element(ma_liste,e2);
	ma_liste = ajouter_element(ma_liste,e3);
	ma_liste = ajouter_element(ma_liste,e4);
	ma_liste = ajouter_element(ma_liste,e5);
	afficher_liste(ma_liste);
	classement(ma_liste);
}
