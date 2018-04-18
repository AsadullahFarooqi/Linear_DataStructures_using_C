#include <stdio.h>
#include <stdlib.h>

const int total_queue_items = 8;

int queue[total_queue_items], top = -1;
int front = -1;
int rear = -1;

bool isempty();
bool isfull();
void enqueue(int data);
void dequeue();
int front_item();
int rear_item();
void display_queue();

int main(){

	int option;

	do{
		
		printf(" 1 :: to see the length of the queue.\n");
		printf(" 2 :: to print the queue.\n");
		printf(" 3 :: front.\n");
		printf(" 4 :: back.\n");
		printf(" 5 :: enqueue.\n");
		printf(" 6 :: dequeue.\n");
		printf(" 7 :: to see if queue is empty.\n");
		printf(" 8 :: to see if queue is full.\n");
		printf("-1 :: to exit.\n");
		
		scanf("%d", &option);
		
		switch(option){
			
			case 1: // length of the queue
				printf("%d \n", rear);
				break;
			case 2:
				display_queue();
				break;
			case 3: // print queue reversily
				printf("%d\n", front_item());
				break;
			case 4: // print queue normally
				printf("%d \n", rear_item());
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
			case 7:
				printf("%s \n", isempty() ? "true" : "false");

			case 8:
				printf("%s \n", isfull() ? "true" : "false");

		}
	}while(option != -1);



	return 0;
}

bool isempty(){
	if ((front == -1) && (rear == -1)){
		return true;
	}else{
		return false;
	}
}

bool isfull(){
	if (rear == total_queue_items){
		return true;
	}else{
		return false;
	}
}
void enqueue(int data){
	if (isfull()){
		printf("queue is full \n");
		return;
	}else if (isempty()){
		front = 0;
		rear = 0;
		
	}else{
		rear += 1;
	}
	queue[rear] = data;
}
void dequeue(){
	if (isempty()){
		printf("queue is empty\n");
		return;
	}else if(front_item == rear_item){
		front = -1;
		rear = -1;
	}else{
		front += 1;
	}
}
int front_item(){
	if (isempty()){ 
		printf("queue is empty \n");
		return 0;
	}else{
		return queue[front];
	}
}
int rear_item(){
	if (isempty()){ 
		printf("queue is empty \n");
		return 0;
	}else{
		return queue[rear];
	}
}
void display_queue(){
	if (isempty()){ 
		printf("queue is empty \n");
		return;
	}else{
		int i;
		for(i=front; i <= rear; i += 1){
			printf("%d, ", queue[i]);
		}
		printf("\n");
	}
}