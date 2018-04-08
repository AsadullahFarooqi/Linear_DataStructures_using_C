#include <stdio.h>
#include <stdlib.h>

struct stack_node{
	int data;
	struct stack_node* bottom_item_link;
};

struct stack_node *top = NULL;

//length of the Stack
int height(){
	
	int counter = 0;

	if (top == NULL) {
		return 0;

	}
	else if (top -> bottom_item_link == NULL){
		return 1;
	}
	else {

		struct stack_node *ptr = top;

		while (ptr -> bottom_item_link != NULL){
			ptr = ptr -> bottom_item_link;
			counter++;
			if (ptr -> bottom_item_link == NULL){
				counter++;
			}
		}

		return counter;
	}
}


//display Stack normally using iteration
void print_stack(){
	
	if (top == NULL) return;

	struct stack_node *ptr = top;

	while(ptr -> bottom_item_link != NULL){
		printf("%d, ", ptr -> data);
		ptr = ptr -> bottom_item_link;
		if (ptr -> bottom_item_link == NULL){
			printf("%d, ", ptr -> data);
			break;
		}
	}
	printf("\n");
}

//display Stack normally using iteration
int peak(){
	if (top == NULL) printf("Stack is empty \n"); return 0;
	return top -> data;	
}

//insert item at the begining of the Stack 
void push(int item){

	struct stack_node *new_node;

	new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
	new_node -> data = item;
	
	if (top == NULL) {

		new_node -> bottom_item_link = NULL;
		top = new_node;
		printf("%d is added at the begining of the Stack! \n", item);
	
	} else{
		
		new_node -> bottom_item_link = top;
		printf("%d is added at the begining of the Stack! \n", item);
		top = new_node;

	}	
}


//deleting item from the top of Stack
void pop(){
	struct stack_node *ptr;
	ptr = top;
	top = top -> bottom_item_link;
	printf("%d is deleted from the begining of the Stack\n", ptr -> data);
	free(ptr);
}


int main(){

	int option;

	do{
		printf(" 1 :: to see the height of the stack.\n");
		printf(" 2 :: see the stack.\n");
		printf(" 3 :: peak.\n");
		printf(" 4 :: push.\n");
		printf(" 5 :: pop.\n");
		printf("-1 :: to exit.\n");
		
		scanf("%d", &option);
		
		switch(option){
			case 1: // length of the Stack
				printf("%d \n",height());
				break;
			case 2: // print Stack reversily
				print_stack();
				break;
			case 3: // print Stack normally
				print("%d \n", peak());
				break;

			case 4: //enter at the begining of the Stack
				int val_for_beg;
				printf("enter the value.\n");
				scanf("%d", &val_for_beg);
				push(val_for_beg);

				break;

			case 5:
				pop();
				break;
		}
	}while(option != -1);

	return 0;
}
