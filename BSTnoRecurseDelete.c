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
        if (root != NULL)
        {
                inorderDisplay(root->lptr);
                printf("%d  ", root->info);
                inorderDisplay(root->rptr);
        }
}

node *delete(node *root, int key)
{
        // 1. locate node to be deleted
        node *deleteNode = root, *prevtoDelete = root;
        while (deleteNode)
        {
                if (deleteNode->info == key)
                        break;
                prevtoDelete = deleteNode;
                if (key > deleteNode->info)
                        deleteNode = deleteNode->rptr;
                else
                        deleteNode = deleteNode->lptr;
        }
        if (!deleteNode)
        {
                printf("Key element not found\n");
                return root;
        }
NUKE: // label.
        // if (partial) leaf
        if (!deleteNode->rptr) // only left sub tree exists
        {
                node *childBackup = deleteNode->lptr;
                if (prevtoDelete->rptr == deleteNode)
                        prevtoDelete->rptr = childBackup;
                else
                        prevtoDelete->lptr = childBackup;
                free(deleteNode);
                if (deleteNode == root)
                        return childBackup;
                else
                        return root;
        }
        if (!deleteNode->lptr) // only right sub tree exists
        {
                node *childBackup = deleteNode->rptr;
                if (prevtoDelete->rptr == deleteNode)
                        prevtoDelete->rptr = childBackup;
                else
                        prevtoDelete->lptr = childBackup;
                if (deleteNode == root)
                        return childBackup;
                else
                        return root;
        }

        // general case. IOS stands for Inorder Successor
        node *IOS;
        IOS = deleteNode->rptr;
        while (IOS->lptr)
        {
                prevtoDelete = IOS;
                IOS = IOS->lptr;
        }
        deleteNode->info = IOS->info;
        deleteNode = IOS;
        goto NUKE;
}

void main()
{
        node *root = NULL;
        int data[] = {40, 20, 50, 10, 30, 45, 47};
        for (int i = 0; i < (sizeof(data) / sizeof(int)); i++)
                root = generateTree(root, data[i]);
        inorderDisplay(root);
        printf("\n");
        for (;;)
        {
                printf("Enter ele to be deleted:  ");
                int key;
                scanf("%d", &key);
                root = delete (root, key);
                inorderDisplay(root);
                printf("\n");
        }
}
