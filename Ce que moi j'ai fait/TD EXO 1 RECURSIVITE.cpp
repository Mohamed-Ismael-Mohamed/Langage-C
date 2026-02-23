#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

void push(Node **top, int value){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = value;
	p->next = *top;
	*top = p;
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
	push(&stack,1);
	push(&stack,2);
	push(&stack,3);
	
	printf("Contenue de la Pile\n");
	display(stack);
	printf("NULL\n");
}