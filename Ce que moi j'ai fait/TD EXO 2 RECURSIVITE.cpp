#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;


Node* createNode(int value){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = value;
	p->next = NULL;
	return p;
}

void append(Node **head, int value){
	if(*head == NULL){
		Node *p = createNode(value);
		*head = p;
		return;
	}
	append(&(*head)->next,value);
}

int search(Node *head, int value){
	if(head == NULL){
		return 0;
	}
	if(head->data == value){
		return 1;
	}
	search(head->next,value);
}
void display(Node *top){
	if(top == NULL){
		return;
	}
	printf("%d->",top->data);
	display(top->next);
}

int main(){
	Node *stack = NULL;
	append(&stack,1);
	append(&stack,2);
	append(&stack,3);
	
	printf("Contenue de la Pile\n");
	display(stack);
	printf("NULL\n");
	int value;
	printf("Quelle valeur chercher ? : ");
	scanf("%d",&value);
	int resultat = search(stack,value);
	if (resultat){
		printf("Trouvee\n");
	}
	else{
		printf("Pas Trouvee\n");
	}
}