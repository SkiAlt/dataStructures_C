#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct BT
{
	char info;
	struct BT *lptr,*rptr;
}; typedef struct BT node;
node* stack[69];
int top=-1;
void push(node* address)
{
	stack[++top]=address;
}
node* pop()
{
	return(stack[top--]);
}

void create(char string[])
{
	for(int i=0; string[i]!='\0';i++)
	{
		node* new1=malloc(sizeof(node));
		if(isalnum(string[i])) //if operand
		{
			new1->info=string[i];
			new1->lptr=new1->rptr=NULL;
			push(new1);
		}
		else//if operator
		{
			new1->info=string[i];
			new1->rptr=pop();
			new1->lptr=pop();
			push(new1);
		}
	}
}


float evaluate(node* root)
{
	switch(root->info)
	{
		case '+': return(evaluate(root->lptr) + evaluate(root->rptr)); 
		case '/': return(evaluate(root->lptr) / evaluate(root->rptr)); 
		case '*': return(evaluate(root->lptr) * evaluate(root->rptr));
		case '-': return(evaluate(root->lptr) - evaluate(root->rptr));
		default: float operand = (root->info) -'0';
			 return operand;
	}
}

void main()
{
	printf("Enter postfix expression(the operands MUST be numbers!):\n");
	char postfix[69];
	scanf("%s",postfix);
	create(postfix);
	node* root=pop();
	printf("Result: %.2f\n", evaluate(root));
}
