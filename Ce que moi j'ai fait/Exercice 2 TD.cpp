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

liste* inserer_pos(int pos, int x, liste *L){
	if(L == NULL){
		printf("La liste est vide\n");
		return L;
	}
	liste *c = L;
	int cpt=0;
	while(c != NULL){
		cpt++;
		c = c->suivant;
	}
	liste *p = (liste*)malloc(sizeof(liste));
	p->value = x;
	if(pos == 0){
		p->suivant = L;
		L=p;
	}
	else{
		if(pos == cpt-1){
			liste *prev = NULL;
			liste *m = L;
			while(m->suivant != NULL){
				prev = m;
				m = m->suivant;
			}
			prev->suivant = p;
			p->suivant = m;
		}
		else{
			int i;
			liste *prev = NULL;
			liste *m = L;
			for(i=0;i<pos;i++){
				prev = m;
				m = m->suivant;
			}
			prev->suivant = p;
			p->suivant = m;
		}
	}
	return L;
}

liste* supprimer_pos(liste *L, int pos){
	if(L == NULL){
		printf("La liste est vide\n");
		return L;
	}
	liste *c = L;
	int cpt=0;
	while(c != NULL){
		cpt++;
		c = c->suivant;
	}
	if(pos == 0){
		liste *temp = L;
		L = L->suivant;
		free(temp);
	}
	else{
		if(pos == cpt-1){
			liste *prev = NULL;
			liste *courant = L;
			while(courant->suivant != NULL){
				prev = courant;
				courant = courant->suivant;
			}
			prev->suivant = NULL;
			free(courant);
		}
		else{
			int i;
			liste *prev = NULL;
			liste *courant = L;
			for(i=0;i<pos;i++){
				prev = courant;
				courant = courant->suivant;
			}
			prev->suivant = courant->suivant;
			free(courant);
		}
	}
	return L;
}

liste* Inserer_trie(liste *L, int x){
	if(L == NULL){
		printf("La liste est vide\n");
		return L;
	}
	liste *c = L;
	liste *p = (liste*)malloc(sizeof(liste));
	p->value = x;
	while(c->suivant != NULL){
		c = c->suivant;
	}
	if(x<L->value){
		p->suivant = L;
		L=p;
	}
	else{
		if(x>c->value){
			p->suivant = NULL;
			c->suivant = p;
		}
		else{
			liste *m = L;
			liste *n = L->suivant;
			while (n != NULL){
				if(m->value < x && x < n->value){
					m->suivant = p;
					p->suivant = n;
				}
				else{
					m = n;
					n = n->suivant;
				}
			}
		}
	}
	return L;
}

int main(){
	liste *ma_liste = NULL;
	ma_liste = ajouter_element(ma_liste,1);
	ma_liste = ajouter_element(ma_liste,3);
	ma_liste = ajouter_element(ma_liste,5);
	afficher_liste(ma_liste);
	ma_liste = inserer_pos(0,0,ma_liste);
	ma_liste = inserer_pos(2,2,ma_liste);
	ma_liste = inserer_pos(4,4,ma_liste);
	afficher_liste(ma_liste);
	ma_liste = Inserer_trie(ma_liste,6);
	afficher_liste(ma_liste);
}