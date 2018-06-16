#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* create(int size){


	if(size<1)
		return NULL;

	int i;
	node* head = (node*) malloc(sizeof(node));
	node* current;

	current = head;

	for(i=0;i<size;i++){

		current->data = 0;
		current->next = i<size-1 ? (node*) malloc(sizeof(node)): NULL;
		current = current->next;

	}

	return head;


}

void print(node* head){
	node* current = head;

	printf("\n");

	while(current != NULL){
		printf("%d\t",current->data);
		current = current->next;
	}

	printf("\n");


}

void insert_at_head(node** head, int data){

	if(*head == NULL)
		return;

	node* newnode = (node*) malloc(sizeof(node));
	if(newnode==NULL){
		printf("Memory Error");
		return;
	}
	newnode->data = data;
	newnode->next = *head;
	*head = newnode; 

}

void insert_otherwise(node** head, int data, int position){
	node* newnode = (node*) malloc(sizeof(node));
	newnode->data = data;

	node *p,*q;
	int k = 1;

	p = *head;

	while(p!=NULL && k < position){
		q = p;
		p = p-> next;
		k++;

	}

	q->next = newnode;
	newnode->next = p;

}

void delete_head(node** head){
	node *temp = *head;

	*head = (*head)->next;
	free(temp);
}

void delete_otherwise(node** head,int position){

	if(position<1)
		return;
	node *p,*q;
	int count = 1;

	p = *head;

	while(p!=NULL && count<position){
		q = p;	
		p = p->next;
		count++;

	}

	if(p==NULL){
		printf("position does not exist. \n");
		return;
	}

	q->next = p->next;
	free(p);




}

void main() {

	int a[] = {1,2,3,4,5};

	node* head = create(5);

	node* current = head;
	int i = 0;

	while(current!=NULL){

		current->data = a[i];
		current = current->next;
		i++;

	}

	print(head);
	
	insert_at_head(&head,9);
	print(head);
	insert_otherwise(&head,99,3);
	print(head);

	delete_otherwise(&head,3);
	print(head);
	delete_head(&head);
	print(head);







}