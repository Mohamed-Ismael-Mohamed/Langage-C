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

void display(Node *top){
	if(top == NULL){
		return;
	}
	printf("%d->",top->data);
	display(top->next);
}

int sum_element(Node *head){
	if(head == NULL){
		return 0;
	}
	return head->data + sum_element(head->next);
}

void reverse_list(Node *head, Node *prev){
	if(head == NULL){
		if(prev != NULL){
			printf("Affichage de la LISTE RENVERSER\n");
			display(prev);
			printf("NULL\n");
		}
		return;
	}
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = head->data;
	p->next = prev;
	prev = p;
	reverse_list(head->next,prev);
}

int main(){
	Node *stack = NULL;
	append(&stack,10);
	append(&stack,20);
	append(&stack,30);
	append(&stack,40);
	append(&stack,50);
	
	printf("Contenue de la Pile\n");
	display(stack);
	printf("NULL\n");
	
	printf("Somme des elements : %d\n",sum_element(stack));
	reverse_list(stack,NULL);
}