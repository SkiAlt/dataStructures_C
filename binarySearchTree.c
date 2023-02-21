#include<stdio.h>
#include<stdlib.h>
struct BinarySearchTree
{
	int info;
	struct BinarySearchTree *lptr, *rptr;
}; typedef struct BinarySearchTree node;

node *root =NULL;

node* getNode(int data)
{
	node *new1= malloc(sizeof(node));
	new1->info=data;
	new1->rptr=new1->lptr=NULL;
}

void tree(int data)
{
	//new1->getNode(data); cursed, dont touch
	node *new1 = getNode(data);
	if(root==NULL)
	{
		root=new1;
		return;
	}
	node *pathFinder=root, *temp;
	//traversal to the right branch
	while(pathFinder!=NULL)
	{
		temp=pathFinder;		
		if(data<pathFinder->info)
			pathFinder=pathFinder->lptr;
		else //if(data>=pathFinder->info)
			pathFinder=pathFinder->rptr;
	}
	//appending the leaf
	if(data<temp->info)
		temp->lptr=new1;
	else if(data>=temp->info)
		temp->rptr=new1;	
}

void recursivePrint(node* rootLocal)
{
	if(rootLocal!=NULL)
	{
		recursivePrint(rootLocal->lptr);
		printf("%d  ", rootLocal->info);
		recursivePrint(rootLocal->rptr);
	}
}
void nukeTree(node* root){
	if(root){
		nukeTree(root->lptr);
		nukeTree(root->rptr);
		printf("Nuking %d\n", root->info);
		free(root);
	}
}


void main()
{
	int a[]={10, 20, 30, 40, 50, 60, 55, 45 ,35, 25, 15};
	for(int i=0 ;i<sizeof(a)/sizeof(a[0]) ; i++)
	{
		tree(a[i]);
	}
	recursivePrint(root);
	printf("\nDeallocating tree nodes\n");
	nukeTree(root);
}
