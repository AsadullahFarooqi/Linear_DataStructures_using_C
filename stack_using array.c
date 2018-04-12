#include <stdio.h>
#include <stdlib.h>

#define total_stack_items 5

int stack[total_stack_items], top = -1;
bool isempty();
bool isfull();
void push(int data);
int pop();
int peek();
void display();

int main(){
	int option;
	// printf("enter the number of items in stack.\n");
	// scanf("%d", &total_stack_items);

	do{
		printf(" 1 :: to see if stack empty.\n");
		printf(" 2 :: to see if stack is full.\n");
		printf(" 3 :: to display stack.\n");
		printf(" 4 :: push.\n");
		printf(" 5 :: pop.\n");
		printf(" 6 :: peak.\n");
		printf("-1 :: to exit.\n");
		
		scanf("%d", &option);
		
		switch(option){
			case 1: // length of the list
				printf("%s \n", isempty() ? "true" : "false");
				break;
			case 2: // print list reversily
				printf("%s \n", isfull() ? "true" : "false");
				break;
			case 3: // print list normally
				display();
				break;

			case 4: //enter at the begining of the list
				int val;
				printf("enter the value\n");
				scanf("%d", &val);
				push(val);
				break;

			case 5:
				printf("%d \n", pop());
				break;

			case 6:
				printf("%d \n", peek());
				break;
		}
	}while(option != -1);

	return 0;
}

bool isempty(){
	if (top == -1) {
		return true;
	}else{
		return false;
	}
}

bool isfull(){
	if (top == total_stack_items) return true;
	return false;
}
void push(int data){
	if (isfull()) {
		printf("stack is full :( \n");
		return;
	}else{
		top++;
		stack[top] = data;
	}
}
int pop(){
	if (isempty()) {
		printf("stack is empty\n"); 
		return 0;
	}
	else
	{
	int data = stack[top];
	top--;
	return data;
	}
}
int peek(){
	if (isempty()) {
		printf("stack is empty\n"); return 0;
	}else{
		return stack[top];
	}
	
}
void display(){
	if (isempty()) {
		printf("stack is empty\n"); return;
	}else{
		int i;
		for (i=top; i>=0; i--){
			printf("%d, ", stack[i]);
		}
		printf("\n");
	}
	
}