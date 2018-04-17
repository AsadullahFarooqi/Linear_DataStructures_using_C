#include <stdio.h>
#include <stdlib.h>

struct List_Node{
	int data;
	struct List_Node* next_node_link;
};

struct List_Node *head = NULL;

//length of the list
int length(){
	
	int counter = 0;

	if (head == NULL) {
		return 0;

	}
	else if (head -> next_node_link == head){
		return 1;
	}
	else {

		struct List_Node *ptr = head;

		while (ptr -> next_node_link != head){
			ptr = ptr -> next_node_link;
			counter++;
			if (ptr -> next_node_link == head){
				counter++;
			}
		}

		return counter;
	}
}

//display list reversly using recursion
void print_list_reversly(struct List_Node *h){
	
	if (h == head) return;

	print_list_reversly(h -> next_node_link);
	printf("%d, ", h -> data);
}

//display list normally using iteration
void print_list(){
	
	if (head == NULL) return;

	struct List_Node *ptr = head;

	while(ptr -> next_node_link != head){
		printf("%d, ", ptr -> data);
		ptr = ptr -> next_node_link;
		if (ptr -> next_node_link == head){
			printf("%d, ", ptr -> data);
			break;
		}
	}
	printf("\n");
}

//insert item at the begining of the list 
void insert_item_at_beg(int item){

	struct List_Node *new_node;

	new_node = (struct List_Node*)malloc(sizeof(struct List_Node));
	new_node -> data = item;
	
	if (head == NULL) {

		new_node -> next_node_link = new_node;
		head = new_node;
		
		printf("%d is added at the begining of the list! \n", item);
	
	} else{
		
		new_node -> next_node_link = head;
		printf("%d is added at the begining of the list! \n", item);
		head = new_node;

	}	
}

//insert item at the end of the list
void insert_item_at_end(int item){

	struct List_Node *new_node;

	new_node = (struct List_Node*)malloc(sizeof(struct List_Node));
	new_node -> data = item;
	new_node -> next_node_link = new_node;

	if (head == NULL){

		head = new_node;
		new_node -> next_node_link = head;
		printf("%d is added at the end of the list! \n", item);
		return;

	} else{
		struct List_Node *ptr;

		ptr = head;

		while(ptr -> next_node_link != head){
			ptr = ptr -> next_node_link;
		}

		ptr -> next_node_link = new_node;
		printf("%d is added at the end of the list! \n", item);

	}
}

//insert item anywhere in the list using index key
void insert_on_nth_position(int item, int key){

	if (head == NULL){
		insert_item_at_beg(item);
		return;
	}else if ( key > length()) {
	
		printf("this index is too high list doesn't has that much items\n");
		return;
	}else{
		int list_item_counter, i;
		list_item_counter = 0;

		struct List_Node *ptr;
		ptr = head;

		struct List_Node *new_node;
		new_node = (struct List_Node*)malloc(sizeof(struct List_Node));
		new_node -> data = item;

		for (i=1;i<= key-2;i++){
			ptr = ptr -> next_node_link;
		}

		new_node -> next_node_link = ptr -> next_node_link;
		ptr -> next_node_link = new_node;

		printf("%d is added to %d position of the list list! \n", item, key);

	}
}

//deleting item from the head of list
void del_from_beg(){
	struct List_Node *ptr;
	ptr = head;
	head = head -> next_node_link;
	printf("%d is deleted from the begining of the list\n", ptr -> data);
	free(ptr);
}

//deleting item from the tail of the list 
void del_from_end(){
	
	if (head == NULL) return;

	struct List_Node *ptr, *prev_node_to_null;
	ptr = head;

	while(ptr -> next_node_link != head){
		prev_node_to_null = ptr;
		ptr = ptr -> next_node_link;
	}

	prev_node_to_null -> next_node_link = head;
	printf("%d is deleted from the begining of the list\n", ptr -> data);
	free(ptr);
}

//deleting item by value
void del_by_val(int item){

	if (head == NULL) {
		printf("list is empty :( \n");
	}
	else if (head -> data == item) {
		del_from_beg();
	}
	else{
		
		struct List_Node *ptr, *ptr2;
		ptr = head;
	

		while(ptr -> data != item){
			if (ptr -> next_node_link == head) break;
			ptr2 = ptr;
			ptr = ptr -> next_node_link;
		}
		if (ptr -> data == item){
			ptr2 -> next_node_link = ptr -> next_node_link;
			printf("%d is deleted from the list\n", ptr -> data);
			free(ptr);
		}else{
			printf("item is not exist in the list  :(\n");
		}
	}
}

//deleting item by key
void del_by_key(int key){
	
	if (head == NULL || key > length()) {
		printf("this index is too high list doesn't has that much items\n");
		return;
	}else if (key == 1){
		del_from_beg();
		return;
	}else if (key == -1){
		del_from_end();
		return;
	}

	struct List_Node *ptr, *ptr2;
	ptr = head;

	int i;
	for (i=1;i<=key-1; i++){

		ptr2 = ptr;
		ptr = ptr -> next_node_link;
	}

	ptr2 -> next_node_link = ptr -> next_node_link;
	printf("%d is deleted from the list\n", ptr -> data);
	free(ptr);
}

void del_list(){
	if (head == NULL) return;
	struct List_Node *ptr;
	ptr = head;
	while(ptr != head){
		del_from_end();
		ptr = ptr -> next_node_link;
	}
}


int main(){

	int option;

	do{
		printf(" 1 :: to see the length of the list.\n");
		printf(" 2 :: to display list reversly.\n");
		printf(" 3 :: to display list normally.\n");
		printf(" 4 :: to insert item at the begining of list.\n");
		printf(" 5 :: to insert item at the end of list.\n");
		printf(" 6 :: to insert item at the nth location of list.\n");
		printf(" 7 :: to delete item from the begining of the list.\n");
		printf(" 8 :: to delete item from the end of the list.\n");
		printf(" 9 :: to delete item by value.\n");
		printf("10 :: to delete item by key.\n");
		printf("11 :: to delete the whole list.\n");
		printf("-1 :: to exit.\n");
		
		scanf("%d", &option);
		
		switch(option){
			case 1: // length of the list
				printf("%d \n",length());
				break;
			case 2: // print list reversily
				struct List_Node *ptr;
				ptr = head;
				print_list_reversly(head);
				break;
			case 3: // print list normally
				print_list();
				break;

			case 4: //enter at the begining of the list
				int val_for_beg;
				printf("enter the value.\n");
				scanf("%d", &val_for_beg);
				// while (val_for_beg == -11){
				insert_item_at_beg(val_for_beg);
				// 	scanf("%d", &val_for_beg);
				// 	printf("\n");
				// }
				break;

			case 5:
				int val_for_end;
				printf("enter the value.\n");
				scanf("%d", &val_for_end);
				// while (val_for_end == -1){
				insert_item_at_end(val_for_end);
				// 	scanf("%d", &val_for_end);
				// 	printf("\n");
				// }
				break;

			case 6:
				int valu, position;
				printf("enter the value then ',' then position\n");

				// printf("enter the position\n");
				scanf("%d, %d", &valu, &position);
				// while ((valu == -1) || (position == -1)){
				insert_on_nth_position(valu, position);
				// 	scanf("%d, %d", &valu, &position);
				// 	printf("\n");
				// }
				break;

			case 7:
				del_from_beg();
				break;

			case 8:
				del_from_end();
				break;

			case 9:
				int value;
				printf("enter the value \n");
				scanf("%d", &value);
				del_by_val(value);
				break;

			case 10:
				int index;
				printf("enter the index \n");
				scanf("%d", &index);
				del_by_key(index);
				break;

			case 11:
				del_list();
				break;	
		}
	}while(option != -1);

	return 0;
}
