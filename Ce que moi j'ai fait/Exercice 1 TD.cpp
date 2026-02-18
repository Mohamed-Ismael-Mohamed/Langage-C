#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node *suivant;
}node;

typedef node liste;

liste* ajouter_element(liste *L, int value){
	liste *p = (liste*)malloc(sizeof(liste));
	p->value = value;
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
	printf("Affichage de la liste au COMPLET\n");
	while(c != NULL){
		printf("%d->",c->value);
		c=c->suivant;
	}
	printf("NULL\n");
}

int longueur_liste(liste *L){
	if(L == NULL){
		printf("liste Vide !");
		return 0;
	}
	int cpt=0;
	liste *c = L;
	while(c != NULL){
		cpt++;
		c=c->suivant;
	}
	return cpt;
}

int somme_des_element(liste *L){
	if(L == NULL){
		printf("liste Vide !");
		return 0;
	}
	int somme=0;
	liste *c = L;
	while(c != NULL){
		somme+=c->value;
		c=c->suivant;
	}
	return somme;
}

int minimum_liste(liste *L){
	if(L != NULL){
		int min = L->value;
		liste *c = L;
		while(c != NULL){
			if(c->value < min){
				min=c->value;
			}
			c=c->suivant;
		}
		return min;
	}
}

liste* miroire(liste *L){
	if(L==NULL){
		printf("la liste est vide !");
		return L;
	}
	liste *c = L;
	liste *prev = NULL;
	while(c != NULL){
		liste *p = (liste*)malloc(sizeof(liste));
		p->value = c->value;
		p->suivant = prev;
		prev = p;
		c = c->suivant;
	}
	return prev;
}

int main(){
	liste *ma_liste = NULL;
	ma_liste = ajouter_element(ma_liste,1);
	ma_liste = ajouter_element(ma_liste,2);
	ma_liste = ajouter_element(ma_liste,3);
	ma_liste = ajouter_element(ma_liste,4);
	ma_liste = ajouter_element(ma_liste,5);
	afficher_liste(ma_liste);
	printf("Longueur : %d\n",longueur_liste(ma_liste));
	printf("Somme des Elements : %d\n",somme_des_element(ma_liste));
	ma_liste = ajouter_element(ma_liste,0);
	printf("Minimum value : %d\n",minimum_liste(ma_liste));
	liste *miroires = NULL;
	miroires = miroire(ma_liste);
	afficher_liste(miroires);
}