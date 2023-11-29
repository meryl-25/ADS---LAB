#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void insert();
void inorder(struct node *root);
void search();
struct node *delete(struct node *root, int value);

struct node
{
	int data;
	struct node *left, *right;
} *root;

void main()
{
	int ch, value;
	clrscr();

	do
	{
		printf("\nSELECT\n 1.Insert\n 2.Delete\n 3.Search\n 4.Inorder\n 5.Exit\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			insert();
			continue;

		case 2:
			printf("Enter the value to be deleted\n");
			scanf("%d",&value);
			delete(root,value);
			continue;

		case 3:
			search();
			continue;
		
		case 4:
			printf("The inorder traversal is ");
			inorder(root);
			continue;

		default:
			exit(0);
		}

	} while (ch != 0);
}

void insert()
{
	struct node *curr, *prev, *newnode;
	int value;

	printf("Enter the node value\n");
	scanf("%d", &value);

	if (root == NULL)
	{

		root = malloc(sizeof(struct node));
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		printf("Node Inserted %d\n", value);
	}
	else
	{

		newnode = malloc(sizeof(struct node));
		newnode->data = value;
		newnode->left = NULL;
		newnode->right = NULL;

		curr = root;

		// find the last node  for insertion
		while (curr != NULL)
		{
			prev = curr;
			if (curr->data <= value)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}

		// check whether value greater than or less than last node
		if (prev->data <= value)
		{
			prev->right = newnode;
		}
		else
		{
			prev->left = newnode;
		}

		printf("Node Inserted %d\n", value);
	}
}

void inorder(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void search()
{
	struct node *curr;
	int value, flag = 0;

	printf("Enter the node to be searched\n");
	scanf("%d", &value);

	if (root == NULL)
	{

		printf("Tree Empty\n");
	}
	else
	{
		curr = root;
		while (curr != NULL)
		{
			if (curr->data == value)
			{
				printf("Node %d Found\n", value);
				flag = 1;
				return;
			}
			else if (curr->data < value)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}
		if (flag == 0)

			printf("Node not Found\n");
	}
}

struct node *delete(struct node *root, int value)
{
	struct node *curr;
	if (root == NULL)

		return 0;

	else if (value < root->data)

		root->left= delete (root->left,value);

	else if (value > root->data)

		root->right= delete (root->right,value);

	else
	{
		//delete node with one or zero child
		if(root->left==NULL)
		{
			curr=root->right;
			free(root);
			return curr;
		}
		else if(root->right==NULL)
		{
			curr=root->left;
			free(root);
			return curr;
		}
		else
		{
			//delete node with two child
			
			root->data=curr->data;

			root->right=delete(root->right,curr->data);

		}
	}
	return root;

}
