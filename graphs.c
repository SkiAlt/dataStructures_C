#include <stdio.h>
#include <stdlib.h>
#define GRAPHSIZE 15

int adjacenyMatrix[GRAPHSIZE][GRAPHSIZE] = {0};

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

int main()
{
    printf("Enter number of nodes:  ");
    int n;
    scanf("%d", &n);
    initAdjacencyMatrix(n);
    printAdjacencyMatrix(n);
    return 0;
}
