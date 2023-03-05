#include <stdio.h>
#include <stdlib.h>
struct BST
{
    int info;
    struct BST *lptr, *rptr;
};
typedef struct BST node;

node *generateTree(node *root, int data)
{
    node *new1 = malloc(sizeof(node));
    new1->lptr = new1->rptr = NULL;
    new1->info = data;
    if (!root)
    {
        root = new1;
        return root;
    }
    node *pathFinder = root, *temp;
    while (pathFinder)
    {
        temp = pathFinder;
        if (data >= pathFinder->info)
            pathFinder = pathFinder->rptr;
        else // if(data<pathFinder->info)
            pathFinder = pathFinder->lptr;
    }

    if (data >= temp->info)
        temp->rptr = new1;
    if (data < temp->info)
        temp->lptr = new1;
    return root;
}
void inorderDisplay(node *root)
{
    if (root!=NULL)
    {
        inorderDisplay(root->lptr);
        printf("%d  ", root->info);
        inorderDisplay(root->rptr);
    }
}

void preorderDisplay(node *root)
{
    if(root!=NULL)
    {
        printf("%d  ",root->info);
        preorderDisplay(root->lptr);
        preorderDisplay(root->rptr);
    }
}

void postorderDisplay(node* root)
{
    if(root!=NULL)
    {
        postorderDisplay(root->lptr);
        postorderDisplay(root->rptr);
        printf("%d  ", root->info);
    }
}
node *IOSfinder(node *root)
{
    while (root->lptr)
        root = root->lptr;
    return root;
}

node *delete(node *root, int key)
{
    if (!root)//root==NULL
    {
        printf("tree empty\n");
        return NULL;
    }
    if (key > root->info)
        root->rptr = delete (root->rptr, key);
    else if (key < root->info)
        root->lptr = delete (root->lptr, key);
    else // if (key==root->info)
    {
        // left child
        if (!root->rptr)
        {
            node *temp = root->lptr;
            free(root);
            return temp;
        }
        // right child
        if (!root->lptr)
        {
            node *temp = root->rptr;
            free(root);
            return temp;
        }
        // general
        node *IOS = IOSfinder(root->rptr);
        root->info = IOS->info;
        root->rptr = delete(root->rptr, IOS->info);
    }
    return root;
}

void search(node* root, int key)
{
    while(root!=NULL)
    {
        if(root->info==key)
        {
            printf("found\n");
            return;
        }
        if(key>root->info)
            root=root->rptr;
        else
            root=root->lptr;
    }
    printf("not found\n");
}

void main()
{
    node *root = NULL;
    int data[] = {40, 20, 50, 10, 30, 45, 65};
    for (int i = 0; i < 7; i++)
        root = generateTree(root, data[i]);
    inorderDisplay(root);
    printf("\n");
   for(;;)
   {
	    printf("Enter ele to be deleted:  ");
	    int key;
	    scanf("%d", &key);
	    root = delete (root, key);
	    inorderDisplay(root);
	    printf("\n");
    }
}
