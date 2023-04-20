#include <stdio.h>
#include <stdlib.h>

typedef struct SLL {
	int info;
	struct SLL *next;
} node;

node* getNode(int data) {
	node* new1 = (node*) malloc(sizeof(node));
	new1->next = NULL;
	new1->info = data;
	return new1;
}

node* createNnodes(int a[], int n) {
	node *start, *end;
	start = getNode(a[0]);
	end = start;
	for(int i = 1; i < n; i++) {
		node* new1 = getNode(a[i]);
		end->next = new1;
		end = new1;
	}
	return start;		
}
void printList(node* start) {
	printf("\n");
	while(start) {
		printf("%d ", start->info);
		start = start->next;
	} 
	printf("\n\n");
}

node* reverse(node* start) {
	node *temp, *prev = NULL, *curr = start;
	while(curr) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

int main() {
	int a[] = {1,2,3};
	int n = sizeof(a) / sizeof(a[0]);
	node* start = createNnodes(a,n);
	printf("Before reversal:\n");
	printList(start);
	start = reverse(start);
	printf("After reversal:\n");
	printList(start);
	return 0;	
}
