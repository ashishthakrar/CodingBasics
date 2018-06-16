#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* prev;
	struct node* next;
}node;

node* create(int size){
	if(size<1)
		return NULL;

	int i;
	node* head = (node*) malloc(sizeof(node));
	node* current;
	node* previous;

	current = head;
	previous = NULL;

	for(i=0;i<size;i++){
		current->data = 0;
		current->next = i<size-1?(node*)malloc(sizeof(node)):NULL;
		current->prev =  previous;
		previous = current;
		current = current->next;
	}

	return head;

}

void print(node* head){
	node* current = head;

	printf("\n");
	while(current!=NULL){
		printf("%d\t",current->data);
		current = current->next;
	}
	printf("\n");

}

void insert_at_head(node** head,int item){
	node* newnode = (node*) malloc(sizeof(node));
	newnode->data = item;
	newnode->prev = NULL;
	newnode->next = *head;
	(*head)->prev = newnode;
	*head = newnode;
}

void insert_elsewhere(node** head,int item, int position){
	node* newnode = (node*) malloc(sizeof(node));
	newnode->data = item;

	int count = 1;
	node* current = *head;

	while(count < position && current->next!=NULL){
		current = current->next;
		count++;
	}

	if(count!=position){
		printf("the position requested does not exist\n");
		return;
	}

	newnode->next = current->next;
	newnode->prev = current;

	current->next = newnode;
	newnode->next->prev = newnode;


}

void delete_head(node** head){

	if(*head==NULL){
		printf("List is Empty\n");
		return;
	}


	node* temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;

	free(temp);
}

void delete_elsewhere(node**head, int position){
	int count = 1;
	node* temp;
	node* current = *head;

	if(*head==NULL){
		printf("List is Empty\n");
		return;
	}



	while(count<position && current->next!=NULL ){
		current=current->next;
		count++;
	}

	if(count!=position){
		printf("desired position does not exist\n");
		return;
	}


	temp = current->prev;
	temp->next = current->next;

	if(current->next)
		current->next->prev = temp;

	free(current);
	return;

}

int main(){
	int a[] = {1,2,3,4,5};

	node* head = create(5);
	node* current = head;
	int i;

	for(i=0;i<5;i++){
		current->data = a[i];
		current=current->next;

	}

	print(head);

	insert_at_head(&head,9);
	print(head);

	insert_elsewhere(&head,99,3);
	print(head);

	delete_head(&head);
	print(head);

	delete_elsewhere(&head,3);
	print(head);

	delete_elsewhere(&head,6);
	print(head);

	delete_elsewhere(&head,5);
	print(head);




}