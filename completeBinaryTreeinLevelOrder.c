/*Given an array of elements, construct a complete binary tree from this array in level order
fashion. That is, elements from left in the array will be filled in the tree level wise starting from
level 0*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct BinarySearchTree 
{
        int info;
        struct BinarySearchTree * lptr, * rptr;
};
typedef struct BinarySearchTree node;
//queue Implementaion
int f = 0, r = -1, count = 0;
node * q[SIZE]; //#define SIZE 10
void enqueue(node * address){
        r = (r + 1) % SIZE;
        q[r] = address;
        count++;
}
node * dequeue() {
        int preF = f;
        f = (f + 1) % SIZE;
        count--;
        return q[preF];
}

node * getnode(int data) {
        node * new1 = malloc(sizeof(node));
        new1->info=data;
        new1 -> lptr = new1 -> rptr = NULL;
        return new1;
}
node* lvlotree(node* root, int a[],int noarrele) {
        node * temp;
        int i=0;
        root = getnode(a[i++]);
        enqueue(root);
       	while(i<noarrele)
        {
                temp = dequeue();
                temp -> lptr = getnode(a[i++]);
                enqueue(temp -> lptr);
               	if(i<noarrele){
                temp -> rptr = getnode(a[i++]);
                enqueue(temp -> rptr);
                }//ugly fix for incomplete BT
        }
        return root;
}

void levelorderTraversal(node * rootL) {
        f = 0;
        r = -1;
        count = 0;
        node * temp;
        enqueue(rootL);
        do {
                temp = dequeue(); //copied
                printf("%d  ", temp -> info);
                if (temp -> lptr) //GN's
                        enqueue(temp -> lptr);
                if (temp -> rptr) //logic
                        enqueue(temp -> rptr);
        } while (count > 0);
}
void inorder(node* root)
{
	if(root)
	{
		inorder(root->lptr);
		printf("%d  ", root->info);
		inorder(root->rptr);
	}
}
void main() {
        node * root = NULL;
        int a[] = {1,2,3,4,5,6}; //pay attention to no of elements. 
        /*if A complete binary tree is a binary tree in which every level, 
        except possibly the last, is completely filled, and all nodes in the last level are as far left as possible, 
        then my code doesn't work. well now it does. but it's excessivly ugly.*/
        int noarrele=sizeof(a)/sizeof(a[0]);
        root = lvlotree(root, a ,noarrele);
        printf("Expected output:\n");
        for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
        	printf("%d  ",a[i]);
        printf(" \n");
        printf("Level order output after tree generation:\n");	
        levelorderTraversal(root);
        printf("\n");
        printf("inorder for comparison: \n");
        inorder(root);
        printf(" \n");
}
//debug tools:
// printf(" \n");
