#include <stdio.h>
#include <stdlib.h>
struct Polynomial
{
	int cf, xp, yp, zp, used;
	struct Polynomial *next;
};
typedef struct Polynomial node;
node *equation1 = NULL, *equation2 = NULL, *result = NULL;

void display(node *equation)
{
	while (equation != NULL)
	{
		printf("(%d x^(%d) y^(%d) Z^(%d))", equation->cf, equation->xp, equation->yp, equation->zp);
		if(equation->next!=NULL)
			printf(" + ");
		equation = equation->next;
	}
	printf("\n");
}

node* newTerm(node **equation)
{
	node *new1 = malloc(sizeof(node));
	new1->used = 0;
	new1->next = NULL;
	// inserting new term at the end of the equation:
	if (*equation == NULL) // if 0 nodes
	{
		*equation = new1;
		return new1;		
	}
	node *temp = *equation;
	while (temp->next != NULL)
		temp = temp->next;
		temp->next = new1;
	return new1;
}

void initEquations()
{
	char ch;
	printf("Note: Equations should be in standard form.\n");
	printf("Reading Equation 1:\n");
	do
	{
		node *new1 = newTerm(&equation1);
		printf("Enter coeff, x power, y power, and z power:\n");
		scanf("%d%d%d%d", &new1->cf, &new1->xp, &new1->yp, &new1->zp);
		printf("Another term?: y/n?  ");
		scanf("\n%c", &ch); // ch input GAEEE
	} while (ch == 'y');

	printf("Reading Equation 2:\n");
	do
	{
		node *new1 = newTerm(&equation2);
		printf("Enter coeff, x power, y power, and z power:\n");
		scanf("%d%d%d%d", &new1->cf, &new1->xp, &new1->yp, &new1->zp);
		printf("Another term?: y/n?\n");
		scanf("\n%c", &ch);
	} while (ch == 'y');
}
void collect(node* equation)
{
	node *temp = equation;
	while (temp!= NULL)
	{
		if (temp->used == 0)
		{
			node *new1 = newTerm(&result);
			new1->cf = temp->cf;
			new1->xp = temp->xp;
			new1->yp = temp->yp;
			new1->zp = temp->zp;
			temp->used = 1;
		}
		temp = temp->next;
	}
}
void add()
{
	node *temp1 = equation1, *temp2;
	while (temp1 != NULL)
	{
		temp2 = equation2;
		while (temp2 != NULL)
		{	//if 2nd eqn term is not used AND the powers match, then add 
			if (temp2->used != 1 && temp1->xp == temp2->xp && temp1->yp == temp2->yp && temp1->zp == temp2->zp) 
			{
				node *new1 = newTerm(&result);
				new1->cf = temp1->cf + temp2->cf;
				new1->xp = temp1->xp;
				new1->yp = temp1->yp;
				new1->zp = temp1->zp;
				temp1->used = temp2->used = 1;
				break;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	collect(equation1);
	collect(equation2);
}

int main()
{
	initEquations();
	printf("\n");
	display(equation1);
	printf("\t+\n");
	display(equation2);
	add();
	printf("\n");
	display(result);
	return 0;
}
