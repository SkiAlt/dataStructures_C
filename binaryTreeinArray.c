#include <stdio.h>
#include <stdlib.h>
#define SIZE 420

void insert(int a[], int ele)
{
	int i = 0;
	while (a[i])
	{
		if (ele < a[i])
			i = 2 * i + 1;
		else
			i = 2 * i + 2;
	}
	a[i] = ele;
}

void inorder(int a[], int i)
{
	if (a[i])
	{
		inorder(a, 2 * i + 1);
		printf("%d  ", a[i]);
		inorder(a, 2 * i + 2);
	}
}

void preorder(int a[], int i)
{
	if (a[i])
	{
		printf("%d  ", a[i]);
		preorder(a, 2 * i + 1);
		preorder(a, 2 * i + 2);
	}
}

void postorder(int a[], int i)
{
	if (a[i])
	{
		postorder(a, 2 * i + 1);
		postorder(a, 2 * i + 2);
		printf("%d  ", a[i]);
	}
}

int main()
{
	int n, a[SIZE] = {0}, ch, i, ele;
	printf("Enter Number of tree elements:  ");
	scanf("%d", &n);
	printf("Enter Tree elements:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ele);
		insert(a, ele);
	}
	printf("\nTraversal:\n");
	while (1)
	{
		printf("\n1.inorder  2.preorder  3.postorder:\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			inorder(a, 0);
			break;
		case 2:
			preorder(a, 0);
			break;
		case 3:
			postorder(a, 0);
			break;
		default:
			return 0;
		}
	}
}
