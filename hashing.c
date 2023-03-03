/*Design and develop a program in C that uses Hash Function H:K->L as H(K)=K mod m
and implement hashing technique to map a given key K to the address space L. Resolve
the collision (if any) using linear probing.*/
#include <stdio.h>
#include <stdlib.h>
#define MAXTABLESIZE 69

void H(int k, int a[], int m){
	int l = k % m;
	if(a[l]==-1){ //no collision
		a[l] = k;
		printf("inserted key: %d at address: %d\n", k, l);
		return;
	}	
	printf("Collision occured at address: %d\n", l);
	while(a[l]!=-1)
		l = (l + 1) % m;
	a[l] = k;
	printf("inserted key: %d at address: %d\n", k, l);
}

void displayHashTable(int a[],int m){
	printf("\n\nHashTable:\n\n");
	printf("%10s%10s\n","Address:","Keys:");
	for(int l=0; l<m; l++)
		printf("%10d%10d\n",l,a[l]);
}

void main(){
	int m, n, k, hashTable[MAXTABLESIZE];
	//initializing hashTable
	for(int i = 0; i < MAXTABLESIZE; i++)
		hashTable[i] = -1;
		
	printf("Enter HashTable size: ");
	scanf("%d",&m);
	printf("Number of keys: ");
	scanf("%d",&n);
	printf("Enter the keys:\n");
	while(n--){
		scanf("%d",&k);
		H(k,hashTable,m);
	}
	displayHashTable(hashTable,m);
}
//	printf("\n");
//	test case
//	10  8  72 27 36 24 63 81 92 101


