#include<stdio.h>
#include<stdlib.h>
#include<math.h> //don't forget -lm while compiling!!
struct Polynomial
{
	int cf, xp, yp, zp;
	struct Polynomial *next;
};
typedef struct Polynomial node;
node *equation=NULL;

node* newTerm(node **eqn)
{
	node *new1=malloc(sizeof(node));
	new1->next=NULL;
	if((*eqn)==NULL)
	{
		*eqn=new1;
		return new1;
	}
	node *temp=*eqn;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new1;
	return new1;
}

void initEquation()
{
	char ch;
	do{
	node *new1= newTerm(&equation);
	printf("Enter:\ncf xp yp zp:\n");
	scanf("%d%d%d%d",&new1->cf,&new1->xp,&new1->yp,&new1->zp);
	printf("Another term? y/n?:  ");
	scanf("\n%c",&ch);
	}while(ch=='y');	
}

int evaluate(int x, int y, int z)
{
	int result=0;
	node *temp=equation;
	while(temp!=NULL)
	{
		result+= (temp->cf)*(pow(x,temp->xp))*(pow(y,temp->yp))*(pow(z,temp->zp));
		temp=temp->next;
	}
	return result;
}

int main()
{
	initEquation();
	printf("Enter the roots: x,y,z values-\n");
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	printf("%d\n",evaluate(x,y,z));
	return 0;
}
