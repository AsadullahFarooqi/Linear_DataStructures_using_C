#include <stdio.h>
#include <stdlib.h>

struct queue_node{
	int data;
	struct queue_node* rightside_item_link;
};

struct queue_node *head = NULL;

//length of the queue
int length_of_queue(){
	
	int counter = 0;

	if (head == NULL) {
		return 0;

	}
	else if (head -> rightside_item_link == NULL){
		return 1;
	}
	else {

		struct queue_node *ptr = head;

		while (ptr -> rightside_item_link != NULL){
			ptr = ptr -> rightside_item_link;
			counter++;
			if (ptr -> rightside_item_link == NULL){
				counter++;
			}
		}

		return counter;
	}
}

//display queue normally using iteration
void print_queue(){
	
	if (head == NULL) return;

	struct queue_node *ptr = head;

	while(ptr -> rightside_item_link != NULL){
		printf("%d, ", ptr -> data);
		ptr = ptr -> rightside_item_link;
		if (ptr -> rightside_item_link == NULL){
			printf("%d, ", ptr -> data);
			break;
		}
	}
	printf("\n");
}

//display queue normally using iteration
int back(){
	if (head == NULL){
		printf("queue is empty \n");
		return 0;
	}else{
		return head -> data;	
	}
		
}

//display queue normally using iteration
int front(){
	
	if (head == NULL) {
		printf("queue is empty!");
		return 0;
	}else if (head -> rightside_item_link == NULL){
		return head -> data;
	}else{
		struct queue_node *ptr;
		ptr = head;

		while(ptr -> rightside_item_link != NULL){
			ptr = ptr -> rightside_item_link;
		}
		return ptr -> data;	
	}

	
		
}

//insert item at the begining of the queue 
void enqueue(int item){

	struct queue_node *new_node;

	new_node = (struct queue_node*)malloc(sizeof(struct queue_node));
	new_node -> data = item;
	
	if (head == NULL) {

		new_node -> rightside_item_link = NULL;
		head = new_node;
		printf("%d is added at the begining of the queue! \n", item);
	
	} else{
		
		new_node -> rightside_item_link = head;
		printf("%d is added at the begining of the queue! \n", item);
		head = new_node;

	}	
}

//deleting item from the tail of the list 
void dequeue(){
	
	if (head == NULL) return;

	struct queue_node *ptr, *prev_node_to_null;
	ptr = head;

	while(ptr -> rightside_item_link != NULL){
		prev_node_to_null = ptr;
		ptr = ptr -> rightside_item_link;
	}

	prev_node_to_null -> rightside_item_link = NULL;
	printf("%d is deleted from the begining of the list\n", ptr -> data);
	free(ptr);
}


int main(){

	int option;

	do{
		printf(" 1 :: to see the length of the queue.\n");
		printf(" 2 :: to print the queue.\n");
		printf(" 3 :: front.\n");
		printf(" 4 :: back.\n");
		printf(" 5 :: enqueue.\n");
		printf(" 6 :: dequeue.\n");
		printf("-1 :: to exit.\n");
		
		scanf("%d", &option);
		
		switch(option){
			case 1: // length of the queue
				printf("%d \n",length_of_queue());
				break;
			case 2:
				print_queue();
				break;
			case 3: // print queue reversily
				printf("%d\n", front());
				break;
			case 4: // print queue normally
				printf("%d \n", back());
				break;
			case 5: //enter at the begining of the queue
				int val_for_beg;
				printf("enter the value.\n");
				scanf("%d", &val_for_beg);
				enqueue(val_for_beg);
				break;
			case 6:
				dequeue();
				break;

		}
	}while(option != -1);

	return 0;
}
