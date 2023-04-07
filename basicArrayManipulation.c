#include <stdio.h>
#include <stdlib.h>

void display(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void insert(int a[], int *n)
{
	int ele, pos, i, temp;
	printf("Enter the element and position: ");
	scanf("%d %d", &ele, &pos);
	if (pos <= *n)
	{
		printf("Array before insertion:\n");
		temp = *n;
		display(a, temp);
		(*n)++;
		for (i = *n - 1; i > pos - 1; i--)
		{
			a[i] = a[i - 1];
		}
		a[pos - 1] = ele;
		printf("\nArray after insertion:\n");
		temp = *n;
		display(a, temp);
	}
	else
		printf("Invalid position");
}

void delete(int a[], int *n)
{
	int pos, i, temp = *n;
	display(a, temp);
	printf("\nEnter the position of the element to be deleted: ");
	scanf("%d", &pos);
	if (pos <= *n)
	{
		for (i = pos - 1; i < *n - 1; i++)
		{
			a[i] = a[i + 1];
		}
		(*n)--;
		printf("Array after deletion:\n");
		temp = *n;
		display(a, temp);
	}
	else
		printf("Invalid position.");
}

void main()
{
	int a[100], n, i, ch;
	printf("Enter the array size: ");
	scanf("%d", &n);
	printf("Enter the array elements: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (;;)
	{
		printf("1.Insert 2.Delete 3.Display:  ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insert(a, &n);
			break;
		case 2:
			delete (a, &n);
			break;
		case 3:
			display(a, n);
			break;
		default:
		{
			printf("Invalid Input. Terminating...\n");
			exit(0);
		}
		}
	}
}
