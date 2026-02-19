#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tache{
	int id;
	char nom[70];
	int priorite;
	struct tache *prev;
	struct tache *next;
}tache;

typedef struct{
	tache *tete;
	tache *queue;
}liste_tache;

void initialiser(liste_tache *L){
	L->tete = NULL;
	L->queue = NULL;
}

void ajouter_fin(liste_tache *L, int id, char nom[], int prio){
	tache *p = (tache*)malloc(sizeof(tache));
	p->id = id;
	strcpy(p->nom,nom);
	p->priorite = prio;
	p->next = NULL; 
	if(L->tete == NULL){
		p->prev = NULL;
		L->tete = p;
		L->queue = p;
	}
	else{
		L->queue->next = p;
		p->prev = L->queue;
		L->queue = p;
	}
}

void supprimer_tache_id(liste_tache *L, int id){
	tache *c = L->tete;
	while(c->id != id){
		c = c->next;
	}
	if(c->prev == NULL){
		L->tete = L->tete->next;
		if(L->tete == NULL){
			L->queue = NULL;
		}
		else{
			L->tete->prev = NULL;
		}
		free(c);
	}
	else{
		if(c->next == NULL){
			L->queue = L->queue->prev;
			if(L->queue == NULL){
				L->tete = NULL;
			}else{
				L->queue->next = NULL;
			}
			free(c);
		}
		else{
			c->prev->next = c->next;
			c->next->prev = c->prev;
			free(c);
		}
	}
}

void supprimer_tache_prioritaire(liste_tache *L){
	int max = L->tete->priorite;
	tache *adresse_max = L->tete;
	tache *c = L->tete;
	while(c != NULL){
		if(c->priorite > max){
			max = c->priorite;
			adresse_max = c;
		}
		c = c->next;
	}
	supprimer_tache_id(L,adresse_max->id);
}

void afficher_liste_tache(liste_tache *L){
	printf("Affichage de la liste dans l'ordre\n");
	tache *c = L->tete;
	while(c != NULL){
		printf("Tache id = %d  || nom = %s  || priorite = %d\n",c->id,c->nom,c->priorite);
		c = c->next;
	}
}

void affichage_par_ordre_priorite(liste_tache *L){
	int priorite_max = L->tete->priorite;
	int priorite_min = L->tete->priorite;
	tache *c = L->tete;
	while(c != NULL){
		if(c->priorite > priorite_max){
			priorite_max = c->priorite;
		}
		if(c->priorite < priorite_min){
			priorite_min = c->priorite;
		}
		c = c->next;
	}
	printf("Priorite DECROISSANTE\n");
	while(priorite_max >= priorite_min){
		tache *a = L->tete;
		while(a != NULL){
			if(a->priorite == priorite_max){
				printf("id = %d \\ nom = %s \\ priorite = %d\n",a->id,a->nom,a->priorite);
			}
			a = a->next;
		}
		priorite_max--;
	}
}

void rechercher_id(liste_tache *L, int id){
	tache *c = L->tete;
	while(c->id != id){
		c = c->next;
	}
	if(c==NULL){
		printf("Id de la tache introuvable\n");
		return;
	}
	printf("Tache Rechercher trouver !\n");
	printf("id = %d \\ nom = %s \\ priorite = %d\n",c->id,c->nom,c->priorite);
}

int main(){
	liste_tache ma_liste;
	initialiser(&ma_liste);
	int choix, id, prio;
    char nom[70];

    do{
        printf("\n===== MENU =====\n");
        printf("1. Ajouter tache\n");
        printf("2. Supprimer par id\n");
        printf("3. Supprimer tache prioritaire\n");
        printf("4. Afficher liste\n");
        printf("5. Afficher par priorite\n");
        printf("6. Rechercher par id\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                printf("Id : ");
                scanf("%d", &id);
                printf("Nom : ");
                scanf("%s", nom);
                printf("Priorite : ");
                scanf("%d", &prio);
                ajouter_fin(&ma_liste, id, nom, prio);
                break;

            case 2:
                printf("Id a supprimer : ");
                scanf("%d", &id);
                supprimer_tache_id(&ma_liste, id);
                break;

            case 3:
                supprimer_tache_prioritaire(&ma_liste);
                break;

            case 4:
                afficher_liste_tache(&ma_liste);
                break;

            case 5:
                affichage_par_ordre_priorite(&ma_liste);
                break;

            case 6:
                printf("Id a rechercher : ");
                scanf("%d", &id);
                rechercher_id(&ma_liste, id);
                break;

            case 0:
                printf("Fin du programme\n");
                break;

            default:
                printf("Choix invalide\n");
        }

    }while(choix != 0);

    return 0;
}
