#include<stdio.h>
#include<stdlib.h>

struct DLL
{
	int info;
	struct DLL *rptr, *lptr;
};
typedef struct DLL node;
node *start=NULL;

node* getNode()
{
	node *new1=(node*)malloc(sizeof(node));
	printf("Node Info? :  ");
	scanf("%d", &new1->info);
	new1->lptr=new1->rptr=NULL;
	return new1;
}

void display()
{
	if(start==NULL)
	{
		printf("DLL empty\n");
		return;
	}
	node *temp=start;
	while(temp!=NULL)
	{
		printf("%d  ", temp->info);
		temp=temp->rptr;
	}
	printf("\n");
}

void createNnodes()
{
	printf("How many nodes? :  ");
	int n;
	scanf("%d", &n);
	while(n--)
	{
		//creating new node
		node* new1=(node*)malloc(sizeof(node));
		printf("Enter info: ");
		scanf("%d",&new1->info);
		new1->rptr=NULL; //we are inserting at the end
		//establishing link with last node
		node* temp=start;
		if(start==NULL)
		{
			start=new1;
		}
		//if list not empty traverse
		else
		{
			while(temp->rptr!=NULL) //traversal
				temp=temp->rptr;
			temp->rptr=new1; //linking last (but one) node to new node
		}
		new1->lptr=temp; //linking new node to last (but one) node
	}
}

void searchNdestroy()
{
	if(start==NULL)
	{
		printf("DLL empty.\n");
		return;
	}
	printf("Prenuking:\n");
	display();
	node *temp= start; int key, foundFlag=0;
	printf("Key? : ");
	scanf("%d",&key);
	
	while(temp!=NULL) //to access every node
	{
		if(temp->info==key)
		{
			foundFlag=1;
			printf("Nuking: %d\n", temp->info); 
			//if lonely node
			if(start->rptr==NULL)
			{
				free(start);
				start=NULL;
				goto postNuke;
			}
			//multiple nodes
			if(temp==start)
			{	start=start->rptr;
				free(start->lptr);
				start->lptr=NULL;
				temp=start;
				continue;
			}
			(temp->lptr)->rptr=temp->rptr; 
			//if temp is last node
			if(!temp->rptr){
				free(temp);
				goto postNuke;
			}
			(temp->rptr)->lptr=temp->lptr;
			node* nuke=temp;
			temp=temp->rptr; //traversal after hit
			free(nuke);
			continue;
		}
		temp=temp->rptr; //traversal wen miss
	}
	
	if(foundFlag==0)
		printf("Unsuccessful Seach\n");
	else
	{
postNuke:		printf("Post nuking:\n");
		display();	
	}
}

void orderedInsert()
{
	node *new1=getNode(), *temp=start;
	printf("Before Insertion:\n");
	display();
	//NULL node case
	if(start==NULL)
	{
		start=new1;
		goto END;
	}
	//traversal to the right spot
	while( (new1->info) > (temp->info) && temp->rptr!=NULL)
		temp=temp->rptr;
	//insertion at the end
	if(temp->rptr==NULL && (new1->info)>(temp->info)) 
	{
		temp->rptr=new1;
		new1->lptr=temp;
		goto END;
	}
	//insertion at the beggining
	if(temp->lptr==NULL && (new1->info)<(temp->info))	
	{
		start->lptr=new1;
		new1->rptr=start;
		start=new1;
		goto END;	
	}
		
	//insertion in the middle
	new1->rptr=temp;
	new1->lptr=temp->lptr;
	(temp->lptr)->rptr=new1;
	temp->lptr=new1;	
	
END:	printf("After Insertion:\n");
	display();
}

void insertFront()
{
	node *ptr=getNode();
	if(start==NULL)
	{
		start=ptr;
		return;
	}
	start->lptr=ptr;
	ptr->rptr=start;
	start=ptr;
}

void insertRear()
{
	node *new1=getNode(),*temp=start;
	while(temp->rptr!=NULL)
		temp=temp->rptr;
	temp->rptr=new1;
	new1->lptr=temp;
}

void deleteFront()
{
	if(start==NULL)
	{
		printf("DLL empty\n");
		return;
	}
	printf("Deleted node: %d",start->info);
	if(start->rptr==NULL)
	{
		free (start);
		start=NULL;
		return;
	}
	start=start->rptr;
	free(start->lptr);
	start->lptr=NULL;
}

void deleteRear()
{
	if(start==NULL)
	{
		printf("DLL empty\n");
		return;
	}
	if(start->rptr==NULL)
	{
		printf("Deleted node: %d",start->info);
		free (start);
		start=NULL;
		return;
	}
	node *temp=start;
	while(temp->rptr!=NULL)
		temp=temp->rptr;
	printf("Deleted node: %d", temp->info);
	(temp->lptr)->rptr=NULL;
	free (temp);
}

void count()
{
	int count=0;
	node *temp=start;
	if(start==NULL)
	{
		printf("DLL empty\n");
		return;
	}
	while(temp!=NULL)
	{
		count++;
		temp=temp->rptr;
	}
	printf("Number of nodes: %d\n",count);
}

void deleteAll()
{
	while(start->rptr!=NULL)
	{
		start=start->rptr;
		free (start->lptr);
	}
	free (start);
	start=NULL;
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.display()\n2.createNnodes\n3.searchNdestroy()\n4.orderedInsert\n5.insertFront()\n6.insertRear()\n7.deleteFront()\n8.deleteRear()\n9.count()\n10.deleteAll()\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:display(); break;
			case 2: createNnodes(); break;
			case 3: searchNdestroy(); break;
			case 4: orderedInsert();break;
			case 5: insertFront();break;
			case 6: insertRear(); break;
			case 7: deleteFront(); break;
			case 8: deleteRear(); break;
			case 9: count(); break;
			case 10: deleteAll(); break;
			default:printf("Invalid input...\n"); return 0;
		}
	}
}
