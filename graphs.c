#include <stdio.h>
#include <stdlib.h>
#define GRAPHSIZE 15
#define SIZE 15

int adjacenyMatrix[GRAPHSIZE][GRAPHSIZE] = {0};
int visited[GRAPHSIZE]= {0};

void initAdjacencyMatrix(int n)
{
	printf("\nInitializing adjacency Matrix:\n\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			int bol=0;
			printf("is %d connected to %d?(1/0):  ",i+1, j+1);
			scanf("%d",&bol);
			if(bol==1)
				adjacenyMatrix[i][j]=1;
		}
	}
}

void printAdjacencyMatrix(int n){
	printf("\n  ");
	for(int i=0; i<n; i++)
		printf("%3d  ",i+1);
	printf("\n\n");
	for(int i=0; i<n; i++){
		printf("%d ",i+1);
		for(int j=0; j<n; j++)
			printf("%3d  ",adjacenyMatrix[i][j]);
		printf("\n");
	}
}
int f, r, count;
int q[SIZE]; 
void enqueue(int item)
{
	r = (r + 1) % SIZE;
	q[r] = item;
	count++;
}
int dequeue()
{
	int preF = f;
	f = (f + 1) % SIZE;
	count--;
	return q[preF];
}
void BFS(int v, int n)
{
	enqueue(v);
	visited[v]=1;
	do{
		v = dequeue();
		printf("%d  ", v + 1);
		for(int i=0;i<n;i++)
			if(adjacenyMatrix[v][i] && !visited[i] ){
				enqueue(i);
				visited[i]=1;
			}
	}while(count>0);
}

void DFS(int v, int n)
{
	printf("%d  ",v+1);
	visited[v] = 1;
	
	for (int i = 0; i < n; i++)
		if (adjacenyMatrix[v][i] && !visited[i] )
			DFS(i,n);
}

void clearVisited()
{
	for(int i=0;i<GRAPHSIZE;i++)
		visited[i]=0;
}

int main()
{
	printf("Enter number of nodes:  ");
	int n,ch,v;
	scanf("%d", &n);
	initAdjacencyMatrix(n);
	printAdjacencyMatrix(n);
	while(1)
	{
		printf("\n1.BFS   2.DFS\n");
		scanf("%d",&ch);
		printf("Enter starting vertex:  ");
		scanf("%d",&v);
		switch (ch)
		{
		case 1:
			f = 0, r = -1, count = 0;
			clearVisited();
			BFS(--v, n);
			printf("\n\n");
			break;
		case 2:	DFS(--v,n);
			clearVisited();
			printf("\n\n");
			break;
		default: return 0;
		}
	}
}
//test case
// 6 1 1 2 2 2 1 2 1 1 2 1 2 1 2 2 2 1 1 1 1 2 1 2 1 1 2 2 2 1 1 
