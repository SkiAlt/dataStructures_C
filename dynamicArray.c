#include<stdio.h>
#include<stdlib.h>

void create(int *p, int *n)
{
	int i;
	printf("Enter the array elements: ");
	for(i=0;i<*n;i++)
	{
		scanf("%d",(p+i)); //like (&)a[i]. but not really.
	}
}

void display(int *p, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",*(p+i));
	}
	printf("\n");
}

void insert(int *p, int *n)
{
	int ele, pos,i,temp;
	printf("Enter the element and position: ");
	scanf("%d %d", &ele,&pos);
	if(pos<=*n)
	{ 
		printf("Array before insertion:\n");
		temp=*n;
		display(p,temp);
		(*n)++; //OMFG 
		for(i=*n-1;i>pos-1;i--)
		{
			*(p+i)=*(p+i-1);
		}
		*(p+pos-1)=ele;
		printf("\nArray after insertion:\n");
		temp=*n;
		display(p,temp);
	}
	else printf("Invalid position");
}

void delete(int *p, int *n)
{
	int pos, i,temp=*n;
	display(p,temp);
	printf("\nEnter the position of the element to be deleted: ");
	scanf("%d",&pos);
	if(pos<=*n-1)
	{
		for(i=pos-1;i<*n-1;i++)
		{
			*(p+i)=*(p+i+1);
		}
		(*n)--; //OMFG
		printf("Array after deletion:\n");
		temp=*n;
		display(p,temp);
	}
	else printf("Invalid position.");
}

void main()
{
	int *p, i, n, ch;
	printf("Enter array size: ");
	scanf("%d",&n);
	p = (int *) malloc (n*sizeof(int)); //dynamic allocation
	create(p,&n);
	for(;;)
	{
		printf("1.Insert 2.Delete 3.Display:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(p,&n); break;
			case 2: delete(p,&n); break;
			case 3: display(p,n); break;
			default: {printf("Invalid Input. Terminating...\n"); exit(0); }
		}
	}
	
}
